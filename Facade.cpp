#include "Facade.h"

// Converting from infix to postfix using algorithm from the slides and adding to it too
bool Facade::infix_to_postfix(const std::string & infix, Stack_Expr_Command_Factory & factory, Array<Expr_Command*> & postfix)
{
	// Counter for the index of the postfix array
	int index = 0;

	// Input is all that is on the line
	std::istringstream input(infix);
	
	// The token can be an operator, operand or a parenthesis
	std::string token;

	// Flag must start with a number or parenthese
	// Therefore I have initialized the prev as 1
	int curr_flag = 0;
	int prev_flag = 1;
	
	Expr_Command *cmd = 0;
	Stack <Expr_Command *> temp;
	Stack <char> temp1;

	while(!input.eof())
	{
		
		// Start by assuming the token is not operator or operand
		// boolean required for precedence in the later half of the method
		bool isOperator = false;
		bool isOperand = false;
		bool par_start_found = false;
		bool par_end_found = false;

		// This token is for my second stack for parenthesis ops
		char token1;
		input >> token;

		// If a certain token is found, use the Stack Factory to
		// make the Expression Command, update the boolean and
		// assign token
		if(token == "+")
		{	
			cmd = factory.create_add_command();
			token1 = '+';			
			isOperator = true;
		}

		else if(token == "-")
                {
                        cmd = factory.create_subtract_command();
			token1 = '-';
			isOperator = true;
                }

		else if(token == "*")
                {
                        cmd = factory.create_multiply_command();
			token1 = '*';
			isOperator = true;
                }

		else if(token == "/")
                {
                        cmd = factory.create_divide_command();
			token1 = '/';
			isOperator = true;
                }

		else if(token == "%")
                {
                        cmd = factory.create_modulo_command();
			token1 = '%';
			isOperator = true;
                }	
		// If parenthesis found
		else if (token == "(")
		{
			par_start_found = true;
		}	

		else if (token == ")")
		{
			par_end_found = true;
		}

		else
		{
			int number = std::stoi(token);
			cmd = factory.create_number_command(number);
			isOperand = true;
		}

		
		// If the token is an operand, set the current flag and update prev
		// flag using the method
		// We must increment the Array size by 1 and set the last element with
		// the Operand	
		if(isOperand)
		{
			curr_flag = 2;
			prev_flag = validCheck(prev_flag,curr_flag);	
			postfix.resize(postfix.size() + 1);				
			postfix.set(index, cmd);
			index ++;
		}
		// If the token is an Operator, use our stack of tokens and add to it
		// according to the precedence function built in the class
		// Update the flag so it works for the next iteration
		else if ( isOperator)
		{
		
			curr_flag = 1;
			prev_flag = validCheck(prev_flag,curr_flag);
			while((!temp.is_empty()) && (op_precedence(token1) <= op_precedence(temp1.top())))
			{
				 postfix.resize(postfix.size() + 1);
				 postfix.set(index, temp.top());
				 index++;
				 temp.pop();
				 temp1.pop();
         		               
			}

			temp.push(cmd);
			temp1.push(token1);
				
		}
		// Push the opening parenthesis
		else if (par_start_found)
	 	{
			
			curr_flag = 3;
			prev_flag = validCheck(prev_flag, curr_flag);
			temp1.push('(');
		}	
		// If end parenthesis is found, then keep taking the top off
		// till you find the opening parenthesis
		else if (par_end_found)
		{
				
			curr_flag = 4;
			prev_flag = validCheck(prev_flag,curr_flag);
			while (temp1.top() != '(')
			{
				// Keep adding to our Array of Commands
				postfix.resize(postfix.size() + 1);
                                postfix.set(index, temp.top());
                       		temp1.pop();                 
				temp.pop();
                                index ++;
			}
			// Pop and top till opening parenthesis
			if (temp1.top() != '(')
			{
				temp.pop();
			}

			temp1.pop();
		}

		
	}

	// At the end of operator list we keep popping and setting the top
	// to the Array of Commands
	while(!temp.is_empty())
	{
		postfix.resize(postfix.size() + 1);
		postfix.set(index, temp.top());
		index++;
	
		temp.pop();
		temp1.pop();
			
	}	           
             
	
	return true;
}

// Valid check allows prev and curr flag to see if expression is valid
// eg. two numbers together is not valid
int Facade::validCheck(int prev_flag, int curr_flag)
{
	// Switch case with flags 1,2,3,4,
	// 1 is operator
	// 2 is number
	// 3 is (
	// 4 is )
	switch(curr_flag)
	{
		case 1:
			if(prev_flag == 1 || prev_flag == 3)
			{
				throw std::invalid_argument(" Cannot have operator or ( before current operator");
			}
		break;

		case 2:
			if(prev_flag == 4 || prev_flag == 2)
                        {
                                throw std::invalid_argument(" Cannot have number or ) before current number");
                        }

		break;

		case 3:
			if(prev_flag == 4 || prev_flag == 2)
                        {
                                throw std::invalid_argument(" Cannot have operator or ( before current (");
                        }


		break;

		case 4:
			if(prev_flag == 1 || prev_flag == 3)
                        {
                                throw std::invalid_argument(" Cannot have operator or ( before current )");
                        }

		break;

		default:
	
		break;
	}

	return curr_flag;
}

// COMMENT: You should implement the precedence function on
// the command object since it is better place there.

// RESPONSE: I implemented two stacks and checked the stack input
// to go about precedence
int Facade::op_precedence(char token)
{
	// * / and % have the same precedence only from left to right
	if( token == '*' || token == '/' || token == '%')
	{
		// assign higher precendence
		return 2;
	}
	// + and - have the same precendence too
	else if ( token == '+' || token == '-')
	{
		return 1;
	}
	// this will never be called
	else
	{
		return 0;
	}
}

