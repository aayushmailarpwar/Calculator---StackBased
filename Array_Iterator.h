#ifndef _ARRAY_ITERATOR_H_
#define _ARRAY_ITERATOR_H_

#include "Array.h"


template <typename T>
class Array_Iterator 
{
	typedef T type;
	public:
		Array_Iterator(Array <T>& a);
		~Array_Iterator(void);
	
		bool is_done(void);
		void advance(void);
		T& operator * (void);
		T* operator -> (void);

	private:
		Array <T>& a_;
		size_t curr_;
};

#endif
