#include <cmath>
#include "remplirVehicule.hpp"

remplirVehicule::remplirVehicule(std::vector<colisCapacite> colis, int capacite, int nbColis) {
    this->colis = std::move(colis);
    this->capacite = capacite;
    this->nbColis = nbColis;
}

remplirVehicule::~remplirVehicule() = default;

void remplirVehicule::remplir() {
    std::vector<std::pair<float, colisCapacite>> ratio;
    for (auto colis_ : this->colis) {
        ratio.push_back(std::make_pair((float)colis_.getBenefice() / (float)colis_.getVolume(), colis_));
    }

    //Trier la le vecteur ratio par ordre décroissant
    std::sort(ratio.begin(), ratio.end(), [](const std::pair<float, colisCapacite> &a, const std::pair<float, colisCapacite> &b) {
        return a.first > b.first;
    });

    int i = 0;
    while (this->nbColis > 0 && ratio.size() >= 2 && (this->capacite >= ratio[i].second.getVolume() || this->capacite >= ratio[i + 1].second.getVolume())) {
        int random = rand() % 2;
        if (random == 0) {
            this->colisDansVehicule.push_back(ratio[0].second);
            ratio.erase(ratio.begin());
            ratio.erase(ratio.begin()+1);
            this->nbColis--;
            this->capacite -= ratio[i].second.getVolume();
        }
        else{
            this->colisDansVehicule.push_back(ratio[1].second);
            ratio.erase(ratio.begin());
            ratio.erase(ratio.begin()+1);
            this->nbColis--;
            this->capacite -= ratio[i].second.getVolume();
        }
        i++;
    }
    if (ratio.size() == 1){
        this->colisDansVehicule.push_back(ratio[0].second);
        this->nbColis--;
        this->capacite -= ratio[0].second.getVolume();
    }
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

remplirVehicule::remplirVehicule() {
    this->capacite = 0;
    this->nbColis = 0;
}
