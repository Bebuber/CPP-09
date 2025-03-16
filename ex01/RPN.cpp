/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 00:55:09 by bebuber           #+#    #+#             */
/*   Updated: 2025/03/16 02:35:22 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(const std::string& input) {
	parseInputString(input);
}

RPN::RPN(const RPN& other) : numbers(other.numbers) {}

RPN& RPN::operator=(const RPN& other) {
	if (this != &other) {
		this->numbers = other.numbers;
	}
	
	return *this;
}

void RPN::parseInputString(const std::string& input) {
	for(int i = 0; input[i]; i++) {
		if (isdigit(input[i])) {
			numbers.push(input[i] - '0');
		} else if (isspace(input[i])) {
			continue;
		} else if (strchr("+-*/", input[i])) {
			calculate(input[i]);
		} else {
			throw std::invalid_argument("invalid argument.");
		}
	}
	
	if (numbers.size() == 1) {
		std::cout << numbers.top() << std::endl;
	} else {
		throw std::invalid_argument("not enough operators.");
	}
}

void RPN::calculate(char x) {
	if (numbers.size() >= 2) {
		double b = numbers.top();
		numbers.pop();
		double a = numbers.top();
		numbers.pop();
		
		double result;
		
		switch (x) {
			case '+':
				result = a + b;
				break;
			case '-':
				result = a - b;
				break;
			case '/':
				if (b == 0) {
					throw std::runtime_error("division by zero.");
				}
				result = a / b;
				break;
			case '*':
				result = a * b;
				break;
			default:
				throw std::runtime_error("invalid operator");
		}
		
		numbers.push(result);
	} else {
		throw std::runtime_error("not enough operands.");
	}
}
