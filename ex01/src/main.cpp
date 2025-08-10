/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 21:26:49 by akostian          #+#    #+#             */
/*   Updated: 2025/08/10 23:28:50 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "../include/RPN.hpp"
#include "../include/colors.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << colors::red_bbold << "Error: Invalid number of arguments"
		          << colors::reset << "\n";
		std::cerr << "Usage: ./RPN " << colors::yellow << "<input>"
		          << colors::reset << "\n";
		return 1;
	}

	std::string input(argv[1]);
	double result;

	if (solve(input, result)) return 1;

	std::cout << result << "\n";
}
