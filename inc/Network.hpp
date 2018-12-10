/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Network.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 16:38:33 by aorji             #+#    #+#             */
/*   Updated: 2018/10/13 16:38:34 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWORK_HPP
# define NETWORK_HPP

class Network {
public:
	Network( void );
	Network( Network const & src );
	~Network( void );

	Network & operator=( Network const & rhs);
	std::string getNetwork( void );

private:
	std::string _network;
};

#endif