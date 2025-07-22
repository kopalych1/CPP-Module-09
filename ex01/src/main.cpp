/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 21:26:49 by akostian          #+#    #+#             */
/*   Updated: 2025/07/22 23:23:36 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "../include/colors.hpp"
#include "../include/RPN.hpp"

typedef std::string str;

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << (COLORED ? RED : "") << "Error: Invalid number of arguments" << (COLORED ? CRESET : "") << "\n";
		std::cerr << "Usage: ./RPN " << (COLORED ? YEL : "") << "<input>" <<  (COLORED ? CRESET : "") << "\n";
		return 1;
	}

	str	input(argv[1]);
	int	result;
	
	if (solve(input, result))
		return 1;

	std::cout << result << "\n";
}
