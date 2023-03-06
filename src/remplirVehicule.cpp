#include "remplirVehicule.hpp"

remplirVehicule::remplirVehicule(std::vector<colisCapacite> colis, int capacite) {
    this->colis = std::move(colis);
    this->capacite = capacite;
}