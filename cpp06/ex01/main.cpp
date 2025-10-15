/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 13:06:41 by ayasar            #+#    #+#             */
/*   Updated: 2025/10/15 14:42:08 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main() {
    Data originalData;
    originalData.text = "Ahmet Eren";
    
    std::cout << "Original Data: " << originalData.text << std::endl;
    std::cout << "Original pointer: " << &originalData << std::endl;
    
    uintptr_t serialized = Serializer::serialize(&originalData);
    std::cout << "Serialized: " << serialized << std::endl;
    
    Data* deserialized = Serializer::deserialize(serialized);
    
    std::cout << "Deserialized Data: " << deserialized->text << std::endl;
    std::cout << "Deserialized pointer: " << deserialized << std::endl;
    std::cout << "Same pointer? " << ((&originalData == deserialized) ? "YES" : "NO") << std::endl;
    
    return 0;
}

