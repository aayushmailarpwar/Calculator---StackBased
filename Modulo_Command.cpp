#include "Modulo_Command.h"

Modulo_Command::Modulo_Command(Stack<int> &s):
s_(s)
{

}


void Modulo_Command::execute(void)
{
	if(!s_.is_empty())
	{
		int n2 = s_.top();
		s_.pop();
		
		if (n2 == 0)
                {
                        throw std::invalid_argument("Modulo by zero");
                }
		
		
		if(!s_.is_empty())
		{	
  	 		int n1 = s_.top();
			s_.pop();
	        	s_.push(n1 % n2);
		}
		else
		{
			throw std::invalid_argument("Empty Stack");
		}			
			
		
	}
}

