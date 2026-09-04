/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 08:46:13 by mamaratr          #+#    #+#             */
/*   Updated: 2026/09/04 10:02:00 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <algorithm>
#include <cerrno>
#include <cctype>
#include <cstdio>

struct CompareByValueVector
{
	const std::vector<long> &vals;
	CompareByValueVector(const std::vector<long> &v) : vals(v) {}
	bool operator()(size_t a, size_t b) const { return (vals[a] < vals[b]); }
};

struct CompareByValueDeque
{
	const std::deque<long> &vals;
	CompareByValueDeque(const std::deque<long> &v) : vals(v) {}
	bool operator()(size_t a, size_t b) const { return (vals[a] < vals[b]); }
};

std::vector<long> PmergeMe::parseArgs(int argc, char **argv)
{
	std::vector<long> result;

	if (argc < 2)
		throw PmergeMe::ErrorException();

	for (int i = 1; i < argc; i++)
	{
		std::string token(argv[i]);
		if (token.empty())
			throw PmergeMe::ErrorException();

		errno = 0;
		char *end;
		long value = std::strtol(token.c_str(), &end, 10);

		if (*end != '\0' || errno == ERANGE || value < 0 || value > INT_MAX)
			throw PmergeMe::ErrorException();
		
		result.push_back(value);
	}
	return (result);
}

static std::vector<size_t> jacobsthalOrderVector(size_t m)
{
	std::vector<size_t> order;
	if (m == 0)
		return (order);

	std::vector<long> jac;
	jac.push_back(0);
	jac.push_back(1);
	while (jac.back() <= static_cast<long>(m) + 1)
		jac.push_back(jac.back() + 2 * jac[jac.size() - 2]);
	
	size_t placed = 0;
	size_t t = 2;
	while (placed < m)
	{
		long hi = jac[t];
		if (hi > static_cast<long>(m) + 1)
			hi = static_cast<long>(m) + 1;
		long lo = jac[t - 1] + 1;
		for (long b = hi; b >= lo; b--)
		{
			if (b >= 2)
			{
				order.push_back(static_cast<size_t>(b - 2));
				placed++;
			}
		}
		t++;
	}
	return (order);
}

std::vector<size_t> PmergeMe::sortIndxVector(std::vector<size_t> indices, const std::vector<long> &vals)
{
	if (indices.size() <= 1)
		return (indices);
	
	std::vector<size_t> winners;
	std::vector<size_t> losers;
	bool hasStraggler = (indices.size() % 2 == 1);
	size_t stragglerIdx = 0;
	if (hasStraggler)
		stragglerIdx = indices.back();

	size_t limit = hasStraggler ? indices.size() - 1 : indices.size();
	for (size_t i = 0; i < limit; i += 2)
	{
		size_t a = indices[i];
		size_t b = indices[i + 1];
		if (vals[a] > vals[b])
		{
			winners.push_back(a);
			losers.push_back(b);
		}
		else
		{
			winners.push_back(b);
			losers.push_back(a);
		}
	}

	std::vector<size_t> sortedWinners = sortIndxVector(winners, vals);
	
	std::vector<size_t> loserOf(vals.size());
	for (size_t i = 0; i < winners.size(); i++)
		loserOf[winners[i]] = losers[i];
	
	std::vector<size_t> chain;
	chain.push_back(loserOf[sortedWinners[0]]);
	for (size_t i = 0; i < sortedWinners.size(); i++)
		chain.push_back(sortedWinners[i]);

	std::vector<size_t> pend;
	for (size_t i = 1; i < sortedWinners.size(); i++)
		pend.push_back(loserOf[sortedWinners[i]]);

	std::vector<size_t> order = jacobsthalOrderVector(pend.size());
	for (size_t i = 0; i < order.size(); i++)
	{
		size_t pednIndx = pend[order[i]];
		size_t winnerIndx = sortedWinners[order[i] + 1];

		std::vector<size_t>::iterator boundIt = std::find(chain.begin(), chain.end(), winnerIndx);
		std::vector<size_t>::iterator pos = std::lower_bound(chain.begin(), boundIt, pednIndx, CompareByValueVector(vals));
		chain.insert(pos, pednIndx);
	}

	if (hasStraggler)
	{
		std::vector<size_t>::iterator pos = std::lower_bound(chain.begin(), chain.end(), stragglerIdx, CompareByValueVector(vals));
		chain.insert(pos, stragglerIdx);
	}
	return (chain);
}

std::vector<long> PmergeMe::sortVector(std::vector<long> input)
{
	std::vector<size_t> indices;
	for (size_t i = 0; i < input.size(); i++)
		indices.push_back(i);
	
	std::vector<size_t> sortedIndx = sortIndxVector(indices, input);
	
	std::vector<long> result;
	for (size_t i = 0; i < sortedIndx.size(); i++)
		result.push_back(input[sortedIndx[i]]);
	return (result);
}

static std::deque<size_t> jacobsthalOrderDeque(size_t m)
{
	std::deque<size_t> order;
	if (m == 0)
		return (order);

	std::deque<long> jac;
	jac.push_back(0);
	jac.push_back(1);
	while (jac.back() <= static_cast<long>(m) + 1)
		jac.push_back(jac.back() + 2 * jac[jac.size() - 2]);
	
	size_t placed = 0;
	size_t t = 2;
	while (placed < m)
	{
		long hi = jac[t];
		if (hi > static_cast<long>(m) + 1)
			hi = static_cast<long>(m) + 1;
		long lo = jac[t - 1] + 1;
		for (long b = hi; b >= lo; b--)
		{
			if (b >= 2)
			{
				order.push_back(static_cast<size_t>(b - 2));
				placed++;
			}
		}
		t++;
	}
	return (order);
}

std::deque<size_t> PmergeMe::sortIndxDeque(std::deque<size_t> indices, const std::deque<long> &vals)
{
	if (indices.size() <= 1)
		return (indices);
	
	std::deque<size_t> winners;
	std::deque<size_t> losers;
	bool hasStraggler = (indices.size() % 2 == 1);
	size_t stragglerIdx = 0;
	if (hasStraggler)
		stragglerIdx = indices.back();

	size_t limit = hasStraggler ? indices.size() - 1 : indices.size();
	for (size_t i = 0; i < limit; i += 2)
	{
		size_t a = indices[i];
		size_t b = indices[i + 1];
		if (vals[a] > vals[b])
		{
			winners.push_back(a);
			losers.push_back(b);
		}
		else
		{
			winners.push_back(b);
			losers.push_back(a);
		}
	}

	std::deque<size_t> sortedWinners = sortIndxDeque(winners, vals);
	
	std::vector<size_t> loserOf(vals.size());
	for (size_t i = 0; i < winners.size(); i++)
		loserOf[winners[i]] = losers[i];
	
	std::deque<size_t> chain;
	chain.push_back(loserOf[sortedWinners[0]]);
	for (size_t i = 0; i < sortedWinners.size(); i++)
		chain.push_back(sortedWinners[i]);

	std::deque<size_t> pend;
	for (size_t i = 1; i < sortedWinners.size(); i++)
		pend.push_back(loserOf[sortedWinners[i]]);

	std::deque<size_t> order = jacobsthalOrderDeque(pend.size());
	for (size_t i = 0; i < order.size(); i++)
	{
		size_t pednIndx = pend[order[i]];
		size_t winnerIndx = sortedWinners[order[i] + 1];

		std::deque<size_t>::iterator boundIt = std::find(chain.begin(), chain.end(), winnerIndx);
		std::deque<size_t>::iterator pos = std::lower_bound(chain.begin(), boundIt, pednIndx, CompareByValueDeque(vals));
		chain.insert(pos, pednIndx);
	}

	if (hasStraggler)
	{
		std::deque<size_t>::iterator pos = std::lower_bound(chain.begin(), chain.end(), stragglerIdx, CompareByValueDeque(vals));
		chain.insert(pos, stragglerIdx);
	}
	return (chain);
}

std::deque<long> PmergeMe::sortDeque(std::deque<long> input)
{
	std::deque<size_t> indices;
	for (size_t i = 0; i < input.size(); i++)
		indices.push_back(i);
	
	std::deque<size_t> sortedIndx = sortIndxDeque(indices, input);
	
	std::deque<long> result;
	for (size_t i = 0; i < sortedIndx.size(); i++)
		result.push_back(input[sortedIndx[i]]);
	return (result);
}

const char* PmergeMe::ErrorException::what() const throw()
{
	return ("Error");
}
