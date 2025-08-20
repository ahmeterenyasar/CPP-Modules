/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 20:10:06 by ayasar            #+#    #+#             */
/*   Updated: 2025/07/30 21:26:25 by ayasar           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <Zombie.hpp>
#include <iostream>

int main()
{
    std::cout << "=== Heap allocation ===" << std::endl;
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    delete heapZombie;

    std::cout << "\n=== Stack allocation ===" << std::endl;
    randomChump("StackZombie");

    return 0;
}