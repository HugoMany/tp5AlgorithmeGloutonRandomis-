#ifndef ALGORITHMGLOUTONRANDOMIS_REMPLIRVEHICULE_HPP
#define ALGORITHMGLOUTONRANDOMIS_REMPLIRVEHICULE_HPP

#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
#include "protoColisCapacite.hpp"//À Modifier quand on aura la classe

class remplirVehicule {
    remplirVehicule(std::vector<colisCapacite> colis, int capacite, int nbColis);
    ~remplirVehicule();
    void remplir();
    void afficher();
private:
    std::vector<colisCapacite> colis;
    int capacite;
    int nbColis;
    std::vector<colisCapacite> colisDansVehicule;
};


#endif //ALGORITHMGLOUTONRANDOMIS_REMPLIRVEHICULE_HPP
