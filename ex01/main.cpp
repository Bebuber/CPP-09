/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 02:11:51 by bebuber           #+#    #+#             */
/*   Updated: 2025/03/16 02:21:06 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "usage: ./RPN \"operands_and_operators\" " << std::endl;
		return (1);
	}
	
	try {
		RPN math(argv[1]);
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}