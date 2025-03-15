/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:46:23 by bebuber           #+#    #+#             */
/*   Updated: 2025/03/16 00:20:44 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <fstream>
#include <exception>
#include <iostream>
#include <sstream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"
class BitcoinExchange {
	public:
		BitcoinExchange() {};
		BitcoinExchange(const std::string& filename);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange() {};
		
		double getValueOnDate(const std::string& date) const;
		void processInputFile(const std::string& inputFilename);
	private:
		void loadData(const std::string& filename);
		bool isValidDate(const std::string& date);
		bool isValidQuantity(const std::string& quantityStr, double& quantity);
		std::map<std::string, double> data;
};

#endif