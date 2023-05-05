/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:38:04 by pfrances          #+#    #+#             */
/*   Updated: 2023/05/05 15:46:19 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void	print_twice(int const& x) {
	std::cout << x << x << std::endl;
}

void	print_twice(std::string const& str) {
	std::cout << str << str << std::endl;
}

int main( void ) {
	int int_array[5] = {1, 2, 3, 4, 5};
	std::string str_array[5] = {"a", "b", "c", "d", "e"};

	std::cout << "int_array" << std::endl;
	iter(int_array, sizeof(int_array) / sizeof(int), print);
	iter(int_array, sizeof(int_array) / sizeof(int), print_ptr);
	iter(int_array, sizeof(int_array) / sizeof(int), print_twice);
	std::cout << std::endl;
	std::cout << "str_array" << std::endl;
	iter(str_array, sizeof(str_array) / sizeof(std::string), print);
	iter(str_array, sizeof(str_array) / sizeof(std::string), print_ptr);
	iter(str_array, sizeof(str_array) / sizeof(std::string), print_twice);
	std::cout << std::endl;
	return 0;
}
