#ifndef STACK_EXPR_CMD_FCTRY
#define STACK_EXPR_CMD_FCTRY
#include "Expr_Command_Factory.h"
#include "Stack.h"

class Stack_Expr_Command_Factory: public Expr_Command_Factory
{
	public:
		Stack_Expr_Command_Factory (Stack <int> & stack); 

		virtual Number_Command * create_number_command (int num);

		virtual Add_Command * create_add_command ();

		virtual Subtract_Command * create_subtract_command (void);
			
		virtual Multiply_Command * create_multiply_command (void);
		
		virtual Divide_Command * create_divide_command (void);
		
		virtual Modulo_Command * create_modulo_command (void);


	private:
		Stack <int> & stack_;
};
#endif
