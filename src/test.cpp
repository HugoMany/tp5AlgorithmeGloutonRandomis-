#include "remplirVehicule.hpp"
#include "matrice.hpp"
#include "readingMatrix.hpp"

int main(int argc, char *argv[]){
    srand(stoi(argv[1]));
    string fichiercolis = argv[2];
    string fichierville = argv[3];
    auto donneMax = recupColisMax(fichiercolis);
    auto colis = recupColis();
    remplirVehicule camionnette = remplirVehicule(colis, donneMax.volumeMax, donneMax.colisMax);

    camionnette.remplir();
    camionnette.afficher();

    vector<string> city;
    int nbOfCity = 0;
    int energieConso = 0;

    matrice matDistance = readingFileCity(&city, nbOfCity, fichierville);

    vector<int> meilleurParcours = randBestRoute(matDistance, nbOfCity, energieConso);
    for (int i = 0; i < meilleurParcours.size(); i++)
    {
        cout << city[meilleurParcours[i]] << " "; // Affichage de la route
    }
    cout << ": " << energieConso << " d'energie consomme" << endl; // Affichage de l'�nergie consomm�

    return 0;
}