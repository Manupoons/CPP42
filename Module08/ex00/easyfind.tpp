/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 11:21:26 by mamaratr          #+#    #+#             */
/*   Updated: 2026/08/05 11:30:43 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
#define EASYFIND_TPP

template <typename T>
typename T::iterator easyfind(T& a, int b)
{
	typename T::iterator it = std::find(a.begin(), a.end(), b);
	if (it == a.end())
		throw std::logic_error("No occurence found");
	return (it);
}

#endif
