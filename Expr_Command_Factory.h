#ifndef EXPR_CMD_FCTRY
#define	EXPR_CMD_FCTRY

// Must include all the classes we are referencing 
#include "Number_Command.h"
#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Multiply_Command.h"
#include "Divide_Command.h"
#include "Modulo_Command.h"


class Expr_Command_Factory
{

	public:
		
		// List of virtual Command functions that must be implemented in the subclasses
		virtual Number_Command * create_number_command (int num) = 0; 
		virtual Add_Command * create_add_command (void) = 0;
		virtual Subtract_Command * create_subtract_command (void) = 0;
		virtual Multiply_Command * create_multiply_command (void) = 0;
		virtual Divide_Command * create_divide_command (void) = 0;
		virtual Modulo_Command * create_modulo_command (void) = 0;


};

#endif

