/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:46:26 by bebuber           #+#    #+#             */
/*   Updated: 2025/03/16 00:34:22 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : data(other.data) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		this->data = other.data;
	}
	return *this;
}

BitcoinExchange::BitcoinExchange(const std::string& filename) {
	loadData(filename);
}

void BitcoinExchange::loadData(const std::string& filename) {
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

double BitcoinExchange::getValueOnDate(const std::string& date) const {
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

bool BitcoinExchange::isValidDate(const std::string& date) {
	if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
		return false;
	}

	try {
		int month = std::stoi(date.substr(5, 2));
		int day = std::stoi(date.substr(8, 2));
		if (month < 1 || month > 12 || day < 1 || day > 31) {
			return false;
		}
	} catch (const std::exception&) {
		return false;
	}

	return true;	
}

bool BitcoinExchange::isValidQuantity(const std::string& quantityStr, double& quantity) {
	try {
		quantity = std::stod(quantityStr);
	} catch (const std::exception&) {
		return false;
	}

	if (quantity < 0 || quantity > 1000) {
		return false;
	}
	return true;
}

void BitcoinExchange::processInputFile(const std::string& inputFilename) {
	std::ifstream file(inputFilename);
	if (!file.is_open()) {
		throw std::runtime_error("Could not open input file.");
	}
	
	std::string line;
	std::getline(file, line);
	while(std::getline(file, line)) {
		std::istringstream ss(line);
		std::string date, quantityStr;
		double quantity = 0;
		
		if (std::getline(ss, date, '|') && std::getline(ss, quantityStr)) {
			date.erase(date.find_last_not_of(" \n\r\t") + 1);
			quantityStr.erase(quantityStr.find_first_of(" \n\r\t"), quantityStr.find_first_not_of(" \n\r\t"));
			
			if (!isValidDate(date)) {
				std::cerr << RED << "Error: invalid date format or date earlier than 2009-01-02 => " << date << GREEN << std::endl;
				continue;
			}
			
			if (!isValidQuantity(quantityStr, quantity)) {
				std::cerr << RED << "Error: value can not be less than 0 or more than 1000 => " << quantityStr << GREEN << std::endl;
				continue;
			}
			
			try {
				double value = getValueOnDate(date);
				std::cerr << GREEN << "On " << date << ", " << quantity << " BTC is worth " << (quantity * value) << std::endl;
			} catch (const std::exception& e) {
				std::cerr << RED << "Error: " << e.what() << GREEN << std::endl;
			}
		} else {
			std::cerr << RED << "Error: expected line format: <date> | <value>  => " << line << GREEN << std::endl;
		}
	}
	
}