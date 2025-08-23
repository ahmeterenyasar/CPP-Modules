/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:23:02 by ayasar            #+#    #+#             */
/*   Updated: 2025/08/23 15:35:18 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructor
ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " is born!" << std::endl;
}

// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " is destroyed!" << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hitPoints(other._hitPoints), 
	_energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap " << _name << " is copied!" << std::endl;
}

// Assignment operator
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
		std::cout << "ClapTrap " << _name << " is assigned!" << std::endl;
	}
	return *this;
}

// Attack function
void ClapTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is dead and can't attack!" << std::endl;
		return;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy to attack!" << std::endl;
		return;
	}
	
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

// Take damage function
void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
		return;
	}
	
	if (amount >= _hitPoints)
	{
		_hitPoints = 0;
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage and dies!" << std::endl;
	}
	else
	{
		_hitPoints -= amount;
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage! Health remaining: " << _hitPoints << std::endl;
	}
}

// Repair function
void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is dead and can't be repaired!" << std::endl;
		return;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy to repair!" << std::endl;
		return;
	}
	
	_energyPoints--;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " hit points! Current health: " << _hitPoints << std::endl;
}

// Getters
std::string ClapTrap::getName() const
{
	return _name;
}

unsigned int ClapTrap::getHitPoints() const
{
	return _hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const
{
	return _energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const
{
	return _attackDamage;
}

