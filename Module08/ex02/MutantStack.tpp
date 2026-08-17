/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 13:33:35 by mamaratr          #+#    #+#             */
/*   Updated: 2026/08/17 11:43:45 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& copy) : std::stack<T>() {
	this->c = copy.c;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator =(const MutantStack& assign) {
	if (this != &assign)
		this->c = assign.c;
	return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack() {
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const {
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const {
	return (this->c.end());
}

#endif