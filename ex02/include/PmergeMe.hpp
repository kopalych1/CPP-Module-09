/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 23:27:37 by akostian          #+#    #+#             */
/*   Updated: 2025/08/10 05:25:40 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <iostream>
#include <vector>

#include "colors.hpp"

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &vector) {
	os << '[';
	T prev = vector[0];
	for (size_t i = 0; i < vector.size(); i++) {
		std::cout << (prev <= vector[i] ? colors::green : colors::red)
		          << vector[i] << colors::reset
		          << ((i + 1) != vector.size() ? ", " : "");
		prev = vector[i];
	}
	os << ']';
	return os;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::deque<T> &dq) {
	os << '[';
	T prev = dq[0];
	for (size_t i = 0; i < dq.size(); i++) {
		std::cout << (prev <= dq[i] ? colors::green : colors::red) << dq[i]
		          << colors::reset << ((i + 1) != dq.size() ? ", " : "");
		prev = dq[i];
	}
	os << ']';
	return os;
}

void insertionSort(std::vector<unsigned int> &elems, size_t begin, size_t end,
                   bool ascending = true);
void insertionSort(std::vector<unsigned int> &elems);
void insertionSort(std::deque<unsigned int> &elems, size_t begin, size_t end,
                   bool ascending = true);
void insertionSort(std::deque<unsigned int> &elems);

void mergeInsertSort(std::vector<unsigned int> &elems, size_t begin, size_t end,
                     unsigned int threshold = 2);
void mergeInsertSort(std::vector<unsigned int> &elems);
void mergeInsertSort(std::deque<unsigned int> &elems, size_t begin, size_t end,
                     unsigned int threshold = 2);
void mergeInsertSort(std::deque<unsigned int> &elems);

#endif  // PMERGEME_HPP
