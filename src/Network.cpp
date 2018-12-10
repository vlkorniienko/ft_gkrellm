/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Network.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 16:38:28 by aorji             #+#    #+#             */
/*   Updated: 2018/10/13 16:38:29 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gkrellm.hpp"

Network::Network( void ) {
	FILE *buf = popen("top -l 1| grep Network", "r");
	char res[100];
	
	fgets(res, 100, buf);
	_network = static_cast<std::string>(res);

	pclose(buf);
}
Network::Network( Network const & src) { *this = src; }
Network::~Network( void ) {}

Network &
Network::operator=( Network const & rhs) {
	(void)rhs;
	return *this;
}

std::string
Network::getNetwork( void ) {
	FILE *buf = popen("top -l 1| grep Network", "r");
	char res[100];
	
	fgets(res, 100, buf);
	_network = static_cast<std::string>(res);

	pclose(buf);

	return _network;
}