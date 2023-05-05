/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:56:36 by pfrances          #+#    #+#             */
/*   Updated: 2023/05/05 17:27:04 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <ostream>

template<typename T>
class Array {

public:
	Array( void ) : array_(new T[0]), size_(0) {
		std::cout << "[Array] default constructor called." << std::endl;
	}
	Array( const unsigned int n) : array_(new T[n]), size_(n) {
		std::cout << "[Array] typed constructor called." << std::endl;
	}

	Array(const Array& other) : size_(other.size()) {
		this->array_ = new T[this->size_];
		for (unsigned int i = 0; i < this->size_; i++) {
			this->array_[i] = other.array_[i];
		}
		std::cout << "[Array] copy constructor called." << std::endl;
	}

	Array&	operator=(const Array& other) {
		if (this != &other) {
			if (this->size_ != other.size())
			delete[] this->array_;
			this->size_ = other.size_;
			this->array_ = new T[this->size_];
			for (unsigned int i = 0; i < this->size_; i++) {
				this->array_[i] = other.array_[i];
			}
		}
		std::cout << "[Array] asignment called." << std::endl;
		return *this;
	}

	T&		operator[](unsigned int index) {
		if (index >= this->size()) {
			std::cerr << "[Array] index [" << index << "] out of range." << std::endl;
			throw std::exception();
		}
		return this->array_[index];
	}
	virtual	~Array( void ) {
		delete[] this->array_;
		std::cout << "[Array] destructor called." << std::endl;
	}

	unsigned int	size(void) const {
		return this->size_;
	}

private:
	T*				array_;
	unsigned int	size_;
};

template<typename T>
std::ostream&	operator<<(std::ostream &os, const Array<T> &arr) {
	for (unsigned int i = 0; i < arr.size(); ++i) {
		os << "[" << arr[i] << "] ";
	}
	return (os);
}

#endif
