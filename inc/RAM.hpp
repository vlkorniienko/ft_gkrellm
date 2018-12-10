/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAM.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 17:12:32 by aorji             #+#    #+#             */
/*   Updated: 2018/10/13 17:12:33 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAM_HPP
# define RAM_HPP

#include <string>
#include <iostream>

class RAM {
public:
	RAM( void );
	RAM( RAM const & src );
	~RAM( void );

	RAM & operator=( RAM const & rhs);
	std::string getRAM( void );

private:
	std::string _RAM;
};

#endif