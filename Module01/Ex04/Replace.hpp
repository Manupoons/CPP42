/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 09:59:35 by mamaratr          #+#    #+#             */
/*   Updated: 2025/07/20 10:08:52 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <string>
#include <iostream>
#include <fstream>

class Replace {
	private:
		std::string _filename;
		std::string _str1;
		std::string _str2;

		std::string replaceLine(const std::string &line);
		
	public:
		Replace(const std::string &filename, const std::string &str1, const std::string &str2);
		~Replace();

		bool process();
};

#endif