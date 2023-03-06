#include "remplirVehicule.hpp"

remplirVehicule::remplirVehicule(std::vector<colisCapacite> colis, int capacite, int nbColis) {
    this->colis = std::move(colis);
    this->capacite = capacite;
    this->nbColis = nbColis;
}

remplirVehicule::~remplirVehicule() = default;

void remplirVehicule::remplir() {
    int volume = this->capacite;
    int nbColisMax = this->nbColis;

    //Trier les colis par volume décroissant
    std::sort(this->colis.begin(), this->colis.end(), [](colisCapacite a, colisCapacite b) {
        return a.getVolume() > b.getVolume();
    });

    // Mise en place d'un algorithme glouton qui calcule la meilleure solution
    int i = 0;
    while (volume > 0 && i < nbColisMax) {
        if (this->colis[i].getVolume() <= volume) {
            this->colisDansVehicule.push_back(this->colis[i]);
            volume = volume - this->colis[i].getVolume();
        }
        i++;
    }
}

void remplirVehicule::afficher() {
    std::cout << "Colis dans le véhicule : " << std::endl;
    for (int i = 0; i < this->colisDansVehicule.size(); i++) {
        std::cout << "Colis " << i << " : " << this->colisDansVehicule[i].getVolume() << " " << this->colisDansVehicule[i].getBenefice() << std::endl;
    }
}