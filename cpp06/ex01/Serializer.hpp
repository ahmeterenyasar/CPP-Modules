/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:30:00 by ayasar            #+#    #+#             */
/*   Updated: 2025/10/15 16:37:37 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include "Data.hpp"

class Serializer {
    private:
        Serializer();
        Serializer(const Serializer& other);
        Serializer& operator=(const Serializer& other);
        ~Serializer();
        
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif
