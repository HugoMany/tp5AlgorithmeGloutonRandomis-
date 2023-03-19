#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class colisCapacite {
private:
	int volume;
	int benefice;
public:
	colisCapacite(int volume, int benefice);
	int getVolume();
	int getBenefice();

};





struct infoColisMax {
	int volumeMax;
	int colisMax;
};

struct infoColisMax recupColisMax(std::string path);
std::vector<colisCapacite> recupColis();