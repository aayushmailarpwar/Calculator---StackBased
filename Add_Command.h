#ifndef ADD_CMD_H
#define ADD_CMD_H
#include "Expr_Command.h"


class Add_Command : public Expr_Command 
{
	public:
		Add_Command(Stack<int> &s);

		virtual void execute(void);
	private:
		Stack<int> &s_;
		
};
#endif
