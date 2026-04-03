/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 18:55:49 by mamaratr          #+#    #+#             */
/*   Updated: 2026/04/03 18:55:50 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(std::string name);
		~ScavTrap();
		
		void attack(const std::string& target);
		void guardGate();
};

#endif