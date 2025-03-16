/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 02:43:19 by bebuber           #+#    #+#             */
/*   Updated: 2025/03/16 23:03:31 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <iostream>
#include <exception>
#include <vector>
#include <deque>

class PmergeMe {
	public:
		PmergeMe();
		PmergeMe(int argc, const std::string& argv);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other); 
		~PmergeMe();
		
		void sortDeque(); //will do the sorting
		void sortVector(); //will do the sorting
	private:
		std::vector<int> vec;
		std::deque<int> deq;

		bool isDuplicate(int value);
		void readInput(int argc, const std::string& argv);
};

#endif