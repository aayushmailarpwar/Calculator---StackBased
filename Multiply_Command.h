#ifndef MUL_CMD_H
#define MUL_CMD_H
#include "Expr_Command.h"


class Multiply_Command : public Expr_Command
{
	public:
		Multiply_Command(Stack<int> &s);
		virtual void execute(void);
	private:
		Stack<int> &s_;
};
#endif
