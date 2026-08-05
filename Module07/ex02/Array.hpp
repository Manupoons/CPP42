/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 10:25:18 by mamaratr          #+#    #+#             */
/*   Updated: 2026/08/05 10:28:19 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
	private:
		T *array;
		int a_size;
	
	public:
		Array();
		Array(unsigned int n);
		Array(Array &copy);
		Array &operator=(Array &assign);
		~Array();

		T& operator [](int index);
		const T& operator [](int index) const;
		int size() const;
};

#include "Array.tpp"

#endif