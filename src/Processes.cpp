/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Processes.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 17:32:36 by aorji             #+#    #+#             */
/*   Updated: 2018/10/13 17:32:37 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gkrellm.hpp"

Processes::Processes( void ) {
	FILE *buf = popen("top -l 1| grep Processes", "r");
	char res[100];
	
	fgets(res, 100, buf);
	_Processes = static_cast<std::string>(res);

	pclose(buf);
}
Processes::Processes( Processes const & src) { *this = src; }
Processes::~Processes( void ) {}

Processes &
Processes::operator=( Processes const & rhs) {
	(void)rhs;
	return *this;
}

std::string
Processes::getProcesses( void ) {
	FILE *buf = popen("top -l 1| grep Processes", "r");
	char res[100];
	
	fgets(res, 100, buf);
	_Processes = static_cast<std::string>(res);

	pclose(buf);
	return _Processes;
}
