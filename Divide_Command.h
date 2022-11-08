#ifndef DIV_CMD_H
#define DIV_CMD_H
//#include "Binary_Op_Command.h"
#include "Expr_Command.h"


class Divide_Command : public Expr_Command //Binary_Op_Command
{
	public:
		Divide_Command(Stack<int> &s);

//		int evaluate (int n1, int n2);
		virtual void execute(void);

//		~Divide_Command(void);
	private:
		Stack<int> &s_;
};
#endif
