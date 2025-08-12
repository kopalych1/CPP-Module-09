/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 21:27:36 by akostian          #+#    #+#             */
/*   Updated: 2025/08/12 11:27:58 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

#include "../include/colors.hpp"

std::ostream &operator<<(std::ostream &os, tm tm) {
	const char separator = '/';
	const bool leading_zero = true;

	os << (leading_zero && tm.tm_mday < 10 ? "0" : "") << tm.tm_mday
	   << separator << (leading_zero && tm.tm_mon < 10 ? "0" : "") << tm.tm_mon
	   << separator << tm.tm_year;
	return os;
}

/**
 * @brief Comparison operator for tm structures (year, month, day only).
 */
bool operator<(const tm &lhs, const tm &rhs) {
	if (lhs.tm_year != rhs.tm_year) return lhs.tm_year < rhs.tm_year;
	if (lhs.tm_mon != rhs.tm_mon) return lhs.tm_mon < rhs.tm_mon;
	if (lhs.tm_mday != rhs.tm_mday) return lhs.tm_mday < rhs.tm_mday;
	return false;
}

/**
 * @brief Checks if a C-string contains only digit characters.
 * @param s Input C-string.
 * @return true if all characters are digits, false otherwise.
 */
bool isdigit(const char *s) {
	for (; *s; s++)
		if (*s < '0' || *s > '9') return 0;
	return 1;
}

int parseDB(std::map<tm, double> &data) {
	std::ifstream DB_file(DB_PATH);
	if (!DB_file.is_open()) {
		std::cerr << colors::red_bbold << "Error: Could not open DB file \""
		          << DB_PATH << "\"" << colors::reset << "\n";
		return 1;
	}

	std::string line;
	tm date = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	getline(DB_file, line);  // Skipping CSV row

	while (getline(DB_file, line)) {
		date.tm_year = std::atoi(line.substr(0, 4).c_str());
		date.tm_mon = std::atoi(line.substr(5, 2).c_str());
		date.tm_mday = std::atoi(line.substr(8, 2).c_str());

		data[date] = atof(line.substr(line.find(',') + 1).c_str());
	}

	return 0;
}

static int printInputError(const std::string &line) {
	std::cout << colors::red_bbold << "Error: Bad input: \"" << line << '\"'
	          << colors::reset << '\n';
	return 1;
}

/**
 * @brief Parses a line with date and value, filling tm and value.
 * @param line Input line to parse.
 * @param date Reference to tm structure to fill.
 * @param val Reference to double value to fill.
 * @return 0 on success, 1 on error.
 */
static int parseLine(std::string line, tm &date, double &val) {
	std::size_t dash_pos = line.find('-');
	if (dash_pos == std::string::npos) return printInputError(line);

	std::string year_str = line.substr(0, dash_pos);
	line = line.substr(dash_pos + 1);

	dash_pos = line.find('-');
	if (dash_pos == std::string::npos) return printInputError(line);

	std::string month_str = line.substr(0, dash_pos);
	std::string day_str = line.substr(dash_pos + 1, 2);

	if (!isdigit(year_str.c_str()) || !isdigit(month_str.c_str()) ||
	    !isdigit(day_str.c_str()))
		return printInputError(line);

	std::size_t bar_pos = line.find('|');
	if (bar_pos == std::string::npos) return printInputError(line);

	val = std::atof(line.substr(bar_pos + 1).c_str());
	if (!val && (line.substr(bar_pos + 1).find('0') == std::string::npos))
		return printInputError(line);

	date.tm_year = std::atoi(year_str.c_str());
	date.tm_mon = std::atoi(month_str.c_str());
	date.tm_mday = std::atoi(day_str.c_str());

	return 0;
}

int processFile(std::map<tm, double> &data, std::ifstream &file) {
	std::string line;
	tm date = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	double val = 0;

	while (getline(file, line)) {
		if (line == "date | value") continue;

		if (parseLine(line, date, val)) continue;

		if (val >= INT_MAX) {
			std::cout << colors::red_bbold << "Error: Number is too big"
			          << colors::reset << '\n';
			continue;
		}
		if (val < 0) {
			std::cout << colors::red_bbold << "Error: Number is not positive"
			          << colors::reset << '\n';
			continue;
		}

		if ((date.tm_year < 2009) ||
		    (date.tm_year == 2009 && date.tm_mon == 1 && date.tm_mday == 1)) {
			std::cout << colors::red_bbold
			          << "Error: No data before Jan 2nd 2009" << colors::reset
			          << '\n';
			continue;
		}
		if (date.tm_mon > 12 || date.tm_mday > 31) {
			std::cout << colors::red_bbold << "Error: Date is incorrect: \'"
			          << date << '\'' << colors::reset << '\n';
			continue;
		}

		std::map<tm, double>::iterator ri = (data.upper_bound(date));
		ri--;

		std::cout << colors::cyan << date << colors::reset << " => "
		          << colors::magenta << val << colors::reset << " = "
		          << colors::green_bbold << ri->second * val << colors::reset
		          << '\n';
	}
	return 0;
}
