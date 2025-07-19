/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:55:19 by mamaratr          #+#    #+#             */
/*   Updated: 2025/07/19 17:03:01 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
	int N = 4;
	Zombie *horde = zombieHorde(N, "Marvin");

	for (int i = 0; i < N; i++) {
		horde[i].announce();
	}
	
	delete[] horde;
	return (0);
}