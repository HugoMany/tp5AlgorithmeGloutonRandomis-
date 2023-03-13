#include "remplirVehicule.hpp"

remplirVehicule::remplirVehicule(std::vector<colisCapacite> colis, int capacite, int nbColis) {
    this->colis = std::move(colis);
    this->capacite = capacite;
    this->nbColis = nbColis;
}

remplirVehicule::~remplirVehicule() = default;

void remplirVehicule::remplir() {
    std::vector<float> ratio;
    for (auto colis : this->colis) {
        ratio.push_back((float) colis.getBenefice() / (float) colis.getVolume());
    }

    sort(ratio.begin(), ratio.end(), std::greater<>());

    /*
     * L'algo glouton à faire :
     * On calcule le ratio poids/benefice de chaque colis
     * On trie les colis par ratio décroissant
     * On prend les 2 meilleurs ratio
     * On select au hasard un des 2
     * On recommence jusqu'à ce qu'on ait plus de place dans le véhicule
     *
     * On fait plusieurs fois l'algo et on garde la meilleure solution
     */


}

void remplirVehicule::afficher() {
    std::cout << "Colis dans le véhicule : " << std::endl;
    for (int i = 0; i < this->colisDansVehicule.size(); i++) {
        std::cout << "Colis " << i << " : " << this->colisDansVehicule[i].getVolume() << " " << this->colisDansVehicule[i].getBenefice() << std::endl;
    }
}