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

class PmergeMe
{
private:
	std::vector<int>	_vectorData;
	std::deque<int>		_dequeData;
	std::vector<int>	_originalData;
	double				_vectorTime;
	double				_dequeTime;

	// Private helper functions for vector
	void				mergeInsertSortVector(std::vector<int>& arr);
	void				insertionSortVector(std::vector<int>& arr, int left, int right);
	std::vector<int>	mergePairsVector(std::vector<std::pair<int, int> >& pairs);
	
	// Private helper functions for deque
	void				mergeInsertSortDeque(std::deque<int>& arr);
	void				insertionSortDeque(std::deque<int>& arr, int left, int right);
	std::deque<int>		mergePairsDeque(std::deque<std::pair<int, int> >& pairs);

	// Utility functions
	int					jacobsthal(int n);
	std::vector<int>	generateInsertionOrder(int n);
	double				getTimeInMicroseconds(struct timeval start, struct timeval end);
	void				validateInput(const std::string& str);

	// Copy prevention (Orthodox Canonical Form)
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
