/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rubrica.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:35:45 by lbusi             #+#    #+#             */
/*   Updated: 2023/05/29 18:30:42 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.hpp"

void	print(PhoneBook phonebook)
{
	int j = 0;
	while (j < phonebook.i)
	{
		std::cout << j << " | ";
		std::cout << phonebook._contact[j].get_first_name() << "| ";
		std::cout << phonebook._contact[j].get_last_name() << "| ";
		std::cout << phonebook._contact[j].get_nickname() << std::endl;
		j++;
	}
}

int	main(int argc, char **argv)
{
	PhoneBook phonebook;

	phonebook.i = 0;
	while (1)
	{
		std::string command;
		
		std::cin >> command;
		if (command == "ADD")
		{
		phonebook._contact[phonebook.i].set_first_name();
		phonebook._contact[phonebook.i].set_last_name();
		phonebook._contact[phonebook.i].set_nickname();
		phonebook._contact[phonebook.i].set_phone_number();
		phonebook._contact[phonebook.i].set_darkest_secret();
		phonebook.i++;
		if (phonebook.i == 9)
			phonebook.i = 0;
		}
		if (command == "SEARCH")
		{
			print(phonebook);
		}
		else if (command == "EXIT")
			exit(0);
	}
}