/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:36:00 by ayasar            #+#    #+#             */
/*   Updated: 2025/08/23 15:38:01 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	// Constructor
	ScavTrap(const std::string& name);
	
	// Destructor
	~ScavTrap();
	
	// Copy constructor
	ScavTrap(const ScavTrap& other);
	
	// Assignment operator
	ScavTrap& operator=(const ScavTrap& other);
	
	// Override attack function
	void attack(const std::string& target);
	
	// Special ability
	void guardGate();
};

#endif
