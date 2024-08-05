#ifndef HARL_H_
#define HARL_H_

#include <iostream>

class Harl
{
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
		enum Level {
			DEBUG,
			INFO,
			WARNING,
			ERROR,
			UNKNOWN
		};
		typedef void (Harl::*Ptrs)();
	public:
		void harlFilter( std::string level );		
};
#endif