#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class colisCapacite {
private:
	int volumeMax;
	int colisMax;
	int volume;
	int benefice;
public:
	colisCapacite();
	colisCapacite(int volume, int benefice);
	int getVolume();
	int getBenefice();

};

colisCapacite::colisCapacite(int volume, int benefice) {
	this->volume = volume;
	this->benefice = benefice;
}

int colisCapacite::getVolume() {
	return this->volume;
}

int colisCapacite::getBenefice() {
	return this->benefice;
}

struct infoColisMax {
	int volumeMax;
	int colisMax;
};