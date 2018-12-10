/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAM.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 17:07:22 by aorji             #+#    #+#             */
/*   Updated: 2018/10/13 17:07:24 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gkrellm.hpp"

RAM::RAM( void ) {
	FILE *buf = popen("top -l 1| grep PhysMem", "r");
	char res[100];
	
	fgets(res, 100, buf);
	_RAM = static_cast<std::string>(res);

	pclose(buf);
}
RAM::RAM( RAM const & src) { *this = src; }
RAM::~RAM( void ) {}

RAM &
RAM::operator=( RAM const & rhs) {
	(void)rhs;
	return *this;
}

std::string
RAM::getRAM( void ) {
	FILE *buf = popen("top -l 1| grep PhysMem", "r");
	char res[100];
	
	fgets(res, 100, buf);
	_RAM = static_cast<std::string>(res);

	pclose(buf);
	return _RAM;
}