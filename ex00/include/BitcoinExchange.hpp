/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 21:27:31 by akostian          #+#    #+#             */
/*   Updated: 2025/08/12 11:27:23 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#define DB_PATH "data/data.csv"

#include <limits.h>  //INT_MAX
#include <stdlib.h>  //atoi() atof()

#include <fstream>
#include <iostream>
#include <map>

int parseDB(std::map<tm, double> &data);

int processFile(std::map<tm, double> &data, std::ifstream &file);

std::ostream &operator<<(std::ostream &os, tm tm);

#endif  // BITCOINEXCHANGE_HPP
