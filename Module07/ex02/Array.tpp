/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 10:28:45 by mamaratr          #+#    #+#             */
/*   Updated: 2026/08/05 10:52:15 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

template <typename T>
Array<T>::Array()
{
	this->a_size = 0;
	this->array = new T[this->a_size];
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->a_size = n;
	this->array = new T[this->a_size];
}

template <typename T>
Array<T>::Array(Array &copy)
{
	this->a_size = copy.size();
	this->array = new T[this->a_size];
	for (int i = 0; i < this->a_size; i++)
		this->array[i] = copy[i];
}

template <typename T>
Array<T>& Array<T>::operator=(Array &assign)
{
	if (this != &assign)
	{
		delete[] this->array;
		this->a_size = assign.size();
		this->array = new T[this->a_size];
		for (int i = 0; i < this->a_size; i++)
			this->array[i] = assign[i];
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete[] this->array;
}

template <typename T>
T& Array<T>::operator[](int index)
{
	if (index < 0 || index >= this->size())
		throw std::exception();
	return (this->array[index]);
}

template <typename T>
const T& Array<T>::operator[](int index) const
{
	if (index < 0 || index >= this->size())
		throw std::exception();
	return (this->array[index]);
}

template <typename T>
int Array<T>::size() const
{
	return (this->a_size);
}

#endif