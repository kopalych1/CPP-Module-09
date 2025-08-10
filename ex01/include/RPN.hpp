/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 23:09:52 by akostian          #+#    #+#             */
/*   Updated: 2025/08/10 23:40:54 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <cstring>
#include <iostream>
#include <stack>

#define ALLOWED_CHARS \
	"+-*/"            \
	"0123456789"

template <typename T>
std::ostream& operator<<(std::ostream& os, std::stack<T> stack) {
	os << '[';
	while (!stack.empty()) {
		std::cout << stack.top() << (stack.size() != 1 ? ", " : "");
		stack.pop();
	}
	os << ']';
	return os;
}

int solve(std::string input, double& result);

#endif  // RPN_HPP
