/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Time.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 15:19:59 by aorji             #+#    #+#             */
/*   Updated: 2018/10/13 15:20:00 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gkrellm.hpp"

Time::Time( void ) {}
Time::Time( Time const & src) { *this = src; }
Time::~Time( void ) {}

Time &
Time::operator=( Time const & rhs) {
	(void)rhs;
	return *this;
}

std::string
Time::getDate( void ) {
	time_t rawtime;
	struct tm * timeinfo;
	char curDate [11];

	time (&rawtime);
	timeinfo = localtime (&rawtime);

	strftime (curDate,11,"%d/%m/%Y",timeinfo);
	_date = static_cast<std::string>(curDate);
	return _date;
}
std::string
Time::getTime( void ) {
	time_t rawtime;
	struct tm * timeinfo;
	char curTime [9];

	time (&rawtime);
	timeinfo = localtime (&rawtime);

	strftime (curTime,9,"%H:%M:%S",timeinfo);
	_time = static_cast<std::string>(curTime);
	return _time;
}