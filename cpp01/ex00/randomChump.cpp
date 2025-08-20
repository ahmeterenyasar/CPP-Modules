/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 21:18:07 by ayasar            #+#    #+#             */
/*   Updated: 2025/07/30 21:18:53 by ayasar           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Zombie.hpp"

/* Creates a zombie on the stack and makes it announce itself */
void randomChump(std::string name)
{
    Zombie zombie(name);
    zombie.announce();
}