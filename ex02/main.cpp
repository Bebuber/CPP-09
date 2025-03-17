/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 21:44:32 by bebuber           #+#    #+#             */
/*   Updated: 2025/03/17 02:54:53 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char* argv[]) {
	PmergeMe sorter(argc, argv);

	sorter.displayVector();
	
	sorter.sortVector();
	std::cout << "----------------------------------\n";
	sorter.displayVector();
	// rest of the implementation
	return (0);
}