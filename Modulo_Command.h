#ifndef MOD_CMD_H
#define MOD_CMD_H
#include "Expr_Command.h"


class Modulo_Command : public Expr_Command 
{
	public:
		Modulo_Command(Stack<int> &s);
		virtual void execute(void);
		
	private:
		Stack<int> &s_;
};
#endif
