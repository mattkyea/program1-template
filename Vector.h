#ifndef VECTOR_MK
#define VECTOR_MK

#include "Planet.h"

class Vector{
	private:
		unsigned curr_size;	
	public:
		Planet ** planets;
		~Vector();
		Vector();
		void insert(int index, Planet * p);
		Planet * read(int index);
		bool remove(int index);
		unsigned size(){return this->curr_size;};
};

#endif
