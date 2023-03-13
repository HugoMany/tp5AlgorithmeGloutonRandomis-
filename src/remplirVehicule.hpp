#ifndef ALGORITHMGLOUTONRANDOMIS_REMPLIRVEHICULE_HPP
#define ALGORITHMGLOUTONRANDOMIS_REMPLIRVEHICULE_HPP

#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
#include "colis.hpp"

class remplirVehicule {

public:
    remplirVehicule();
    ~remplirVehicule();
    remplirVehicule(std::vector<colisCapacite> colis, int capacite, int nbColis);
    void remplir();
    void afficher();

private:
    std::vector<colisCapacite> colis;
    int capacite;
    int nbColis;
    std::vector<colisCapacite> colisDansVehicule;
};


#endif //ALGORITHMGLOUTONRANDOMIS_REMPLIRVEHICULE_HPP
