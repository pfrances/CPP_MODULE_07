/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:58:06 by pfrances          #+#    #+#             */
/*   Updated: 2023/05/05 15:42:35 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <stddef.h>
# include <iostream>

template<typename T>
void	iter(T *array, size_t size, void (*func)(T const &)) {
	for (size_t i = 0; i < size; i++) {
		func(array[i]);
	}
}

template<typename T>
void	print(T const &x) {
	std::cout << x << std::endl;
}

template<typename T>
void	print_ptr(T const &x) {
	std::cout << &x << std::endl;
}

#endif

