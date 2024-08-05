/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 19:23:22 by aboukdid          #+#    #+#             */
/*   Updated: 2024/08/05 16:49:09 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP

# define CONTACT_HPP

# include <iostream>
# include "PhoneBook.hpp"

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
	public:
		void	set_first_name(const std::string& name);
		void	set_last_name(const std::string& name);
		void	set_nickname(const std::string& name);
		void	set_phone_number(const std::string& name);
		void	set_darkest_secret(const std::string& name);
		~Contact();
};

Contact::~Contact()
{
	std::cout<< "Amine zamal" << std::endl;
}


#endif