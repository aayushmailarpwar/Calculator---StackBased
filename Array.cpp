// $Id: Array.cpp 820 2011-01-17 15:30:41Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
//#include <iostream>
//#include <stdexcept>



// Default Constructor
template <typename T>
Array<T>::Array (void):
  Array_Base<T> ()
{

}


// Initializing Constructor
template <typename T>
Array<T>::Array (size_t length):
  Array_Base<T> (length)
{
	
}


// Initializing Constructor using the fill method 
template <typename T>
Array<T>::Array (size_t length, T fill):
  Array_Base<T> (length, fill)
{

}


// Copy constructor
template <typename T>
Array<T>::Array (const Array & array):
  Array_Base<T>(array)
{	

}


template <typename T>
void Array<T>::resize (size_t new_size)
{

	// As long as the current size and maximum size is not equal
	// Copy over contents of data_ to temp_array with limitations to size
	// Delete the array data_
	// Let data_ pointer point to the temp_array


	// If the new size is greater than current size, we increase max and curr to new size 
	// and copying it over into the new data_
	if(new_size > this->cur_size_)
		{
			// Updating the sizes
			this->cur_size_ = new_size;
			this->max_size_ = new_size;
				
			// New temporary array for storing the values
			T* temp_array = new T[new_size];

			// Pointers to first elements of both arrays
			T* ptr1 = this->data_;
			T* ptr2 = temp_array;

			// Copying values over to temp
			for(int i = 0; i < new_size; i++)
				{
					*ptr2 = *ptr1;
					ptr1++;
					ptr2++;	
				}

			//Deleting the contents of data_ off the heap
			delete[] this->data_;
			this->data_ = temp_array;
            
		}
	
	
	// If new size is smaller or equal then just update cur_size and leave memory allocated (max_size)
	// as it is, shrink method will work on it.
	else
		{
			this->cur_size_ = new_size;		
		}

}


template <typename T>
void Array<T>::shrink (void)
{

	// I am copying the data_ array into temp_array and then deleting the data_ array
	// Then I am repointing the temp_array into called data_
	// I do this so I can restore and keep the private member data_
 
	// Shrink only if the current size is smaller than the maximum size
	if(this->cur_size_ < this->max_size_)
		{
			
			// Change maximum size allocated to current size
			this->max_size_ = this->cur_size_;

			// Creating new temp array to store these value with cur_size
			T* temp_array = new T[this->cur_size_];

			//Pointers to the two arrays
			T * ptr1 = this->data_;
			T * ptr2 = temp_array;

			//Copy everything from the data_ to temp array
			for(int i = 0; i < this->cur_size_; i++)
				{
					*ptr2 = *ptr1;
					ptr1++;
					ptr2++;
				}

			//Deleting the data_ array
			delete[] this->data_;
            		this->data_ = temp_array;
		}

	

}


template <typename T>
Array<T> Array<T>::slice (size_t begin) const
{
	return slice(begin, this->cur_size_ - 2);	
}

template <typename T>
Array<T> Array<T>::slice (size_t begin, size_t end) const
{
	// Creating a sliced size Array and then copying 
	// over data
	
	Array<T> sliced_Array (end - begin + 1);

  	T* ptr1 = this->data_ + begin;
	T* ptr2 = sliced_Array.data_;
	
        for(int i = 0; i< end - begin + 1 ; i++)
                {
                        *ptr2 = *ptr1;
                        ptr2++;
                        ptr1++;

                }
    
        return sliced_Array;
}
