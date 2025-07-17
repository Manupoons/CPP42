/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:55:19 by mamaratr          #+#    #+#             */
/*   Updated: 2025/07/17 18:57:46 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
	Zombie *zombie;
	
	zombie = newZombie("Marvin");
	zombie->announce();
	randomChump("Jorge");
	delete zombie;
	return (0);
}