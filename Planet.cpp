#include "Planet.h"
#include <cstdlib>
#include <iostream>

//Planet class implementation

Planet::Planet(int distance){
	this->id = (long int) this;//id is the address of the object
	this->distance = distance;//random distance between 0 and 3000
	this->pos = rand() % 360;//random position between 0 and 359
	char planet_types[] = "hrg";
	int num = rand() % 3;//between 0 and 2
	this->type = planet_types[num];//grab the numth letter from planet_type string	
}

int Planet::orbit(){
	this->pos++;
	if(this->pos == 360){//pos is above the maximum value of 360
		this->pos = 0;//so reset back to 0
	}
	return this->pos;
}

