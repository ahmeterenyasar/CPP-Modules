#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main()
{
    IMateriaSource* src = new MateriaSource();
    AMateria* ice_template = new Ice();
    AMateria* cure_template = new Cure();
    src->learnMateria(ice_template);
    src->learnMateria(cure_template);
    delete ice_template; // Clean up the templates after learning
    delete cure_template;

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;

    std::cout << std::endl << "=== Additional ===" << std::endl;

    // Test copy constructor and assignment operator
    Character* john = new Character("john");
    john->equip(new Ice());
    john->equip(new Cure());

    Character* copy = new Character(*john);
    std::cout << "Copy's name: " << copy->getName() << std::endl;

    Character* assigned = new Character("temp");
    *assigned = *john;
    std::cout << "Assigned's name: " << assigned->getName() << std::endl;

    ICharacter* target = new Character("target");
    copy->use(0, *target);
    assigned->use(1, *target);

    // Test unequip - demonstrate that unequip doesn't delete the materia
    AMateria* ice_for_unequip = new Ice();
    john->equip(ice_for_unequip);
    john->unequip(2); // The ice materia is now unequipped but not deleted
    delete ice_for_unequip; // We need to manually delete the unequipped materia

    // Test invalid operations
    john->use(10, *target); // Invalid index
    john->unequip(-1); // Invalid index

    delete target;
    delete assigned;
    delete copy;
    delete john;

    return 0;
}
