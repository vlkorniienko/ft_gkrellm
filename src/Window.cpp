/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 18:19:30 by aorji             #+#    #+#             */
/*   Updated: 2018/10/13 18:19:31 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_gkrellm.hpp"

Window::Window()
{
	initscr();
	getmaxyx(stdscr, _winY, _winX);

	if (_winX < 121 || _winY < 53) {
		endwin();
		throw Window::ScreenException();
	}

	_hostWindow = newwin(_winY/4, _winX/3.2, 0, 0);
	_osWindowwnd = newwin(_winY/4, _winX/3.2, 0, _winX/3.2 + 2);
	_timeWindow = newwin(_winY/4, _winX/3.2, 0, (_winX/3.2 * 2) + 4);
	
	_netWorkWindow = newwin(_winY/4, _winX/2.1, _winY/4 + 1, 0);
	_ramWindow = newwin(_winY/4, _winX/2.1, _winY/4 + 1, _winX/2.1 + 2);


	_diskWindow = newwin(_winY/4, _winX/2.1, (_winY/4 * 2) + 2, 0);
	_cpuWingow = newwin(_winY/4, _winX/2.1, (_winY/4 * 2) + 2, _winX/2.1 + 2);
	
	_procWindow = newwin(_winY/8, _winX/2.1 * 2 + 2 , (_winY/4 * 3) + 3, 0);
	_wnd = newwin(_winY, _winX, 0, 0);
	cbreak();
	noecho();
	clear();
	refresh();
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_YELLOW);
	init_pair(3, COLOR_BLACK, COLOR_BLACK);

	keypad(_wnd, true);
	nodelay(_wnd, true);
	curs_set(0);

	keypad(_hostWindow, true);
	nodelay(_hostWindow, true);
	curs_set(0);

	keypad(_cpuWingow, true);
	nodelay(_cpuWingow, true);
	curs_set(0);

	keypad(_diskWindow, true);
	nodelay(_diskWindow, true);
	curs_set(0);

	keypad(_osWindowwnd, true);
	nodelay(_osWindowwnd, true);
	curs_set(0);

	keypad(_procWindow, true);
	nodelay(_procWindow, true);
	curs_set(0);

	keypad(_ramWindow, true);
	nodelay(_ramWindow, true);
	curs_set(0);;

	keypad(_timeWindow, true);
	nodelay(_timeWindow, true);
	curs_set(0);

	keypad(_netWorkWindow, true);
	nodelay(_netWorkWindow, true);
	curs_set(0);
}

Window::~Window() {	endwin(); std::cout << "Window cleaned" << std::endl; }
Window::Window(const Window &rhs) {
	*this = rhs;
}

Window &Window::operator=(const Window &rhs) {
	(void)rhs;
	return *this;
}

void
Window::run() {

    Host host;
   	OS osData;
	Time time;
	Network nw;
	CPU	cpu;
	RAM ram;
	Disk disc;
	Processes pr;
	int i = 0;
	while (i != KEY_DOWN){
		i = wgetch(_wnd);
		wbkgd(_wnd, COLOR_PAIR(1));

		mvwprintw(_wnd, _winY/4, _winX/4,"  ______   __    __                      __  __  __       __ ");
		mvwprintw(_wnd, _winY/4 + 1, _winX/4," /      \\ |  \\  /  \\                    |  \\|  \\|  \\     /  ");
		mvwprintw(_wnd, _winY/4 + 2, _winX/4,"|  $$$$$$\\| $$ /  $$  ______    ______  | $$| $$| $$\\   /  $$");
		mvwprintw(_wnd, _winY/4 + 3, _winX/4,"| $$ __\\$$| $$/  $$  /      \\  /      \\ | $$| $$| $$$\\ /  $$$");
		mvwprintw(_wnd, _winY/4 + 4, _winX/4,"| $$|    \\| $$  $$  |  $$$$$$\\|  $$$$$$\\| $$| $$| $$$$\\  $$$$");
		mvwprintw(_wnd, _winY/4 + 5, _winX/4,"| $$ \\$$$$| $$$$$\\  | $$   \\$$| $$    $$| $$| $$| $$\\$$ $$ $$");
		mvwprintw(_wnd, _winY/4 + 6, _winX/4,"| $$__| $$| $$ \\$$\\ | $$      | $$$$$$$$| $$| $$| $$ \\$$$| $$");
		mvwprintw(_wnd, _winY/4 + 7, _winX/4," \\$$    $$| $$  \\$$\\| $$       \\$$     \\| $$| $$| $$  \\$ | $$");
		mvwprintw(_wnd, _winY/4 + 8, _winX/4,"  \\$$$$$$  \\$$   \\$$ \\$$        \\$$$$$$$ \\$$ \\$$ \\$$      \\$$");

		mvwprintw(_wnd, _winY/4 + 11, _winX/3," KEY_DOWN -> Start ");
		box(_wnd, 0, 0);
		wrefresh(_wnd);
	}
		wclear(_wnd);
    
    wrefresh(_wnd);
    while (1) {
		if (wgetch(_hostWindow)  == ESC )
			break;
		if (wgetch(_cpuWingow)  == ESC )
			break;
		if (wgetch(_diskWindow)  == ESC )
			break;
		if (wgetch(_osWindowwnd)  == ESC )
			break;
		if (wgetch(_procWindow)  == ESC )
			break;
		if (wgetch(_ramWindow)  == ESC )
			break;
		if (wgetch(_timeWindow)  == ESC )
			break;
		if (wgetch(_netWorkWindow) == ESC )
			break;

		displayHost( host );
		displayCPU( cpu );
		displayDisk( disc );
		displayOS( osData );
		displayProcesses ( pr );
		displayRam( ram );
		displayTime( time );
		displayNetwork( nw );
		attroff(A_BOLD);
		refresh();
	}
}

void
Window::displayHost( Host & host ) const {

    wbkgd(_hostWindow, COLOR_PAIR(1));
	mvwprintw(_hostWindow, 2, 4,"Host: %s", host.getHostName());
	mvwprintw(_hostWindow, 3, 4,"User: %s", host.getUserName());
	box(_hostWindow, 0, 0);
}
void
Window::displayCPU( CPU & cpu ) const {

	int x, y;
	getmaxyx(stdscr, y, x);

	std::string cp = cpu.getCPU();
	int len = cpu.getUserPercentage() / 2;

	if (len >= x)
		len = x - 1;

	std::string load (len, ' ');
	std::string clean (x-1, ' ');

	wbkgd(_cpuWingow, COLOR_PAIR(1));
	mvwprintw(_cpuWingow, 2, 5, "%s", cp.c_str());

	wattron(_cpuWingow, COLOR_PAIR(3));
	mvwprintw(_cpuWingow, 6, 5,"%s", clean.c_str());
	wattroff(_cpuWingow, COLOR_PAIR(3));

	wattron(_cpuWingow, COLOR_PAIR(2));
	mvwprintw(_cpuWingow, 6, 5,"%s", load.c_str());
	wattroff(_cpuWingow, COLOR_PAIR(2));

	box(_cpuWingow, 0, 0);
}
void
Window::displayDisk( Disk & disk ) const {
	wbkgd(_diskWindow, COLOR_PAIR(1));
	mvwprintw(_diskWindow, 2, 5, "%s", disk.getDisk().c_str());
	box(_diskWindow, 0, 0);
}
void
Window::displayOS( OS & os ) const {
	wbkgd(_osWindowwnd, COLOR_PAIR(1));
	mvwprintw(_osWindowwnd, 2, 4, "ProductName: %s", os.getProductName().c_str());
	mvwprintw(_osWindowwnd, 3, 4, "ProductVersion: %s", os.getProductVersion().c_str());
	mvwprintw(_osWindowwnd, 4, 4, "BuildVersion: %s", os.getBuildVersion().c_str());
	mvwprintw(_osWindowwnd, 5, 6, "	         ..");
	mvwprintw(_osWindowwnd, 6, 6, "      __ :'__");
	mvwprintw(_osWindowwnd, 7, 6, "   .'`__`-'__``.");
	mvwprintw(_osWindowwnd, 8, 6, "  :__________.-'");
	mvwprintw(_osWindowwnd, 9, 6, "  :_________:");
	mvwprintw(_osWindowwnd, 10, 6, "   :_________`-");
	mvwprintw(_osWindowwnd, 11, 6, "    `.__.-.__.'");
	box(_osWindowwnd, 0, 0);
}
void
Window::displayProcesses( Processes & pr ) const {
	wbkgd(_procWindow, COLOR_PAIR(1));
	mvwprintw(_procWindow, 2, 4, "%s", pr.getProcesses().c_str());
	box(_procWindow, 0, 0);
}
void
Window::displayRam( RAM & ram ) const {
	wbkgd(_ramWindow, COLOR_PAIR(1));
	mvwprintw(_ramWindow, 2, 4, "%s", ram.getRAM().c_str());
	box(_ramWindow, 0, 0);
}
void
Window::displayTime( Time & time ) const {
	wbkgd(_timeWindow, COLOR_PAIR(1));
	mvwprintw(_timeWindow, 2, 4, "Date: %s", time.getDate().c_str());
	mvwprintw(_timeWindow, 3, 4, "Time: %s", time.getTime().c_str());
	box(_timeWindow, 0, 0);
}
void
Window::displayNetwork( Network & nw ) const {
	wbkgd(_netWorkWindow, COLOR_PAIR(1));
	mvwprintw(_netWorkWindow, 2, 4, "%s", nw.getNetwork().c_str());
	box(_netWorkWindow, 0, 0);
}

Window::
ScreenException::ScreenException ( void ) {}

Window::
ScreenException::ScreenException ( Window::ScreenException const & src ) {
	*this = src;
}

Window::
ScreenException::~ScreenException ( void ) throw() {}

Window::ScreenException & 
Window::ScreenException::operator=( Window::ScreenException const & rhs) {
	(void)rhs;
	return *this;
}

const char *
Window::ScreenException::what() const throw()
{
    return ("Screen is too small!\n");
}

