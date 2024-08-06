/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 19:23:28 by aboukdid          #+#    #+#             */
/*   Updated: 2024/08/05 21:08:21 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int		last_contact;
	public:
		PhoneBook();
		void	add_contact(const Contact& name);
		void	searchcontact(Contact& name);
		void	add_to_the_contact(Contact& user);
};


#endif
