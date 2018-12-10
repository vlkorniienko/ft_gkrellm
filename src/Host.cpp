/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Host.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 13:23:26 by aorji             #+#    #+#             */
/*   Updated: 2018/10/13 13:23:27 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gkrellm.hpp"

Host::Host( void ) {}
Host::Host( Host const & src) { *this = src; }
Host::~Host( void ) { delete _hostname; delete _username; }

Host &
Host::operator=( Host const & rhs) {
	(void)rhs;
	return *this;
}

char *
Host::getHostName( void )  {
	_hostname = new char[20];
	gethostname(_hostname, 20);
	return _hostname;
}

char *
Host::getUserName( void )  {
	_username = new char[20];
	getlogin_r(_username, 20);
	return _username;
}

