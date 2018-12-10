/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Time.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 15:20:04 by aorji             #+#    #+#             */
/*   Updated: 2018/10/13 15:20:05 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TIME_HPP
# define TIME_HPP

#include <string>
#include <iostream>

class Time {
public:
	Time( void );
	Time( Time const & src );
	~Time( void );

	Time & operator=( Time const & rhs);
	std::string getDate( void );
	std::string getTime( void );

private:
	std::string _date;
	std::string _time;
};

#endif