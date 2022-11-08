#ifndef FACADE_H
#define FACADE_H


#include <iostream>
#include <string>
#include <sstream>
#include "Stack.h"
#include "Array.h"
#include "Array_Iterator.h"
#include "Stack_Expr_Command_Factory.h"
#include "Expr_Command_Factory.h"
#include "Expr_Command.h"

class Facade
{
	public:

		int op_precedence(char token);

		bool infix_to_postfix(const std::string & infix, Stack_Expr_Command_Factory & factory, Array<Expr_Command*> & postfix);

		int validCheck(int prev_flag, int curr_flag);

	

};
#endif
