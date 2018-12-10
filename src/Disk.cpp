/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Disk.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 17:25:25 by aorji             #+#    #+#             */
/*   Updated: 2018/10/13 17:25:26 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gkrellm.hpp"

Disk::Disk( void ) {
	FILE *buf = popen("top -l 1| grep Disks", "r");
	char res[100];
	
	fgets(res, 100, buf);
	_Disk = static_cast<std::string>(res);

	pclose(buf);
}
Disk::Disk( Disk const & src) { *this = src; }
Disk::~Disk( void ) {}

Disk &
Disk::operator=( Disk const & rhs) {
	(void)rhs;
	return *this;
}

std::string
Disk::getDisk( void ) {
	FILE *buf = popen("top -l 1| grep Disks", "r");
	char res[100];
	
	fgets(res, 100, buf);
	_Disk = static_cast<std::string>(res);

	pclose(buf);
	return _Disk;
}