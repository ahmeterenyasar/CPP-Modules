#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _vectorTime(0), _dequeTime(0)
{
}

PmergeMe::~PmergeMe()
{
}

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
		_vectorTime = other._vectorTime;
		_dequeTime = other._dequeTime;
	}
	return *this;
}

void PmergeMe::validateInput(const std::string& str)
{
	if (str.empty())
		throw std::invalid_argument("Error");
	
	// Check if it starts with a sign
	size_t i = 0;
	if (str[0] == '+')
		i = 1;
	else if (str[0] == '-')
		throw std::invalid_argument("Error");
	
	if (i >= str.length())
		throw std::invalid_argument("Error");
	
	// Check if all remaining characters are digits
	for (; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			throw std::invalid_argument("Error");
	}
	
	// Convert and check range
	std::stringstream ss(str);
	long num;
	ss >> num;
	
	if (ss.fail() || num < 0 || num > 2147483647)
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

void PmergeMe::insertionSortVector(std::vector<int>& arr, int left, int right)
{
	for (int i = left + 1; i <= right; i++)
	{
		int key = arr[i];
		int j = i - 1;
		
		while (j >= left && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

std::vector<int> PmergeMe::mergePairsVector(std::vector<std::pair<int, int> >& pairs)
{
	if (pairs.empty())
		return std::vector<int>();
	
	if (pairs.size() == 1)
	{
		std::vector<int> result;
		result.push_back(pairs[0].second);
		result.push_back(pairs[0].first);
		return result;
	}
	
	// Extract larger elements (main chain)
	std::vector<int> mainChain;
	for (size_t i = 0; i < pairs.size(); i++)
		mainChain.push_back(pairs[i].second);
	
	// Sort main chain recursively by creating new pairs
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
	
	// Build the pending elements list (smaller elements from pairs)
	std::vector<int> pending;
	for (size_t i = 0; i < pairs.size(); i++)
		pending.push_back(pairs[i].first);
	
	// Insert pending elements using Jacobsthal sequence
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
	
	if (arr.size() <= 10)
	{
		insertionSortVector(arr, 0, arr.size() - 1);
		return;
	}
	
	// Create pairs and sort each pair
	std::vector<std::pair<int, int> > pairs;
	size_t i;
	for (i = 0; i + 1 < arr.size(); i += 2)
	{
		if (arr[i] > arr[i + 1])
			pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
		else
			pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
	}
	
	// Handle odd element
	int straggler = -1;
	bool hasStraggler = false;
	if (i < arr.size())
	{
		straggler = arr[i];
		hasStraggler = true;
	}
	
	// Recursively sort and merge
	std::vector<int> sorted = mergePairsVector(pairs);
	
	// Insert straggler if exists
	if (hasStraggler)
	{
		std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), straggler);
		sorted.insert(pos, straggler);
	}
	
	arr = sorted;
}

void PmergeMe::insertionSortDeque(std::deque<int>& arr, int left, int right)
{
	for (int i = left + 1; i <= right; i++)
	{
		int key = arr[i];
		int j = i - 1;
		
		while (j >= left && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

std::deque<int> PmergeMe::mergePairsDeque(std::deque<std::pair<int, int> >& pairs)
{
	if (pairs.empty())
		return std::deque<int>();
	
	if (pairs.size() == 1)
	{
		std::deque<int> result;
		result.push_back(pairs[0].second);
		result.push_back(pairs[0].first);
		return result;
	}
	
	// Extract larger elements (main chain)
	std::deque<int> mainChain;
	for (size_t i = 0; i < pairs.size(); i++)
		mainChain.push_back(pairs[i].second);
	
	// Sort main chain recursively
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
	
	// Build pending elements list
	std::deque<int> pending;
	for (size_t i = 0; i < pairs.size(); i++)
		pending.push_back(pairs[i].first);
	
	// Insert pending elements using Jacobsthal sequence
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
	
	if (arr.size() <= 10)
	{
		insertionSortDeque(arr, 0, arr.size() - 1);
		return;
	}
	
	// Create pairs and sort each pair
	std::deque<std::pair<int, int> > pairs;
	size_t i;
	for (i = 0; i + 1 < arr.size(); i += 2)
	{
		if (arr[i] > arr[i + 1])
			pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
		else
			pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
	}
	
	// Handle odd element
	int straggler = -1;
	bool hasStraggler = false;
	if (i < arr.size())
	{
		straggler = arr[i];
		hasStraggler = true;
	}
	
	// Recursively sort and merge
	std::deque<int> sorted = mergePairsDeque(pairs);
	
	// Insert straggler if exists
	if (hasStraggler)
	{
		std::deque<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), straggler);
		sorted.insert(pos, straggler);
	}
	
	arr = sorted;
}

void PmergeMe::sort()
{
	struct timeval start, end;
	
	// Sort using vector
	gettimeofday(&start, NULL);
	mergeInsertSortVector(_vectorData);
	gettimeofday(&end, NULL);
	_vectorTime = getTimeInMicroseconds(start, end);
	
	// Sort using deque
	gettimeofday(&start, NULL);
	mergeInsertSortDeque(_dequeData);
	gettimeofday(&end, NULL);
	_dequeTime = getTimeInMicroseconds(start, end);
}

void PmergeMe::displayResults() const
{
	// Display "Before"
	std::cout << "Before: ";
	for (size_t i = 0; i < _originalData.size() && i < 5; i++)
		std::cout << _originalData[i] << " ";
	if (_originalData.size() > 5)
		std::cout << "[...]";
	std::cout << std::endl;
	
	// Display "After"
	std::cout << "After: ";
	for (size_t i = 0; i < _vectorData.size() && i < 5; i++)
		std::cout << _vectorData[i] << " ";
	if (_vectorData.size() > 5)
		std::cout << "[...]";
	std::cout << std::endl;
	
	// Display times
	std::cout << "Time to process a range of " << _vectorData.size() 
			  << " elements with std::vector : " << _vectorTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _dequeData.size() 
			  << " elements with std::deque : " << _dequeTime << " us" << std::endl;
}
