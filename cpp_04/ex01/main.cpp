#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

#include <iostream>

#define NUMBER_OF_ANIMALS 8

int	main( void )
{
	Animal	*animals[NUMBER_OF_ANIMALS];

	for (int i = 0; i < NUMBER_OF_ANIMALS; i++)
	{
		if (i < NUMBER_OF_ANIMALS / 2)
				animals[i] = new Dog();
		else
				animals[i] = new Cat();
		std::cout << animals[i]->getType() << std::endl;
	}

	for (int i = 0; i < NUMBER_OF_ANIMALS; i++)
		delete animals[i];

	std::cout << std::endl;
	
	Dog c;
	c.getBrain()->ideas[0] = "dog";
	Dog c_dst;
	c_dst.getBrain()->ideas[0] = "dstdog";
	c_dst = c;
	std::cout << c.getBrain()->ideas[0] << std::endl;
}
