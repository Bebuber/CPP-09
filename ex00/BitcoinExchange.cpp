/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:46:26 by bebuber           #+#    #+#             */
/*   Updated: 2025/03/15 18:09:28 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinEchange.hpp"

BitcoinEchange::BitcoinEchange(const BitcoinEchange& other) {}

BitcoinEchange& BitcoinEchange::operator=(const BitcoinExchange& other) {}

BitcoinEchange::BitcoinEchange(const std::string& filename) {
	loadData(filename);
}

void BitcoinEchange::loadData(const std::string& filename) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		throw std::runtime_error("Could not open data file.");
	}
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line)) {
		std::istringstream ss(line);
		std::string date;
		double value;
		if (std::getline(ss, date, ',') && ss >> value)
			data[date] = value;
	}
}

double getValueOnDate(const std::string& date) const {
	auto it = data.find(date);
	if (it != data.end()) {
		return it->second;
	} else {
		it = data.lower_bound(date);
		if (it == data.begin()) {
			throw std::runtime_error("No earlier date available");
		}
		it--;
		return it->second;
	}
}

bool BitcoinEchange::isValidDate(const std::string& date) {
	if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
		return false;
	}

	try {
		int year = std::stoi(date.substr(0, 4));
		int month = std::stoi(date.substr(5, 2));
		int day = std::stoi(date.substr(8, 2));
	} catch (const std::exeption&) {
		return false;
	}

	if (month < 1 || month > 12 || day < 1 || day > 31) {
		return false;
	}
	
	// if (year < 2009 || (year == 2009 && month == 1 && day < 2)) {
	// 	return false;
	// }
	return true;	
}

bool BitcoinEchange::isValidQuantity(const std::string& quantityStr, double quantity) {
	try {
		quantity = std::stod(quantityStr);
	} catch (const std::exeption&) {
		return false;
	}
	
	if (quantity < 0 || quantity > 1000) {
		return false;
	}
	
	retrun true;
}

void BitcoinEchange::processInputFile(const std::string& inputFilename) {
	std::ifstream file(inputFilename);
	if (!file.is_open()) {
		throw std::runtime_error("Could not open input file.");
	}
	
	std::string line;
	std::getline(file, line);
	while(std::getline(file, line)) {
		std::istringstream ss(line);
		std::string date, quantityStr;
		double quantity;
		
		if (std::getline(ss, date, '|') && std::getline(ss, quantityStr)) {
			date.erase(date.find_last_not_of(" \n\r\t") + 1);
			quantityStr.erase(quantityStr.find_first_not_of(" \n\r\t"));

			if (!isValidDate(date)) {
				std::cerr << "Error: invalid date format or date earlier than 2009-01-02 => " << date << std::endl;
				continue;
			}
			
			if (!isValidQuantity(quantityStr, quantity)) {
				std::cerr << "Error: value can not be less than 0 or more than 1000 => " << quantity << std::endl;
				continue;
			}
			
			try {
				double value = getValueOnDate(date);
				std::cerr << "On " << date << ", " << quantity << "BTC is worth " << (quantity * value) << std::endl;
			} catch (const std::exeption& e) {
				std::err << "Error: " << e.what() << std::endl;
			}
		} else {
			std::cerr << "Invalid line format: " << line << std::endl;
		}
	}
	
}