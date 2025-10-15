/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:30:00 by ayasar            #+#    #+#             */
/*   Updated: 2025/10/15 16:35:54 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer &copy)
{
	*this = copy;
}

Serializer::~Serializer() {}

Serializer &Serializer::operator=(const Serializer &copy) {
	if (this != &copy)
		*this = copy;
	return (*this);
}

uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}
