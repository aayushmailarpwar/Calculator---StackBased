// $Id: Array_Base_Base.cpp 820 2011-01-17 15:30:41Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array_Base.h"
#include <iostream>
#include <stdexcept>

#define def_size 0

// Default Constructor
template <typename T>
Array_Base<T>::Array_Base (void):
  data_(new T[def_size]),
  cur_size_(def_size),
  max_size_(def_size)
{

}


// Initializing Constructor
template <typename T>
Array_Base<T>::Array_Base (size_t length):
  cur_size_ (length),
  max_size_(length),
  data_(new T [length])
{
	
}


// Initializing Constructor using the fill method 
template <typename T>
Array_Base<T>::Array_Base (size_t length, T fill):
  cur_size_(length),
  max_size_(length),
  data_(new T[length])
{
	this->fill(fill);	 
}


// Copy constructor
template <typename T>
Array_Base<T>::Array_Base (const Array_Base & array):
  cur_size_(array.cur_size_),
  max_size_(array.max_size_),
  data_(new T [array.max_size_])

{	
	// Creating pointers to new Array_Base and copied Array_Base
	// and then copying over data from one to other
	 T *ptr1 = this->data_;
	 T *ptr2 = array.data_;

	 for(int i = 0; i < array.cur_size_; i++)
		{
			*ptr1 = *ptr2;
			ptr1++;
			ptr2++;
		}		
}

// Destructor for Deleting Array_Base instances when they go out of scope
template <typename T>
Array_Base<T>::~Array_Base (void)
{
	delete[] data_;	
}




// = operator
template <typename T>
const Array_Base<T> & Array_Base<T>::operator = (const Array_Base<T> & rhs)
{

	if( this == &rhs)
		{
			return *this;
		}
	else
		{

			// Deleting the content of what data_ is pointing to,
			// then copying over the data into a temporary array
			// where we just change what data_ is pointing to
			delete[] data_;

			// Ref to lhs variables
			this->cur_size_ = rhs.cur_size_;
			this->max_size_ = rhs.max_size_;

			T * temp = new T[rhs.max_size_];
			T * ptr1 = temp;
			T *ptr2 = rhs.data_;

    
			// Looping to copy over everything
			for ( int i = 0; i < rhs.cur_size_; i ++)
	 			{
					*ptr1 = *ptr2;
					ptr1++;
					ptr2++;
				}

			// Updating what data_ points to
			// and then returning self
			data_ = temp;			
			return *this;
		}
}


template <typename T>
T & Array_Base<T>::operator [] (size_t index)
{
			
	//If withing the range of the array, return the indexed character
	if (index < this->cur_size_)
		{			
		
			T * ptr1 = this->data_;
			return *(ptr1 + index);

		}
	else
		{
					
			throw std::out_of_range("OUT OF RANGE ERROR : [] operator");					
				
		}	
	
	

}	

template <typename T>
const T & Array_Base<T>::operator [] (size_t index) const
{
    
	// This operator is only called when a const Array_Base is formed
	// You can only get() but not set() in this case.
	if( index < this->cur_size_)
		{
			T* ptr1 = this->data_;
			return*(ptr1 + index);
		}
	else 
		{
			throw std::out_of_range("OUT OF RANGE ERROR WITH CONST [] operator");
		}

}

template <typename T>
T Array_Base<T>::get (size_t index) const
{
		

	// If not in bounds of the array
	if(index >= this->cur_size_)
		{		
			throw std::out_of_range("OUT OF RANGE : .get() ");
		}
	else
		{	
			// Pointer to the start of the array
			T* ptr = data_;
			ptr += index;
			return *ptr;
		}			

}

template <typename T>
void Array_Base<T>::set (size_t index, T value)
{

	//Set the value only if index is from 0 to cur_size_ - 1
	if (index < this->cur_size_)
		{
			// Indexing the pointer and setting the value
			T * ptr = data_;
			ptr = ptr + index;
			*ptr = value;
		}
	// If not in bounds
	else
		{
			throw std::out_of_range("OUT OF RANGE : SET()");
		}

}
template <typename T>
int Array_Base<T>::find (T ch) const
{

	// Sending this to find with two arguments
	return this->find(ch,0);
}	

template <typename T>
int Array_Base<T>::find (T ch, size_t start) const
{


	// Pointer to the start of the data
	T* ptr = this->data_;
    

	if(start >= this->cur_size_)
		{		
			throw std::out_of_range("OUT OF BOUND: FIND()");
		}

	// Created increment since while returning, I want to subtract for correct index value
        size_t increment = start;

	// While start to cur_size_ - 1
        while( increment < cur_size_)
                {
			// If found
                        if(*ptr == ch)
                                {
					// Returns the exact index
                                        return (increment - start);
                                }
			// Post increment
                        ptr++;
                        increment++;
                }

	// If not found
        return -1;
 }


template <typename T>
bool Array_Base<T>::operator == (const Array_Base<T> & rhs) const
{
	
	if(this->data_ == rhs.data_)
	{

		return true;		
	}


	// Only execute the following code if lhs size is equal to rhs size
	if((this->cur_size_ == rhs.cur_size_) && (this->max_size_ == rhs.max_size_))
		{
			// Pointers to the starts of lhs data and rhs data
			T * ptr1 = this->data_;
			T * ptr2 = rhs.data_;

			// Iterating through both arrays to check if elements match
			for(int i = 0; i < this->cur_size_; i++)
				{
					// If something does not match		
					if ( *ptr1 != *ptr2)
						{
							
							return false;
						}
					
					ptr1++;
					ptr2++;
				}		

			// After the loop is over
			return true;
		}

	// If lhs size and rhs size is different right off the bat
	else
		{
			return false;	
		}
}

template <typename T>
bool Array_Base<T>::operator != (const Array_Base<T> & rhs) const
{
	
	return !(*this == rhs);
	
}

template <typename T>
void Array_Base<T>::fill (T ch)
{
	// Pointer to start of the Array_Base
	T *ptr = this->data_;
	
	for(int i = 0; i < cur_size_ ; i++)
		{
			// Filling the array with ch
			*ptr = ch;
			ptr++;
		}
}

template <typename T>
void Array_Base<T>::reverse (void)
{
	// Ptr1 points to the beginning of the array
	T* ptr1 = data_;

	// Ptr2 points to the end of the array
	T* ptr2 = data_ + cur_size_ - 1; 

	// For 0 to half the number of times we do reversal
	for(int i = 0; i < cur_size_ /2; i++)
		{
			// Swap helper function
			swap(ptr1, ptr2);

			// Increment the pointer towards the center
			ptr1++;

			// Decrement the pointer towards the center
			ptr2--;

		}
		

}


// Using swap as a helper function in which we are swapping by reference rather just values
template <typename T>
void Array_Base<T>::swap( T *one , T * two)
	{
	
		T temp = *one;
		*one = *two;
		*two = temp;
	}

