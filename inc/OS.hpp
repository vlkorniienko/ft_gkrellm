/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OS.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 14:10:26 by aorji             #+#    #+#             */
/*   Updated: 2018/10/13 14:10:27 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef OS_HPP
# define OS_HPP

#include <string>
#include <iostream>

class OS {
public:
	OS( void );
	OS( OS const & src );
	~OS( void );

	OS & operator=( OS const & rhs);
	std::string getProductName( void );
	std::string getProductVersion( void );
	std::string getBuildVersion( void );

private:
	std::string _productName;
	std::string _productVersion;
	std::string _buildVersion;
};

#endif