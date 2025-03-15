/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:46:26 by bebuber           #+#    #+#             */
/*   Updated: 2025/03/15 15:21:13 by bebuber          ###   ########.fr       */
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
	}
	
}