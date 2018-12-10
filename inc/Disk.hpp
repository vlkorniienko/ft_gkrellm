/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Disk.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 17:25:28 by aorji             #+#    #+#             */
/*   Updated: 2018/10/13 17:25:29 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISk_HPP
# define DISk_HPP
#include <string>
#include <iostream>

class Disk {
public:
	Disk( void );
	Disk( Disk const & src );
	~Disk( void );

	Disk & operator=( Disk const & rhs);
	std::string getDisk( void );

private:
	std::string _Disk;
};

#endif