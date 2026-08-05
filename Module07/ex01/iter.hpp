/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 09:59:17 by mamaratr          #+#    #+#             */
/*   Updated: 2026/08/05 10:10:34 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <string>

template <typename A, typename L>
void iter(A *array, L len, void (*f)(A&))
{
	if (array == NULL || f == NULL)
		return;
		
	size_t size = static_cast<long>(len);
	
	for (size_t i = 0; i < size; i++)
	{
		f(array[i]);
	}
}

template <typename A, typename L, typename T>
void iter(A *array, L len, void (*f)(const T&))
{
	if (array == NULL || f == NULL)
		return;
		
	size_t size = static_cast<long>(len);
	
	for (size_t i = 0; i < size; i++)
	{
		f(array[i]);
	}
}

#endif