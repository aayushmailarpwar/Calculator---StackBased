/*#ifndef BIN_OP_CMD_H
#define BIN_OP_CMD_H
#include "Expr_Command.h"
#include "Stack.h"

class Binary_Op_Command : public Expr_Command
{
	protected:
		Binary_Op_Command (Stack <int> &s);

	public: 

		void execute(void);
		virtual int evaluate (int n1, int n2) const = 0;

	private:
		Stack<int> &s_;
		
};

#endif*/
