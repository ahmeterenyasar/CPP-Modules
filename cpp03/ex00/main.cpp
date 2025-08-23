/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:23:04 by ayasar            #+#    #+#             */
/*   Updated: 2025/08/23 15:35:18 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	std::cout << "=== Creating ClapTrap instances ===" << std::endl;
	ClapTrap clap1("Robo");
	ClapTrap clap2("Mecha");

	std::cout << "\n=== Initial Status ===" << std::endl;
	std::cout << clap1.getName() << " - HP: " << clap1.getHitPoints() 
			  << ", Energy: " << clap1.getEnergyPoints() 
			  << ", Attack Damage: " << clap1.getAttackDamage() << std::endl;

	std::cout << "\n=== Testing Attack Function ===" << std::endl;
	clap1.attack("Enemy1");
	clap1.attack("Enemy2");
	clap1.attack("Enemy3");

	std::cout << "\n=== Testing Repair Function ===" << std::endl;
	clap1.beRepaired(5);
	clap1.beRepaired(3);

	std::cout << "\n=== Testing Take Damage Function ===" << std::endl;
	clap2.takeDamage(3);
	clap2.takeDamage(4);
	clap2.takeDamage(2);

	std::cout << "\n=== Current Status ===" << std::endl;
	std::cout << clap1.getName() << " - HP: " << clap1.getHitPoints() 
			  << ", Energy: " << clap1.getEnergyPoints() << std::endl;
	std::cout << clap2.getName() << " - HP: " << clap2.getHitPoints() 
			  << ", Energy: " << clap2.getEnergyPoints() << std::endl;

	std::cout << "\n=== Testing Energy Depletion ===" << std::endl;
	// Exhaust remaining energy of clap1
	for (int i = 0; i < 10; i++)
	{
		clap1.attack("Target");
	}

	std::cout << "\n=== Testing Dead ClapTrap ===" << std::endl;
	clap2.takeDamage(15); // This should kill clap2
	clap2.attack("DeadTarget");
	clap2.beRepaired(5);
	clap2.takeDamage(1);

	std::cout << "\n=== Testing Copy Constructor ===" << std::endl;
	ClapTrap clap3(clap1);

	std::cout << "\n=== Testing Assignment Operator ===" << std::endl;
	ClapTrap clap4("Temp");
	clap4 = clap1;

	std::cout << "\n=== End of tests - Destructors will be called ===" << std::endl;
	return 0;
}

