/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 20:10:04 by ayasar            #+#    #+#             */
/*   Updated: 2025/07/30 21:23:37 by ayasar           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
    private:
        std::string name;

    public:
        Zombie(std::string zombieName);
        ~Zombie();
        void announce(void);
};

Zombie* newZombie(std::string name);
void    randomChump(std::string name);

#endif