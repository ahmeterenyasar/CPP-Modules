/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:19:48 by ayasar            #+#    #+#             */
/*   Updated: 2025/11/13 18:05:10 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _vectorTime(0), _dequeTime(0) {}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_vectorData = other._vectorData;
		_dequeData = other._dequeData;
		_originalData = other._originalData;
		_vectorTime = other._vectorTime;
		_dequeTime = other._dequeTime;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::hasOnlyDigits(const std::string& str, size_t start) const
{
	for (size_t i = start; i < str.length(); i++)
	{
		if (!std::isdigit(static_cast<unsigned char>(str[i])))
			return false;
	}
	return true;
}

bool PmergeMe::isInIntRange(const std::string& str) const
{
	std::stringstream ss(str);
	long num;
	ss >> num;
	
	if (ss.fail() || num < 0 || num > INT_MAX)
		return false;
	return true;
}

bool PmergeMe::isValidNumber(const std::string& str) const
{
	if (str.empty())
		return false;
	
	size_t start = 0;
	
	if (str[0] == '+')
		start = 1;
	else if (str[0] == '-')
		return false;
	
	if (start >= str.length())
		return false;
	
	if (!hasOnlyDigits(str, start))
		return false;
	
	return isInIntRange(str);
}

void PmergeMe::validateInput(const std::string& str)
{
	if (!isValidNumber(str))
		throw std::invalid_argument("Error");
}

void PmergeMe::parseInput(int argc, char** argv)
{
	if (argc < 2)
		throw std::invalid_argument("Error");
	
	for (int i = 1; i < argc; i++)
	{
		std::string arg(argv[i]);
		validateInput(arg);
		
		std::stringstream ss(arg);
		int num;
		ss >> num;
		
		_vectorData.push_back(num);
		_dequeData.push_back(num);
		_originalData.push_back(num);
	}
	
	if (_vectorData.empty())
		throw std::invalid_argument("Error");
}

double PmergeMe::getTimeInMicroseconds(struct timeval start, struct timeval end)
{
	return (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
}

double PmergeMe::measureVectorSort()
{
	struct timeval start, end;
	gettimeofday(&start, NULL);
	mergeInsertSortVector(_vectorData);
	gettimeofday(&end, NULL);
	return getTimeInMicroseconds(start, end);
}

double PmergeMe::measureDequeSort()
{
	struct timeval start, end;
	gettimeofday(&start, NULL);
	mergeInsertSortDeque(_dequeData);
	gettimeofday(&end, NULL);
	return getTimeInMicroseconds(start, end);
}

int PmergeMe::jacobsthal(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	
	int prev2 = 0;
	int prev1 = 1;
	int current = 0;
	
	for (int i = 2; i <= n; i++)
	{
		current = prev1 + 2 * prev2;
		prev2 = prev1;
		prev1 = current;
	}
	return current;
}

std::vector<int> PmergeMe::generateInsertionOrder(int n)
{
	std::vector<int> order;
	
	if (n <= 0)
		return order;
	
	order.push_back(1);
	
	if (n == 1)
		return order;
	
	int jacobIndex = 3;
	int lastJacob = 1;
	
	while (lastJacob < n)
	{
		int currentJacob = jacobsthal(jacobIndex);
		if (currentJacob > n)
			currentJacob = n;
		
		for (int i = currentJacob; i > lastJacob; i--)
			order.push_back(i);
		
		lastJacob = currentJacob;
		jacobIndex++;
	}
	
	return order;
}

void PmergeMe::createPairsVector(std::vector<int>& arr, std::vector<std::pair<int, int> >& pairs, int& straggler, bool& hasStraggler)
{
	size_t i;
	for (i = 0; i + 1 < arr.size(); i += 2)
	{
		if (arr[i] > arr[i + 1])
			pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
		else
			pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
	}
	
	hasStraggler = (i < arr.size());
	if (hasStraggler)
		straggler = arr[i];
}

void PmergeMe::insertStragglerVector(std::vector<int>& sorted, int straggler)
{
	std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), straggler);
	sorted.insert(pos, straggler);
}

std::vector<int> PmergeMe::mergePairsVector(std::vector<std::pair<int, int> >& pairs)
{
	if (pairs.empty())
		return std::vector<int>();
	
	if (pairs.size() == 1)
	{
		std::vector<int> result;
		result.push_back(pairs[0].first);
		result.push_back(pairs[0].second);
		return result;
	}
	
	std::vector<int> mainChain;
	for (size_t i = 0; i < pairs.size(); i++)
		mainChain.push_back(pairs[i].second);
	
	std::vector<std::pair<int, int> > newPairs;
	for (size_t i = 0; i + 1 < mainChain.size(); i += 2)
	{
		if (mainChain[i] > mainChain[i + 1])
			newPairs.push_back(std::make_pair(mainChain[i + 1], mainChain[i]));
		else
			newPairs.push_back(std::make_pair(mainChain[i], mainChain[i + 1]));
	}
	
	if (mainChain.size() % 2 == 1)
		newPairs.push_back(std::make_pair(mainChain[mainChain.size() - 1], mainChain[mainChain.size() - 1]));
	
	std::vector<int> sorted = mergePairsVector(newPairs);
	
	std::vector<int> pending;
	for (size_t i = 0; i < pairs.size(); i++)
		pending.push_back(pairs[i].first);
	
	std::vector<int> insertOrder = generateInsertionOrder(pending.size());
	
	for (size_t i = 0; i < insertOrder.size(); i++)
	{
		int idx = insertOrder[i] - 1;
		if (idx >= 0 && idx < static_cast<int>(pending.size()))
		{
			int value = pending[idx];
			std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), value);
			sorted.insert(pos, value);
		}
	}
	
	return sorted;
}

void PmergeMe::mergeInsertSortVector(std::vector<int>& arr)
{
	if (arr.size() <= 1)
		return;
	
	std::vector<std::pair<int, int> > pairs;
	int straggler = -1;
	bool hasStraggler = false;
	createPairsVector(arr, pairs, straggler, hasStraggler);
	
	std::vector<int> sorted = mergePairsVector(pairs);
	
	if (hasStraggler)
		insertStragglerVector(sorted, straggler);
	
	arr = sorted;
}

void PmergeMe::createPairsDeque(std::deque<int>& arr, std::deque<std::pair<int, int> >& pairs, int& straggler, bool& hasStraggler)
{
	size_t i;
	for (i = 0; i + 1 < arr.size(); i += 2)
	{
		if (arr[i] > arr[i + 1])
			pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
		else
			pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
	}
	
	hasStraggler = (i < arr.size());
	if (hasStraggler)
		straggler = arr[i];
}

void PmergeMe::insertStragglerDeque(std::deque<int>& sorted, int straggler)
{
	std::deque<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), straggler);
	sorted.insert(pos, straggler);
}

std::deque<int> PmergeMe::mergePairsDeque(std::deque<std::pair<int, int> >& pairs)
{
	if (pairs.empty())
		return std::deque<int>();
	
	if (pairs.size() == 1)
	{
		std::deque<int> result;
		result.push_back(pairs[0].first);
		result.push_back(pairs[0].second);
		return result;
	}
	
	std::deque<int> mainChain;
	for (size_t i = 0; i < pairs.size(); i++)
		mainChain.push_back(pairs[i].second);
	
	std::deque<std::pair<int, int> > newPairs;
	for (size_t i = 0; i + 1 < mainChain.size(); i += 2)
	{
		if (mainChain[i] > mainChain[i + 1])
			newPairs.push_back(std::make_pair(mainChain[i + 1], mainChain[i]));
		else
			newPairs.push_back(std::make_pair(mainChain[i], mainChain[i + 1]));
	}
	
	if (mainChain.size() % 2 == 1)
		newPairs.push_back(std::make_pair(mainChain[mainChain.size() - 1], mainChain[mainChain.size() - 1]));
	
	std::deque<int> sorted = mergePairsDeque(newPairs);
	
	std::deque<int> pending;
	for (size_t i = 0; i < pairs.size(); i++)
		pending.push_back(pairs[i].first);
	
	std::vector<int> insertOrder = generateInsertionOrder(pending.size());
	
	for (size_t i = 0; i < insertOrder.size(); i++)
	{
		int idx = insertOrder[i] - 1;
		if (idx >= 0 && idx < static_cast<int>(pending.size()))
		{
			int value = pending[idx];
			std::deque<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), value);
			sorted.insert(pos, value);
		}
	}
	
	return sorted;
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& arr)
{
	if (arr.size() <= 1)
		return;
	
	std::deque<std::pair<int, int> > pairs;
	int straggler = -1;
	bool hasStraggler = false;
	createPairsDeque(arr, pairs, straggler, hasStraggler);
	
	std::deque<int> sorted = mergePairsDeque(pairs);
	
	if (hasStraggler)
		insertStragglerDeque(sorted, straggler);
	
	arr = sorted;
}

void PmergeMe::sort()
{
	_vectorTime = measureVectorSort();
	_dequeTime = measureDequeSort();
}

void PmergeMe::displayResults() const
{
	std::cout << "Before: ";
	for (size_t i = 0; i < _originalData.size() && i < 5; i++)
		std::cout << _originalData[i] << " ";
	if (_originalData.size() > 5)
		std::cout << "[...]";
	std::cout << std::endl;
	

	std::cout << "After: ";
	for (size_t i = 0; i < _vectorData.size() && i < 5; i++)
		std::cout << _vectorData[i] << " ";
	if (_vectorData.size() > 5)
		std::cout << "[...]";
	std::cout << std::endl;
	
	
	std::cout << "Time to process a range of " << _vectorData.size() 
			  << " elements with std::vector : " << _vectorTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _dequeData.size() 
			  << " elements with std::deque : " << _dequeTime << " us" << std::endl;
}
