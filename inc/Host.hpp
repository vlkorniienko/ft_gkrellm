/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Host.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 13:23:30 by aorji             #+#    #+#             */
/*   Updated: 2018/10/13 13:23:32 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOST_HPP
# define HOST_HPP

class Host {
public:
	Host( void );
	Host( Host const & src );
	~Host( void );

	Host & operator=( Host const & rhs);
	char * getHostName( void ) ;
	char * getUserName( void ) ;
	// void display( void );

private:
	char *_hostname;
	char *_username;
};

#endif