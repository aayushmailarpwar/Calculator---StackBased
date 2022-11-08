#ifndef EXPR_CMD_H
#define EXPR_CMD_H

#include "Stack.h"

class Expr_Command
{
	public:
		
		virtual void execute (void) = 0;
};
#endif
