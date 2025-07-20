/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 10:03:12 by mamaratr          #+#    #+#             */
/*   Updated: 2025/07/20 10:38:45 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(const std::string &filename, const std::string &str1, const std::string &str2) : _filename(filename), _str1(str1), _str2(str2) {
	std::cout << "Replacer created" << std::endl;
}

Replace::~Replace () {
	std::cout << "Replacer destroyed" << std::endl;
}

bool Replace::process() {
	if (_str1.empty()) {
		std::cerr << "Error: str1 must not be empty" << std::endl;
		return false;
	}

	std::ifstream infile;
	std::ofstream outfile;
	std::string line;
	
	infile.open(_filename.c_str());
	if (!infile.is_open()) {
		std::cerr << "Error: Could not open input file." << std::endl;
		return false;
	}

	outfile.open((_filename + ".replace").c_str());
	if (!outfile.is_open()) {
		std::cerr << "Error: Could not create output file." << std::endl;
		infile.close();
		return false;
	}

	while (std::getline(infile, line))
		outfile << replaceLine(line) << std::endl;

	infile.close();
	outfile.close();

	return true;
}

std::string Replace::replaceLine(const std::string &line) {
	std::string result;
	size_t start = 0;
	size_t pos = line.find(_str1);

	while (pos != std::string::npos) {
		result += line.substr(start, pos - start);
		result += _str2;
		start = pos + _str1.length();
		pos = line.find(_str1, start);
	}

	result += line.substr(start);
	return result;
}