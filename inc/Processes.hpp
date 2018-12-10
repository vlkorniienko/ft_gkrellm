/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Processes.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 17:32:40 by aorji             #+#    #+#             */
/*   Updated: 2018/10/13 17:32:41 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Processes_HPP
# define Processes_HPP

class Processes {
public:
	Processes( void );
	Processes( Processes const & src );
	~Processes( void );

	Processes & operator=( Processes const & rhs);
	std::string getProcesses( void );

private:
	std::string _Processes;
};

#endif