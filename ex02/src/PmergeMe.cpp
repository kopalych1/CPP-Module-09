/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 23:26:57 by akostian          #+#    #+#             */
/*   Updated: 2025/08/09 22:39:59 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

void insertionSort(std::vector<unsigned int> &elems, std::size_t begin,
                   std::size_t end, bool ascending) {
	for (std::size_t i = begin; i != end; i++) {
		for (std::size_t j = i + 1; j != end; j++) {
			if ((ascending ? elems[i] < elems[j] : elems[i] > elems[j]))
				continue;
			unsigned int tmp = elems[i];
			elems[i] = elems[j];
			elems[j] = tmp;
		}
	}
}

void insertionSort(std::deque<unsigned int> &elems, std::size_t begin,
                   std::size_t end, bool ascending) {
	for (std::size_t i = begin; i != end; i++) {
		for (std::size_t j = i + 1; j != end; j++) {
			if ((ascending ? elems[i] < elems[j] : elems[i] > elems[j]))
				continue;
			unsigned int tmp = elems[i];
			elems[i] = elems[j];
			elems[j] = tmp;
		}
	}
}

void insertionSort(std::vector<unsigned int> &elems) {
	insertionSort(elems, 0, elems.size());
}

void insertionSort(std::deque<unsigned int> &elems) {
	insertionSort(elems, 0, elems.size());
}

void mergeInsertSort(std::vector<unsigned int> &elems, std::size_t begin,
                     std::size_t end, unsigned int threshold) {
	std::size_t part_length = end - begin;

	if (begin > end) return;

	if (part_length <= threshold) {
		if (part_length > 1) insertionSort(elems);
		return;
	}

	std::size_t mid = begin + static_cast<std::size_t>(part_length / 2);

	std::vector<unsigned int> left(elems.begin() + begin, elems.begin() + mid);
	std::vector<unsigned int> right(elems.begin() + mid, elems.begin() + end);

	mergeInsertSort(left, 0, left.size(), threshold);
	mergeInsertSort(right, 0, right.size(), threshold);

	std::size_t li = 0;
	std::size_t ri = 0;
	for (std::size_t i = 0; i < part_length; i++) {
		if (li == left.size())
			elems[i] = right[ri++];
		else if (ri == right.size())
			elems[i] = left[li++];

		else if (left[li] < right[ri])
			elems[i] = left[li++];
		else
			elems[i] = right[ri++];
	}
}
void mergeInsertSort(std::deque<unsigned int> &elems, std::size_t begin,
                     std::size_t end, unsigned int threshold) {
	std::size_t part_length = end - begin;

	if (begin > end) return;

	if (part_length <= threshold) {
		if (part_length > 1) insertionSort(elems);
		return;
	}

	std::size_t mid = begin + static_cast<std::size_t>(part_length / 2);

	std::vector<unsigned int> left(elems.begin() + begin, elems.begin() + mid);
	std::vector<unsigned int> right(elems.begin() + mid, elems.begin() + end);

	mergeInsertSort(left, 0, left.size(), threshold);
	mergeInsertSort(right, 0, right.size(), threshold);

	std::size_t li = 0;
	std::size_t ri = 0;
	for (std::size_t i = 0; i < part_length; i++) {
		if (li == left.size())
			elems[i] = right[ri++];
		else if (ri == right.size())
			elems[i] = left[li++];

		else if (left[li] < right[ri])
			elems[i] = left[li++];
		else
			elems[i] = right[ri++];
	}
}

void mergeInsertSort(std::vector<unsigned int> &elems) {
	mergeInsertSort(elems, 0, elems.size());
}

void mergeInsertSort(std::deque<unsigned int> &elems) {
	mergeInsertSort(elems, 0, elems.size());
}
