// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.


// Stack Constructor
template <typename T>
Stack <T>::Stack (void)
{
		
}


// Copy Constructor
template <typename T>
Stack <T>::Stack (const Stack & stack):
  stack_Array(stack.stack_Array)
  // COMMENT You are initializing the data member incorrectly.

  // RESPONSE Using BMI instead of equating them in the constructor
{

}


// Destructor
template <typename T>
Stack <T>::~Stack (void)
{

}


// Push method
template <typename T>
void Stack <T>::push (T element)
{
	// Adding a position for the new pushed element
	// Setting the element to the appropriate index	
	stack_Array.resize(stack_Array.size() + 1);
	stack_Array.set(stack_Array.size() - 1 , element);

}



// Pop method
template <typename T>
void Stack <T>::pop (void)
{
	// If stack is empty
	if(stack_Array.size() == 0)
		{
		
			throw empty_exception();
		}

	// Resize down
	else
		{
			stack_Array.resize(stack_Array.size() - 1);
            
            		// COMMENT There is no need to shrink the array after each
		        // pop. If you want to allow clients to reclaim unused space,
		        // you should expose a method that calls the shrink () method.

            		// RESPONSE Removed the shrink method and understood the logic
            		//          the removal
	    			
		}
	
}


// operator =
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
 	// COMMENT Always check for self-assignment first before continuing.

 	// RESPONSE Inserted a check for self-assignment below
 
 	if(&this->stack_Array == &rhs.stack_Array)
		{
			return *this;		
		}		
	
	// Else equate rhs to lhs
	this->stack_Array = rhs.stack_Array;

	return *this;

}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
	stack_Array.resize(0);
    
        // COMMENT There is no need to shrink the array since you
        // will just request the space later. If you want to shrink
        // the array, then you should expose a shrink() method on the
        // Stack, which delegates its call to the array.

        // RESPONSE	I removed the shrink method since I understood why
        // it is not needed
	
}
