/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 02:43:19 by bebuber           #+#    #+#             */
/*   Updated: 2025/03/17 01:11:00 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>
#include <deque>

class PmergeMe {
	public:
		PmergeMe();
		PmergeMe(int argc, char* input[]);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other); 
		~PmergeMe();
		
		void sortDeque(); //will do the sorting
		void sortVector(); //will do the sorting

		void displayVector();
	private:
		std::vector<int> vec;
		std::deque<int> deq;

		std::vector<int> merge(std::vector<int> left, std::vector<int> right);
		
		std::vector<int> mergeInsertion(std::vector<int> container);
		
		bool isDuplicate(int num);
		void readInput(int argc, char* input[]);
};

#endif