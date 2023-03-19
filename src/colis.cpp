#include "colis.hpp"

using namespace std;

//Déclaration des fonctions.
struct infoColisMax recupColisMax(); //Fonction pour les données du camion
vector<colisCapacite> recupColis(); //Fonction pour les données des objets

//Définition des fonctions
struct infoColisMax recupColisMax(string path) {
    //Variable utile pour la suite
    vector<colisCapacite> test;
    int volumeMax = 0;
    int nombreColisMax;
    infoColisMax test2;

    //Variable utile pour la récupération des fichiers
    ifstream fichier(path); //chemin du fichier pour les donnes
    string ligne;
    string tmp;
    int compteur = 0;
    int compteur2 = 0;
    int index;
    int volume = 0;
    int benefice = 0;

    /*
    Ce do va prendre ligne par ligne les informations du fichier
    Pour la première ligne, il va récupérer les informations max du camion
    Pour les autres lignes, il va récupérer la conso ainsi que les bénéfices des objets
    */
    do {
        getline(fichier, ligne);
        if (compteur == 0) {
            for (int i = 0; i < ligne.size(); i++) {
                tmp += ligne[i];
                if (compteur2 == 1) {
                    nombreColisMax = stoi(tmp);
                    tmp = "";
                    compteur2 = 0;
                    test2.volumeMax = volumeMax;
                    test2.colisMax = nombreColisMax;
                }
                if (ligne[i] == 32) {
                    volumeMax = stoi(tmp);
                    compteur2++;
                    tmp = "";
                }

            }
        }
        else {
            for (int i = 2; i < ligne.size(); i++) {
                tmp += ligne[i];
                if (compteur2 == 1) {
                    benefice += stoi(tmp);
                    test.push_back(colisCapacite(volume, benefice));
                    compteur2 = 0;
                    volume = 0;
                    benefice = 0;
                    tmp = "";
                }
                if (ligne[i] == 32) {
                    volume = stoi(tmp);
                    compteur2++;
                    tmp = "";
                }
            }
        }
        compteur++; 
    } while (!ligne.empty());  // tant que l'on peut mettre la ligne dans "contenu"

    return test2; // Renvoi la structure contenant les données du camion
}
vector<colisCapacite> recupColis() {
    //Variable utile pour la suite
    vector<colisCapacite> test;
    int volumeMax = 0;
    int nombreColisMax;
    infoColisMax test2;

    //Variable utile pour la récupération des fichiers
    ifstream fichier("5colis30capacite.txt");
    string ligne;
    string tmp;
    int compteur = 0;
    int compteur2 = 0;
    int index;
    int volume = 0;
    int benefice = 0;

    /*
    Ce do va prendre ligne par ligne les informations du fichier
    Pour la première ligne, il va récupérer les informations max du camion
    Pour les autres lignes, il va récupérer la conso ainsi que les bénéfices des objets
    */
    do {
        getline(fichier, ligne);
        if (compteur == 0) {
            for (char i : ligne) {
                tmp += i;
                if (compteur2 == 1) {
                    volumeMax += stoi(tmp);
                    tmp = "";
                    compteur2 = 0;
                    test2.volumeMax = volumeMax;
                    test2.colisMax = nombreColisMax;
                }
                if (i == 32) {
                    nombreColisMax = stoi(tmp);
                    compteur2++;
                    tmp = "";
                }

            }
        }
        else {
            for (int i = 2; i < ligne.size(); i++) {
                tmp += ligne[i];
                if (compteur2 == 1) {
                    benefice += stoi(tmp);
                    test.push_back(colisCapacite(volume, benefice));
                    compteur2 = 0;
                    volume = 0;
                    benefice = 0;
                    tmp = "";
                }
                if (ligne[i] == 32) {
                    volume = stoi(tmp);
                    compteur2++;
                    tmp = "";
                }
            }
        }
        compteur++;
    } while (!ligne.empty());  // tant que l'on peut mettre la ligne dans "contenu"

    return test; //Renvoi le vecteur de classe colisCapacite contenant tout les objets et leurs informations.
}

//Méthode de la classe colisCapacité
int colisCapacite::getVolume() {
    return this->volume;
}
int colisCapacite::getBenefice() {
    return this->benefice;
}
colisCapacite::colisCapacite(int volume, int benefice) {
    this->volume = volume;
    this->benefice = benefice;
}