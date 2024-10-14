/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:19:44 by aboukdid          #+#    #+#             */
/*   Updated: 2024/10/14 19:56:46 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include "Brain.hpp"

int main()
{
	const int size = 8;
	Animal* animal[size];

	for (int i =0; i < size / 2; i++)
		animal[i] = new Dog();
	for (int i = size / 2; i < size; i++)
		animal[i] = new Cat();
	for (int i = 0; i < size; i++)
		animal[i]->makeSound();
	for (int i = 0; i < size; i++)
		delete animal[i];
}