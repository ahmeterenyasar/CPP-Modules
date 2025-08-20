/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 20:11:46 by ayasar            #+#    #+#             */
/*   Updated: 2025/07/30 21:26:49 by ayasar           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Zombie.hpp"
#include <iostream>

Zombie* newZombie(std::string name)
{
    Zombie* zombie = new Zombie(name);
    return zombie;
}