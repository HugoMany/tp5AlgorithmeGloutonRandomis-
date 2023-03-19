#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include "matrice.hpp"
using namespace std;

matrice::matrice(int n, int m) {
    this->n = n;
    this->m = m;
    this->mat = new int* [n];
    for (int i = 0; i < n; i++) {
        this->mat[i] = new int[m];
    }
}

matrice::~matrice() = default;

int matrice::get(int i, int j) {
    return this->mat[i][j];
}

void matrice::set(int i, int j, int val) {
    this->mat[i][j] = val;
}

//Afficher avec des setw pour aligner les nombres
void matrice::afficher() {
    for (int i = 0; i < this->n; i++) {
        for (int j = 0; j < this->m; j++) {
            std::cout << std::setw(4) << this->mat[i][j];
        }
        std::cout << std::endl;
    }
}

int matrice::getN() const {
    return this->n;
}

int matrice::getM() const {
    return this->m;
}

int* matrice::getLine(int i) {
    return this->mat[i];
}

int* matrice::getColumn(int j) {
    int* col = new int[this->n];
    for (int i = 0; i < this->n; i++) {
        col[i] = this->mat[i][j];
    }
    return col;
}

matrice readingFileCity(){
    ifstream fichier("5villes.txt");
    string fichierStr;
    string temp;
    string nbOfCity;
    string valueDist;
    string nameOfCity;
    vector<string> city;

    cout << fichier.is_open() << endl;
    fichier >> nbOfCity;
    int intNbCity = stoi(nbOfCity);

    matrice matDistance(intNbCity, intNbCity);
    for (int i = 0; i < intNbCity; i++)
    {
        fichier >> nameOfCity;
        city.push_back(nameOfCity);
    }
    for (int x = 0; x < intNbCity; x++)
    {
        for (int y = 0; y < intNbCity; y++)
        {
            fichier >> valueDist;
            matDistance.set(x, y, stoi(valueDist));
        }
    }
    return matDistance;
}

vector<int> randBestRoute(matrice matDistance, int NbCity) {
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
        
        parcours.push_back(idxVilleLaPlusProcheRand); // On ajoute la ville choisi au vecteur
        isTraveled[idxVilleLaPlusProcheRand] = 1; // On dit que cette ville à déjà été parcouru
        previous = idxVilleLaPlusProcheRand; // On retient dans quelle ville on est pour la suite
        nbParcouru++; // On incrémente le nombre de ville parcouru
    }
    return parcours;
}

<<<<<<< Updated upstream
//int main() {
//    matrice matDistance = readingFileCity();
//    matDistance.afficher();
//}
=======
int main() {
    matrice matDistance = readingFileCity();
    matDistance.afficher();
    for (int j = 0; j < 10; j++) {
        vector<int> meilleurParcours = randBestRoute(matDistance, 5);
        for (int i = 0; i < meilleurParcours.size(); i++)
        {
            cout << meilleurParcours[i];
        }
        cout << endl;
    }
    return 0;
}
>>>>>>> Stashed changes
