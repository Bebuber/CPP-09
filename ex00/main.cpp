/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:46:15 by bebuber           #+#    #+#             */
/*   Updated: 2025/03/15 14:55:15 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
	try {
		if (argc != 2) {
			throw std::runtime_error("usage: ./btc <input_file>");
		}
		BitcoinEchange exchange("data.csv");
		exchange.processInputFile(argv[1]);
	} catch (const std::exeption& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}