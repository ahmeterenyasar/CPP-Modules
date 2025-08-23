/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:23:04 by ayasar            #+#    #+#             */
/*   Updated: 2025/08/23 15:38:01 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	std::cout << "=== Creating ClapTrap instances ===" << std::endl;
	ClapTrap clap1("Robo");
	ClapTrap clap2("Mecha");

	std::cout << "\n=== Initial ClapTrap Status ===" << std::endl;
	std::cout << clap1.getName() << " - HP: " << clap1.getHitPoints() 
			  << ", Energy: " << clap1.getEnergyPoints() 
			  << ", Attack Damage: " << clap1.getAttackDamage() << std::endl;

	std::cout << "\n=== Testing ClapTrap Attack Function ===" << std::endl;
	clap1.attack("Enemy1");
	clap1.attack("Enemy2");
	clap1.attack("Enemy3");

	std::cout << "\n=== Testing ClapTrap Repair Function ===" << std::endl;
	clap1.beRepaired(5);
	clap1.beRepaired(3);

	std::cout << "\n=== Testing ClapTrap Take Damage Function ===" << std::endl;
	clap2.takeDamage(3);
	clap2.takeDamage(4);
	clap2.takeDamage(2);

	std::cout << "\n=== Current ClapTrap Status ===" << std::endl;
	std::cout << clap1.getName() << " - HP: " << clap1.getHitPoints() 
			  << ", Energy: " << clap1.getEnergyPoints() << std::endl;
	std::cout << clap2.getName() << " - HP: " << clap2.getHitPoints() 
			  << ", Energy: " << clap2.getEnergyPoints() << std::endl;

	std::cout << "\n\n=== SCAVTRAP TESTS ===" << std::endl;
	std::cout << "=== Creating ScavTrap instances (showing construction chaining) ===" << std::endl;
	ScavTrap scav1("Guardian");
	ScavTrap scav2("Sentinel");

	std::cout << "\n=== Initial ScavTrap Status ===" << std::endl;
	std::cout << scav1.getName() << " - HP: " << scav1.getHitPoints() 
			  << ", Energy: " << scav1.getEnergyPoints() 
			  << ", Attack Damage: " << scav1.getAttackDamage() << std::endl;

	std::cout << "\n=== Testing ScavTrap Attack Function (overridden) ===" << std::endl;
	scav1.attack("Intruder1");
	scav1.attack("Intruder2");
	scav1.attack("Intruder3");

	std::cout << "\n=== Testing ScavTrap Special Ability: Guard Gate ===" << std::endl;
	scav1.guardGate();
	scav2.guardGate();

	std::cout << "\n=== Testing ScavTrap Inherited Functions ===" << std::endl;
	scav1.beRepaired(10);
	scav2.takeDamage(25);
	scav2.takeDamage(30);

	std::cout << "\n=== Current ScavTrap Status ===" << std::endl;
	std::cout << scav1.getName() << " - HP: " << scav1.getHitPoints() 
			  << ", Energy: " << scav1.getEnergyPoints() << std::endl;
	std::cout << scav2.getName() << " - HP: " << scav2.getHitPoints() 
			  << ", Energy: " << scav2.getEnergyPoints() << std::endl;

	std::cout << "\n=== Testing ScavTrap Copy Constructor ===" << std::endl;
	ScavTrap scav3(scav1);

	std::cout << "\n=== Testing ScavTrap Assignment Operator ===" << std::endl;
	ScavTrap scav4("TempScav");
	scav4 = scav1;

	std::cout << "\n=== Testing Energy Depletion on ScavTrap ===" << std::endl;
	// Exhaust some energy
	for (int i = 0; i < 5; i++)
	{
		scav3.attack("Target");
	}
	scav3.guardGate();

	std::cout << "\n=== Testing Dead ScavTrap ===" << std::endl;
	scav2.takeDamage(100); // This should kill scav2
	scav2.attack("DeadTarget");
	scav2.guardGate();
	scav2.beRepaired(5);

	std::cout << "\n=== End of tests - Destructors will be called (showing destruction chaining) ===" << std::endl;
	return 0;
}

