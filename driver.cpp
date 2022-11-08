#include <iostream>
#include <string>
#include <sstream>
#include "Facade.h"
#include "Stack_Expr_Command_Factory.h"
#include "Array.h"
#include "Expr_Command.h"


// COMMENT: Instead of using C functions to implement parts of the
// calculator. It would be better suited to use a Wrapper Facade.

// RESPONSE: I added a Facade class that does everything without 
// allowing the client to access each data member


int main()
{
	Facade calculator;
	bool continue_ = true;
	Stack <int> result;

	// This will be the main stack for computation
	Stack_Expr_Command_Factory factory(result);
	
	std::string infix;	
	
	// Loop that goes through each line aiming to recieive the line as a whole
        while(continue_)
	{
		
		std::getline(std::cin, infix);

		// Logic for the input validation
		if(infix == "QUIT")
		{
			continue_ = false;
			break;
		}
		
		// Postfix array of the type Expr_Command
		Array<Expr_Command *> postfix;
		
		// If the infix input is not empty
		if(infix != "")
		{
			// Try catch to prevent the program from breaking incase any invalid expression is found
	        	try
			{
				calculator.infix_to_postfix (infix, factory, postfix);
		
				// Using this instead of Array Iterator
                                for(int i = 0; i < postfix.size();i++)
                                {
                                        postfix[i]->execute();
                                }

				int res = result.top();
		                std::cout <<" Answer is: " <<res <<std::endl;


			}
			// Catch all involves all types of errors like divide by zero, out-of-range, wrong format
			catch(const std::exception& e)
			{
				
				std::cout << e.what()<<" : Invalid Input" <<std::endl;
			}

		}

		// Else skip
		else
		{
			std::cout << "Empty Input Detected" <<std::endl;
		}
		
	}
}

