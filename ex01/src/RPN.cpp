/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 23:09:45 by akostian          #+#    #+#             */
/*   Updated: 2025/07/22 23:25:43 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"
#include "../include/colors.hpp"

int	solve(std::string input, int &result)
{
	std::stack<double>	data;

	for (std::string::iterator	it = input.begin(); it != input.end(); it++)
	{
		if (std::isspace(*it))
			continue;

		if (!std::strchr(ALLOWED_CHARS, *it))
		{
			std::cerr << (COLORED ? RED : "") << "Error: Character not allowed" << (COLORED ? CRESET : "") << "\n";
			return 1;
		}
		
		if (it != input.begin() && std::strchr(ALLOWED_CHARS, *(it - 1)))
		{
			std::cerr << (COLORED ? RED : "") << "Error: Operands must be separated by ' '" << (COLORED ? CRESET : "") << "\n";
			return 1;
		}

		if (*it >= '0' && *it <= '9')
		{
			data.push(*it - '0');
			continue;
		}

		if (data.size() < 2)
		{
			std::cerr << (COLORED ? RED : "") << "Error: Not enough operands for operation" << (COLORED ? CRESET : "") << "\n";
			return 1;
		}

		double	operand2 = data.top();
		data.pop();
		switch (*it)
		{
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
				if (operand2 == 0)
				{
					std::cerr << (COLORED ? RED : "") << "Error: Zero division" << (COLORED ? CRESET : "") << "\n";
					return 1;
				}
				data.top() = data.top() / operand2;
				break;
		}
	}

	if (data.size() > 1)
	{
		std::cerr << (COLORED ? RED : "") << "Error: Not enough operations for operands" << (COLORED ? CRESET : "") << "\n";
		return 1;
	}
	
	if (!data.size())
	{
		std::cerr << (COLORED ? RED : "") << "Error: No operands provided" << (COLORED ? CRESET : "") << "\n";
		return 1;
	}

	result = data.top();

	return 0;
}

std::ostream& operator<<(std::ostream& os, std::stack<double> stack) {
	os << '[';
	while (!stack.empty())
	{
		std::cout << stack.top() << (stack.size() != 1 ? ", " : "");
		stack.pop();
	}
	os << ']';
	return os;
}
