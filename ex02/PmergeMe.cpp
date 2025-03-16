/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 22:01:47 by bebuber           #+#    #+#             */
/*   Updated: 2025/03/16 23:02:38 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int argc, const std::string& argv) {
	readInput(argc, argv);
}
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : vec(other.vec), deq(other.deq) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		this->vec = other.vec;
		this->deq = other.deq;
	}
	
	return (*this);
}


void PmergeMe::readInput(int argc, const std::string& argv) {
	for (int i = 1; i < argc; i++) {
		std::
	}
}