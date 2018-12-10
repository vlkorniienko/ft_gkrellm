/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPU.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 16:57:19 by aorji             #+#    #+#             */
/*   Updated: 2018/10/13 16:57:20 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gkrellm.hpp"

CPU::CPU( void ) {
	FILE *buf = popen("top -l 1| grep 'CPU usage'", "r");
	char res[100];
	
	fgets(res, 100, buf);
	_CPU = static_cast<std::string>(res);

	pclose(buf);
}
CPU::CPU( CPU const & src) { *this = src; }
CPU::~CPU( void ) {}

CPU &
CPU::operator=( CPU const & rhs) {
	(void)rhs;
	return *this;
}

std::string
CPU::getCPU( void ) {
	FILE *buf = popen("top -l 1| grep 'CPU usage'", "r");
	char res[100];
	
	fgets(res, 100, buf);
	_CPU = static_cast<std::string>(res);
	_userPercentage = atoi(_CPU.substr(10, 3).c_str());
	pclose(buf);
	return _CPU;
}

int
CPU::getUserPercentage( void ) {
	return _userPercentage;
}