#ifndef NUM_CMD_H
#define NUM_CMD_H

#include "Expr_Command.h"

class Number_Command: public Expr_Command
{
	public:
		
		Number_Command(Stack <int> &s , int n);

	 	virtual void execute (void);

		~Number_Command(void);
	
	private:
		Stack <int> & s_;
		int n_;

};
#endif

