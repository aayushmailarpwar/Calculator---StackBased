#include "Number_Command.h"


Number_Command::Number_Command( Stack <int> &s, int n):
s_(s), n_(n)
{

}

void Number_Command::execute(void)
{
	
	s_.push(this->n_);
	
}

Number_Command::~Number_Command(void)
{

}
