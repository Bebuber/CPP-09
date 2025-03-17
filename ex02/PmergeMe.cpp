/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 22:01:47 by bebuber           #+#    #+#             */
/*   Updated: 2025/03/17 02:54:28 by bebuber          ###   ########.fr       */
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

void PmergeMe::sortVector() {
	vec = mergeInsertion(vec);
}

std::vector<int> PmergeMe::mergeInsertion(std::vector<int> cont) {
	if (cont.size() <= 1) {
		return cont;
	}
	
	std::size_t half_size = cont.size() / 2;

	std::vector<int> left(cont.begin(), cont.begin() + half_size);
	std::vector<int> right(cont.begin() + half_size, cont.end());
	
	left = mergeInsertion(left);
	right = mergeInsertion(right);
	
	return merge(left, right);
}

std::vector<int> PmergeMe::merge(std::vector<int> left, std::vector<int> right) {
	std::vector<int> temp;
	
	auto itleft = left.begin();
	auto itright = right.begin();

	// std::cout << "test------4" << std::endl;

	while (itleft != left.end() || itright != right.end()) {
		// std::cout << "test------5" << std::endl;

		if (itright == right.end()) {
			temp.push_back(*itleft);
			itleft++;
		}else if (itleft == left.end()) {
			temp.push_back(*itright);
			itright++;
		} else if (*itleft < *itright) {
			// std::cout << "test------6" << std::endl;

			temp.push_back(*itleft);
			itleft++;
		} else if (*itright < *itleft) {
			// std::cout << "test------7" << std::endl;
			temp.push_back(*itright);
			itright++;
		}
	}
	// std::cout << "test------9" << *temp.begin() << std::endl;
	
	return temp;
}