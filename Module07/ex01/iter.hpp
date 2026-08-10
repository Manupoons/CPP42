/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 09:59:17 by mamaratr          #+#    #+#             */
/*   Updated: 2026/08/10 11:23:32 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <string>
# include <iostream>

# define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))


template <typename T>
void	printElement(const T &element)
{
	std::cout << "Element: "<< element << std::endl;
}

void	sumOne(int &num)
{
	num += 1;
	std::cout << "Element + 1: " << num << std::endl;
}

template <typename T, typename F>
void iter(T *array, size_t const len, F f)
{
	if (array == NULL)
		return;
	for (size_t i = 0; i < len; i++)
		f(array[i]);
}

#endif