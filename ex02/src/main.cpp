/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 21:26:49 by akostian          #+#    #+#             */
/*   Updated: 2025/08/09 22:37:00 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>  // to find element in vector
#include <iostream>
#include <limits>  // limits for parser

#include "../include/PmergeMe.hpp"
#include "../include/colors.hpp"

bool isValidInteger(const std::string& s) {
	if (s.empty()) return false;

	std::size_t i = 0;

	if (s[0] == '-' || s[0] == '+') {
		if (s.size() == 1) return false;
		i = 1;
	}

	for (; i < s.size(); ++i) {
		if (!std::isdigit(s[i])) return false;
	}
	return true;
}

double getTimeMicroseconds() {
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	return static_cast<double>(ts.tv_sec) * 1e6 +
	       static_cast<double>(ts.tv_nsec) / 1e3;
}

int main(int argc, char** argv) {
	if (argc == 1) {
		std::cout << "Usage: ./PmergeMe " << colors::yellow << "<numbers>"
		          << colors::reset << "\n";
		return 0;
	}

	std::vector<unsigned int> vec;
	std::deque<unsigned int> dq;

	for (int i = 1; i < argc; i++) {
		std::string arg(argv[i]);

		if (!isValidInteger(arg)) {
			std::cerr << colors::red_bbold << "Value \'" << arg
			          << "\' must be changed" << colors::reset << "\n";
			return 1;
		}

		long num(std::atol(arg.c_str()));

		if (num < 0) {
			std::cerr << colors::red_bbold << "Value \'" << arg
			          << "\' is negative" << colors::reset << "\n";
			return 1;
		}
		if (num > std::numeric_limits<int>::max()) {
			std::cerr << colors::red_bbold << "Value is too large"
			          << colors::reset << "\n";
			return 1;
		}
		if (std::find(vec.begin(), vec.end(), num) != vec.end()) {
			std::cerr << colors::red_bbold << "Values contain duplicates"
			          << colors::reset << "\n";
			return 1;
		}

		vec.push_back(num);
		dq.push_back(num);
	}

	std::cout << "Before:\t" << vec << '\n';

	double start = getTimeMicroseconds();
	mergeInsertSort(vec);
	double vec_time_us = getTimeMicroseconds() - start;

	start = getTimeMicroseconds();
	mergeInsertSort(dq);
	double dq_time_us = getTimeMicroseconds() - start;

	std::cout << "After:\t" << vec << '\n';

	std::cout << "Time to process a range of " << colors::magenta << vec.size()
	          << colors::reset << " elements with std::vector  :\t"
	          << colors::cyan << vec_time_us << colors::reset << "us" << '\n';

	std::cout << "Time to process a range of " << colors::magenta << dq.size()
	          << colors::reset << " elements with std::deque  :\t"
	          << colors::cyan << dq_time_us << colors::reset << "us" << '\n';
}
