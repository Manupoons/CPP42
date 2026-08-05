/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 09:45:44 by mamaratr          #+#    #+#             */
/*   Updated: 2026/08/05 09:51:36 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <string>

template <typename T>
void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T min(T &a, T &b)
{
	if (a < b)
		return (a);
	return (b);
}

template <typename T>
T max(T &a, T &b)
{
	if (a < b)
		return (b);
	return (a);
}

#endif