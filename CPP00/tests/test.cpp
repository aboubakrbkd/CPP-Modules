/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:12:23 by aboukdid          #+#    #+#             */
/*   Updated: 2024/08/05 17:47:36 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <ios>
#include <iostream>
using namespace std;
 
int main()
{
 
    // Initializing the integer
    int num = 50;
 
    cout << "Before setting the width: \n" << num << endl;
 
    // Using setw()
    cout << "Setting the width"
         << " using setw to 5: \n"
         << setw(50);
 
    cout << num;
 
    return 0;
}