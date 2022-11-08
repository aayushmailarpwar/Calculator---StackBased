#include "Subtract_Command.h"

Subtract_Command::Subtract_Command(Stack<int> &s):
s_(s)
{

}


void Subtract_Command::execute(void)
{
	// COMMENT You have implemented exception transparency here. If the stack
    	// is empty, then this would be bad for the evaluator at this point. Continuing
    	// to process the post fix expression would yield incorrect results. Find
    	// a better way to handle this concern.
	
	// RESPONSE I addeded an invalid_argument exception to fix incase the stack is empty
	
	if(!s_.is_empty())
	{
		int n2 = s_.top();
		s_.pop();
		if(!s_.is_empty())
		{	
  	 	int n1 = s_.top();
		s_.pop();
	        s_.push(n1 - n2);
		}
		else
		{
			throw std::invalid_argument("Empty Stack");
		}
	}
}
