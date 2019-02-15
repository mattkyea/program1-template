#ifndef PLANET_MK
#define PLANET_MK

class Planet{
	private:
		long int id;
		int pos;
		int distance;
		char type;
	public:
		Planet(){this->id=-1;};
		Planet(int);
		int orbit();
		long int getID(){return this->id;};
		int getDistance(){return this->distance;};
		int getPos(){return this->pos;};
		char getType(){return this->type;};
};

#endif
