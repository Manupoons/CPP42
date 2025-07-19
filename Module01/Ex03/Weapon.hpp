/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:23:39 by mamaratr          #+#    #+#             */
/*   Updated: 2025/07/19 18:05:29 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon {
	private:
		std::string type;
		
	public:
		Weapon(void);
		Weapon(std::string);
		~Weapon();
	
		const std::string& getType(void) const;
		void setType(std::string);
};

#endif