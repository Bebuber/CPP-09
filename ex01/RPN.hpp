/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 00:39:29 by bebuber           #+#    #+#             */
/*   Updated: 2025/03/16 02:29:37 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <iostream>
#include <stack>
#include <exception>

class RPN {
	public:
		RPN() {};
		RPN(const std::string& input);
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN() {};

		void parseInputString(const std::string& input);
		void calculate(char x);
	private:
		std::stack<double> numbers;
};

#endif