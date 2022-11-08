// -*- C++ -*-
// $Id: Array.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
 * @file       Array.h
 *
 * $Id: Array.h 380 2010-02-08 05:10:33Z hillj $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _ARRAY_H_
#define _ARRAY_H_


#include "Array_Base.h"
//#include "Array_Iterator.h"
#include <cstring>

/**
 * @class Array
 *
 * Basic implementation of a standard array class for chars.
 */
template <typename T>
class Array : public Array_Base <T>
{

public:

  typedef T type;

 // Default constructor.
  Array (void);

 //  Initializing constructor.
  Array (size_t length);

  // Initializing constructor.
  Array (size_t length, T fill);

  // Copy constructor
  Array (const Array <T>& arr);


  // Methods that pertain to only Array and its children
  void resize (size_t new_size);

  void shrink();
  
  Array slice (size_t begin) const;

  Array slice (size_t begin, size_t end) const;
 
  //friend class Array_Iterator<T>;
  
};


#include "Array.inl"
#include "Array.cpp"

#endif   // !defined _ARRAY_H_
