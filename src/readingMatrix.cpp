#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include "matrice.hpp"
using namespace std;


matrice readingFileCity(vector<string> *city, int &nbOfCity) {
    ifstream fichier("4villes.txt");
    string fichierStr;
    string temp;
    string stringNbOfCity;
    string valueDist;
    string nameOfCity;

    cout << "? Fichier ouvert : " << fichier.is_open() << "\n" << endl;
    fichier >> stringNbOfCity;
    nbOfCity = stoi(stringNbOfCity);

    matrice matDistance(nbOfCity, nbOfCity);
    for (int i = 0; i < nbOfCity; i++)
    {
        fichier >> nameOfCity;
        city->push_back(nameOfCity);
    }
    for (int x = 0; x < nbOfCity; x++)
    {
        for (int y = 0; y < nbOfCity; y++)
        {
            fichier >> valueDist;
            matDistance.set(x, y, stoi(valueDist));
        }
    }
    return matDistance;
}

vector<int> randBestRoute(matrice matDistance, int NbCity, int &energieConso) {
    int nbParcouru = 0;
    int previous = 0;
    vector<int> parcours; // Vecteur qui contient les index des villes à parcourir dans l'ordre
    parcours.push_back(0); // On démarre à la première ville
    vector<bool> isTraveled; // Vecteur qui permet de savoir quelles villes ont été parcourus (ex : [1, 0, 0, 1, 0] indique que les villes 1 et 4 ont déjà été parcouru)
    for (int i = 0; i < NbCity; i++) isTraveled.push_back(false); // Initialisation de isTraveled : [false, false, false, false, false]

    while (nbParcouru < NbCity - 1)
    {
        int idxVilleLaPlusProche1;
        int idxVilleLaPlusProche2;
        int idxVilleLaPlusProcheRand;

        if ((nbParcouru == 0)) { // Si on est au départ
            idxVilleLaPlusProche1 = 1; // On initialise l'index de la ville la plus proche à 1 par défaut
            idxVilleLaPlusProche2 = 2; // Et on initialise l'index de la deuxième ville la plus proche à 2 par défaut
        }
        else {
            for (int i = 1; i < NbCity; i++)
            {
                if (isTraveled[i] == false) // Si la ville n'a pas encore été parcouru
                {
                    idxVilleLaPlusProche1 = i; // On initialise l'index de la ville la plus proche à cette ville
                    idxVilleLaPlusProche2 = i; // On initialise l'index de la deuxième ville la plus proche à cette ville par défaut
                    break;
                }
            }
        }

        auto Line = matDistance.getLine(previous); // On récupère la ligne actuelle dans la matrice

        for (int i = 1; i < NbCity; i++) // Note : i ne part pas de 0 car on ne doit retourner à la premiere ville qu'à la fin !
        {
            // Si la prochaine ville à parcourir n'est pas celle dans laquelle on est actuelement
            if (i != nbParcouru)
            {
                // Si la ville n'a pas déjà été parcouru
                if (isTraveled[i] == false)
                {
                    // Si la ville est encore plus proche que celle trouvée précédemment
                    if (Line[i] < Line[idxVilleLaPlusProche1])
                    {
                        idxVilleLaPlusProche2 = idxVilleLaPlusProche1; // L'anciene ville la plus proche devient la deuxième plus proche
                        idxVilleLaPlusProche1 = i; // Cette ville est la nouvelle ville la plus proche
                    }
                }
            }
        }

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 2); // Génère un nombre aléatoire : soit 1, soit 2
        int randChoixVille = dis(gen);

        if (randChoixVille == 1) idxVilleLaPlusProcheRand = idxVilleLaPlusProche1; // On ira à la ville la plus proche
        else idxVilleLaPlusProcheRand = idxVilleLaPlusProche2; // On ira à la deuxième ville la plus proche
        
        energieConso += Line[idxVilleLaPlusProcheRand];

        parcours.push_back(idxVilleLaPlusProcheRand); // On ajoute la ville choisi au vecteur
        isTraveled[idxVilleLaPlusProcheRand] = 1; // On dit que cette ville à déjà été parcouru
        previous = idxVilleLaPlusProcheRand; // On retient dans quelle ville on est pour la suite
        nbParcouru++; // On incrémente le nombre de ville parcouru
    }
    return parcours;
}


int main() {
    vector<string> city;
    int nbOfCity = 0;
    int energieConso = 0;

    matrice matDistance = readingFileCity(&city, nbOfCity);
    matDistance.afficher();
    cout << endl;

    vector<int> meilleurParcours = randBestRoute(matDistance, nbOfCity, energieConso);
    for (int i = 0; i < meilleurParcours.size(); i++)
    {
        cout << city[meilleurParcours[i]] << " "; // Affichage de la route
    }
    cout << ": " << energieConso << " d'energie consomme" << endl; // Affichage de l'énergie consommé

    return 0;
}