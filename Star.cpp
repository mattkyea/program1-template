#include "Star.h"
#include "Planet.h"
#include <cstdlib>
#include <iostream>

//Star class implementation

//constructor
Star::Star(){
	this->current_planets = 0;
	this->planets = NULL;//set unused pointers to null
}

//destructor
Star::~Star(){
	for(int i=0; i<current_planets; i++){//loop through array to delete each planet
		delete planets[i];
	}
	delete[] planets;
	this->planets = NULL;
}

long int Star::addPlanet(){
	Planet * new_planet = new Planet(rand() % 3001);//make a new planet object with random distance (0-3000) 
	Planet ** new_array;//new array of planets pointers
	new_array = new Planet*[current_planets+1];//with size to hold all old planets plus the new one
	for(int i =0; i < this->current_planets; i++){//copy all values over
		Planet * curr_planet = this->planets[i];//grab the ith planet
		new_array[i] = curr_planet;//put in the new array
	}
	new_array[this->current_planets] = new_planet;//add the new planet
	delete[] this->planets;//delete the old array
	this->planets = new_array;//point to the new array
	this->current_planets = this->current_planets+1;//don't forget to tell star it has a new planet	
	return new_planet->getID();//return the new planets id
}

bool Star::removePlanet(int currid){	
	if(Star::getPlanet(currid)== NULL){return false;}//check if ID exists first
	int rm_index;
	Planet ** new_planet_array;//make new array
	new_planet_array = new Planet*[current_planets-1];//size to hold all current planets minus the one being removed
	int actualindex = 0;//variable used to keep track of where we should be in the new array
	//i.e., when we find the planet with the id, put the planet after it in its place, and don't overflow array
	for(int i =0; i< this->current_planets; i++){//loop through planets
		Planet * curr_planet = this->planets[i];//get the ith planet
		if(curr_planet->getID() == currid){//check if its id matches
			rm_index = i;//if it does, save its index in the array
		}else{//if the id doesn't match
			new_planet_array[actualindex] = curr_planet;//save the current planet at the actual index, not i
			actualindex++;//increment - only account for planets we want in the new array
		}
	}
	delete this->planets[rm_index];//delete planet with currid
	delete[] this->planets;//delete old array 
	this->planets = new_planet_array;//point to new array
	this->current_planets--;//remove from count
	return true;//success
}

Planet * Star::getPlanet(int currid){
	Planet * planet_pointer = NULL;
	for(int i =0; i< this->current_planets; i++){
		if(this->planets[i]->getID() == currid){
			planet_pointer = this->planets[i];
		}
	}
	return planet_pointer;
}


void Star::orbit(){
	for(int i = 0; i < this->current_planets; i++){//loop through all the planets
		Planet *curr_plan = (Planet *) this->planets[i];
		curr_plan->orbit();//orbit method on the ith planet
	}
}


void Star::printStarInfo(){
	std::cout << "\tThe star has " <<  this->current_planets <<  " planets." << std::endl;
	std::cout << "\tPlanets:" << std::endl;
	for(int i=0; i< this->current_planets; i++){
		std::cout << "\tPlanet " << this->planets[i]->getType() << this->planets[i]->getID() << " is " << this->planets[i]->getDistance() << " million miles away at position " << this->planets[i]->getPos() << " around the star." << std::endl;
	}
}

