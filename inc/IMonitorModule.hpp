/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 18:47:30 by aorji             #+#    #+#             */
/*   Updated: 2018/10/14 18:47:31 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITOR_Module_HPP
# define IMONITOR_Module_HPP

#include "Time.hpp"
#include "Network.hpp"
#include "RAM.hpp"
#include "Processes.hpp"

class IMonitorModule {
public:
	virtual ~IMonitorModule() {}
	virtual void displayProcesses( Processes & pr ) const = 0;
	virtual void displayRam( RAM & ram ) const = 0;
	virtual void displayTime( Time & time ) const = 0;
	virtual void displayNetwork( Network & nw ) const = 0;
};
#endif
