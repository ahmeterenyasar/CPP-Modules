/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:19:54 by ayasar            #+#    #+#             */
/*   Updated: 2025/11/13 17:33:42 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

# include <vector>
# include <deque>
# include <string>
# include <iostream>
# include <sstream>
# include <ctime>
# include <sys/time.h>
# include <algorithm>
# include <stdexcept>
# include <cctype>
# include <climits>

class PmergeMe
{
private:
	std::vector<int>	_vectorData;
	std::deque<int>		_dequeData;
	std::vector<int>	_originalData;
	double				_vectorTime;
	double				_dequeTime;

	void				validateInput(const std::string& str);
	bool				isValidNumber(const std::string& str) const;
	bool				isInIntRange(const std::string& str) const;
	bool				hasOnlyDigits(const std::string& str, size_t start) const;

	void				mergeInsertSortVector(std::vector<int>& arr);
	void				insertionSortVector(std::vector<int>& arr, int left, int right);
	std::vector<int>	mergePairsVector(std::vector<std::pair<int, int> >& pairs);
	void				createPairsVector(std::vector<int>& arr, std::vector<std::pair<int, int> >& pairs, int& straggler, bool& hasStraggler);
	void				insertStragglerVector(std::vector<int>& sorted, int straggler);
	
	void				mergeInsertSortDeque(std::deque<int>& arr);
	void				insertionSortDeque(std::deque<int>& arr, int left, int right);
	std::deque<int>		mergePairsDeque(std::deque<std::pair<int, int> >& pairs);
	void				createPairsDeque(std::deque<int>& arr, std::deque<std::pair<int, int> >& pairs, int& straggler, bool& hasStraggler);
	void				insertStragglerDeque(std::deque<int>& sorted, int straggler);

	int					jacobsthal(int n);
	std::vector<int>	generateInsertionOrder(int n);
	
	double				getTimeInMicroseconds(struct timeval start, struct timeval end);
	double				measureVectorSort();
	double				measureDequeSort();

	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);

public:
	PmergeMe();
	~PmergeMe();

	void	parseInput(int argc, char** argv);
	void	sort();
	void	displayResults() const;
};

#endif
