/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:46:23 by bebuber           #+#    #+#             */
/*   Updated: 2025/03/15 15:01:44 by bebuber          ###   ########.fr       */
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
		
		void processInputFile(const std::string& inputFilename);
	private:
		void loadData(const std::string& filename);
		std::map<std::string, double> data;
}

#endif