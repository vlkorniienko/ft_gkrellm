/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPU.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 16:57:23 by aorji             #+#    #+#             */
/*   Updated: 2018/10/13 16:57:24 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPU_HPP
# define CPU_HPP

#include <string>
#include <iostream>

class CPU {
public:
	CPU( void );
	CPU( CPU const & src );
	~CPU( void );

	CPU & operator=( CPU const & rhs);
	std::string getCPU( void );
	int getUserPercentage( void );

private:
	std::string _CPU;
	int _userPercentage;
};

#endif