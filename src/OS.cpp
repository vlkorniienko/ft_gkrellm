/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OS.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 14:10:21 by aorji             #+#    #+#             */
/*   Updated: 2018/10/13 14:10:23 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gkrellm.hpp"

OS::OS( void ) {}
OS::OS( OS const & src) { *this = src; }
OS::~OS( void ) {}

OS &
OS::operator=( OS const & rhs) {
	(void)rhs;
	return *this;
}

std::string
OS::getProductName( void ) {

	FILE *buf = popen("sw_vers -productName", "r");
	char res[100];
	fgets(res, 30, buf);
	pclose(buf);
	_productName = static_cast<std::string>(res);
	return _productName;
}

std::string
OS::getProductVersion( void ) {

	FILE *buf = popen("sw_vers -productVersion", "r");
	char res[100];
	fgets(res, 30, buf);
	pclose(buf);
	_productVersion = static_cast<std::string>(res);
	return _productVersion;
}

std::string
OS::getBuildVersion( void ) {

	FILE *buf = popen("sw_vers -buildVersion", "r");
	char res[100];
	fgets(res, 30, buf);
	pclose(buf);
	_buildVersion = static_cast<std::string>(res);
	return _buildVersion;
}