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
    std::cout << "=== newZombie heap allocation ===" << std::endl;
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    delete heapZombie;

    std::cout << "\n=== randomChump stack allocation ===" << std::endl;
    randomChump("StackZombie");
    
    std::cout << "\n=== direct stack allocation ===" << std::endl;

    {
        Zombie stackZombie("LocalUndeadZombie");
        stackZombie.announce();
    }

    std::cout << "\n THE END." << std::endl;
    return 0;
}