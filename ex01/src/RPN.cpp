/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 23:09:45 by akostian          #+#    #+#             */
/*   Updated: 2025/08/10 23:39:58 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

#include "../include/colors.hpp"

int checkNumber(const std::string& input, std::string::iterator it) {
	if (!std::strchr(ALLOWED_CHARS, *it)) {
		std::cerr << colors::red_bbold << "Error: Character \'" << *it
		          << "\' not allowed" << colors::reset << "\n";
		return 1;
	}
	if (it != input.begin() && std::strchr(ALLOWED_CHARS, *(it - 1))) {
		std::cerr << colors::red_bbold
		          << "Error: Operands must be separated by ' '" << colors::reset
		          << "\n";
		return 1;
	}
	return 0;
}

int solve(std::string input, double& result) {
	std::stack<double> data;

	for (std::string::iterator it = input.begin(); it != input.end(); it++) {
		if (std::isspace(*it)) continue;

		if (checkNumber(input, it)) return 1;

		if (*it >= '0' && *it <= '9') {
			data.push(*it - '0');
			continue;
		}

		if (data.size() < 2) {
			std::cerr << colors::red_bbold
			          << "Error: Not enough operands for operation"
			          << colors::reset << "\n";
			return 1;
		}

		double operand2 = data.top();
		data.pop();
		switch (*it) {
			case '+':
				data.top() = data.top() + operand2;
				break;
			case '-':
				data.top() = data.top() - operand2;
				break;
			case '*':
				data.top() = data.top() * operand2;
				break;
			case '/':
				if (operand2 == 0) {
					std::cerr << colors::red_bbold << "Error: Zero division"
					          << colors::reset << "\n";
					return 1;
				}
				data.top() = data.top() / operand2;
				break;
		}
	}

	if (data.size() > 1) {
		std::cerr << colors::red_bbold
		          << "Error: Not enough operations for operands"
		          << colors::reset << "\n";
		return 1;
	}

	if (!data.size()) {
		std::cerr << colors::red_bbold << "Error: No operands provided"
		          << colors::reset << "\n";
		return 1;
	}

	result = data.top();

	return 0;
}
