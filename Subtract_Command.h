#ifndef SUB_CMD_H
#define SUB_CMD_H
#include "Expr_Command.h"


class Subtract_Command : public Expr_Command
{
	public:
		Subtract_Command(Stack<int> &s);
		virtual void execute(void);
		
	private:
		Stack<int> &s_;
};
#endif
