/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 21:26:49 by akostian          #+#    #+#             */
/*   Updated: 2025/08/12 11:21:09 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"
#include "../include/colors.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << colors::red_bbold << "Error: Invalid number of arguments"
		          << colors::reset << "\n";
		std::cerr << "Usage: ./btc " << colors::yellow << "<input_file>"
		          << colors::reset << "\n";
		return 1;
	}

	std::ifstream input_file(argv[1]);
	if (!input_file.is_open()) {
		std::cerr << colors::red_bbold << "Error: Could not open file \""
		          << argv[1] << "\"" << colors::reset << "\n";
		return 1;
	}

	std::map<tm, double> data;

	if (parseDB(data)) return 1;

	if (processFile(data, input_file)) return 1;
}
