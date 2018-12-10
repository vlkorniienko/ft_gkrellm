/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 11:59:24 by aorji             #+#    #+#             */
/*   Updated: 2018/10/14 11:59:25 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITOR_DISPLAY_HPP
# define IMONITOR_DISPLAY_HPP

#include <ncurses.h>
#include <unistd.h>
#include "Window.hpp"
#include "CPU.hpp"
#include "Host.hpp"
#include "OS.hpp"
// #include "Time.hpp"
// #include "Network.hpp"
// #include "RAM.hpp"
#include "Disk.hpp"
// #include "Processes.hpp"

class IMonitorDisplay {
public:
	virtual ~IMonitorDisplay() {}
	virtual void displayHost( Host & host ) const = 0;
	virtual void displayCPU( CPU & cpu ) const = 0;
	virtual void displayDisk( Disk & disk ) const = 0;
	virtual void displayOS( OS & os ) const = 0;
	// virtual void displayProcesses( Processes & pr ) const = 0;
	// virtual void displayRam( RAM & ram ) const = 0;
	// virtual void displayTime( Time & time ) const = 0;
	// virtual void displayNetwork( Network & nw ) const = 0;
};

#endif