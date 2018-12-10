/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 18:19:34 by aorji             #+#    #+#             */
/*   Updated: 2018/10/13 18:19:35 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_HPP
#define WINDOW_HPP

const int ESC = 27;

#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"

class Window: public IMonitorDisplay, public IMonitorModule{

public:
	Window();
	Window(const Window &rhs);
	~Window();
	Window &operator=(const Window &rhs);
	
	void run( void );

	class ScreenException: public std::exception {
	public:
		ScreenException( void );
		ScreenException( ScreenException const & src );
		~ScreenException( void ) throw();
		ScreenException & operator=( ScreenException const & rhs);
		virtual const char* what() const throw();
	};

	void displayHost( Host & host ) const;
	void displayCPU( CPU & cpu ) const;
	void displayDisk( Disk & disk ) const;
	void displayOS( OS & os ) const;
	void displayProcesses( Processes & pr ) const;
	void displayRam( RAM & ram ) const;
	void displayTime( Time & time ) const;
	void displayNetwork( Network & nw ) const;

protected:
	WINDOW *_hostWindow;
	WINDOW *_cpuWingow;
	WINDOW *_diskWindow;
	WINDOW *_osWindowwnd;
	WINDOW *_procWindow;
	WINDOW *_ramWindow;
	WINDOW *_timeWindow;
	WINDOW *_netWorkWindow;
	WINDOW *_wnd;
	
	int _winY;
	int _winX;
};

#endif
