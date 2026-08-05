/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 13:53:58 by mamaratr          #+#    #+#             */
/*   Updated: 2026/08/05 09:05:44 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

int	main(void)
{
	std::srand(std::time(NULL));
	{
		std::cout << "Test 1:" << std::endl;
		A *a = new A();
		B *b = new B();
		C *c = new C();

		identify(a);
		identify(b);
		identify(c);
		identify(NULL);
		std::cout << std::endl << "----" << std::endl;
		identify(*a);
		identify(*b);
		identify(*c);

		delete a;
		delete b;
		delete c;
	}
	{
		std::cout << "----" << std::endl;
		std::cout << "Test 2:" << std::endl;
		Base *base;

		base = generate();

		identify(base);
		identify(*base);

		delete (base);
	}
	return (0);
}
