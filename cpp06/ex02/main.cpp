/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 13:06:48 by ayasar            #+#    #+#             */
/*   Updated: 2025/10/15 17:02:38 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>

int main() {
    std::cout << "=== Type Identification Test ===" << std::endl;
    
    for (int i = 0; i < 5; i++) {
        std::cout << "\nTest " << (i + 1) << ":" << std::endl;
        
        Base* obj = generate();
        
        std::cout << "Identify by pointer: ";
        identify(obj);
        
        std::cout << "Identify by reference: ";
        identify(*obj);
        
        delete obj;
    }

    return 0;
}

