/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:29:02 by mamaratr          #+#    #+#             */
/*   Updated: 2025/07/17 18:54:07 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie {
	private:
		std::string name;
	
	public:
		Zombie(std::string name);
		~Zombie(void);
		
		void setName(std::string str);
		std::string getName(void) const;
		void announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif