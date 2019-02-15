#ifndef STAR_MK
#define STAR_MK

#include "Planet.h"

class Star{
	private:
		int current_planets;
		//int next_id;
	public:
		Planet ** planets;
		Star();
		~Star();
		long int addPlanet();
		bool removePlanet(int);
		Planet * getPlanet(int);
		void orbit();
		void printStarInfo();
		int getCurrentNumPlanets(){return this->current_planets;};
};

#endif
