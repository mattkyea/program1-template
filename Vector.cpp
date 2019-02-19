#include "Star.h"
#include "Planet.h"
#include "Vector.h"
#include <cstdlib>
#include <iostream>

//Vector class implementation
//should this be more general or for Planets like I've done?

//constructor
Vector::Vector(){
	this->curr_size = 0;
	this->planets = NULL;//set unused pointers to null
}

//destructor
Vector::~Vector(){
	for(int i=0; i<this->curr_size; i++){//loop through array to delete each planet
		delete planets[i];
	}
	delete[] planets;
	this->planets = NULL;
}

/*
 	if the index is within bounds, insert element p at index and copy all values over 
	those with index < parameter index have same index in old and new array
	those with index >= parameter index have their old index + 1 in the new array
	if the index is out of bounds, copy over the entire old array in their original indices
	then insert p at index, in our new array of size index+1
*/
void Vector::insert(int index, Planet * p){//inserts an element at index, increasing size by 1 and if vector not large enough increase capacity
	if(index < this->curr_size){//within size
		Planet ** new_array;
	        new_array = new Planet*[this->curr_size+1];
		this->curr_size++;//update size of vector
		int old_arr_index = 0;
		for(int i=0; i<this->curr_size; i++){
			if(i == index){
				new_array[i] = p;
			}else{
				new_array[i] = this->planets[old_arr_index];//accounts for new element not being in the old array
				old_arr_index++;//only increment when we took an element from the old array
			}
		}
		this->planets = new_array;//point to the new array
	}else{//index>size, out of bounds
		Planet ** new_array = new Planet*[index+1];
		for(int i =0; i<this->curr_size; i++){//copy over all values from old array
			new_array[i] = this->planets[i];
		}
		this->curr_size = index+1;//update size of vector
		new_array[index] = p;//insert the new element at index
		this->planets = new_array;//point to the new array
	}
	//free old memory
	delete[] this->planets;//delete the old array
}
			
		
//return pointer to the Planet object at index or null if out of bounds
Planet* Vector::read(int index){
	if(index > this->curr_size) return NULL;
	return this->planets[index];	
}

/*
	returns false when index out of bounds
	else copys over all the elements from the previous array not located at index
	only copies over when i != index, and saves into a smaller sized array using actual_index variable
*/
bool Vector::remove(int index){
	if(index>this->curr_size) return false;//check for out of bounds
	Planet ** new_array;
	new_array = new Planet*[this->curr_size-1];
	this->curr_size--;//update size of vector
	int actual_index = 0;//keep track of the index we want to save to - can't use i
	for(int i=0; i<this->curr_size; i++){
		if(i != index){
			new_array[actual_index] = this->planets[actual_index];//accounts for deleted element not being in the new array
			actual_index++;//only increment when we don't hit the element we want to delete
		}
	}
	delete this->planets[index];//delete planet at index
	delete[] this->planets;//delete old array 
	this->planets = new_array;//point to new array
	return true;//success
}

