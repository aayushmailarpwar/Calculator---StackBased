#include "Stack_Expr_Command_Factory.h"

// Constructor
Stack_Expr_Command_Factory::Stack_Expr_Command_Factory(Stack <int> & stack):
stack_(stack)
{

}
// All Commands that are possible
Number_Command* Stack_Expr_Command_Factory::create_number_command( int num)
{
	return new Number_Command( this->stack_, num);
}

Add_Command* Stack_Expr_Command_Factory::create_add_command()
{
        return new Add_Command(this->stack_);
}


Subtract_Command* Stack_Expr_Command_Factory::create_subtract_command(void)
{
        return new Subtract_Command(stack_);
}

Multiply_Command* Stack_Expr_Command_Factory::create_multiply_command(void)
{
        return new Multiply_Command(stack_);
}

Divide_Command* Stack_Expr_Command_Factory::create_divide_command(void)
{
        return new Divide_Command(stack_);
}

Modulo_Command* Stack_Expr_Command_Factory::create_modulo_command(void)
{
        return new Modulo_Command(stack_);
}
