/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 22:01:47 by bebuber           #+#    #+#             */
/*   Updated: 2025/03/16 23:55:20 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int argc, char* input[]) {
	readInput(argc, input);
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

bool PmergeMe::isDuplicate(int num) {
	return (vec.end() != find(vec.begin(), vec.end(), num));
}

void PmergeMe::readInput(int argc, char* input[]) {
	for (int i = 1; i < argc; i++) {
		std::string arg = input[i];
		size_t pos;
		try {
			int num = std::stoi(arg, &pos);
			if (arg.size() != pos) {
				throw std::invalid_argument("Invalid input: not an integer");
			}

			if (isDuplicate(num)) {
				throw std::invalid_argument("Duplicate value: ");
			}
			deq.push_back(num);
			vec.push_back(num);
		} catch (const std::invalid_argument& e) {
			std::cerr << "Error: " << e.what() << " (" << arg << ")" << std::endl;
			exit(EXIT_FAILURE);
		}
	}
}

void PmergeMe::displayVector() {
	for (auto it = vec.begin(); it != vec.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

