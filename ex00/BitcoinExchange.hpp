/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:46:23 by bebuber           #+#    #+#             */
/*   Updated: 2025/03/15 17:12:00 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <fstream>
#include <exeption>

class BitcoinEchange {
	public:
		BitcoinEchange() {};
		BitcoinEchange(const std::string& filename);
		BitcoinEchange(const BitcoinEchange& other);
		BitcoinEchange& operator=(const BitcoinEchange& other);
		~BitcoinEchange() {};
		
		double getValueOnDate(const std::string& date) const;
		void processInputFile(const std::string& inputFilename);
	private:
		void loadData(const std::string& filename);
		bool isValidDate(const std::string& date);
		bool isValidQuantity(const std::string& quantityStr, double quantity);
		std::map<std::string, double> data;
}

#endif