#include "colis.hpp"

using namespace std;

struct infoColisMax recupColisMax();

vector<colisCapacite> recupColis();

int main()
{
    vector<colisCapacite> colis;
    infoColisMax colisMax;
    colis = recupColis();
    colisMax = recupColisMax();
    cout << "Le volume max du camion est : " << colisMax.volumeMax << endl;
    cout << "Le nombre de colis max du camion est : " << colisMax.colisMax << endl;

    for (int i = 0; i < colis.size(); i++) {
        cout << "Nombre de colis : " << colis[i].getVolume() << "Benefice des colis : " << colis[i].getBenefice() << endl;
    }
    return 0;
}

struct infoColisMax recupColisMax() {
    //Variable utile pour la suite
    vector<colisCapacite> test;
    int volumeMax = 0;
    int nombreColisMax;
    infoColisMax test2;

    //Variable utile pour la récupération des fichiers
    ifstream fichier("C:/Users/maxen/OneDrive/Documents/5colis30capacite.txt");
    string ligne;
    string tmp;
    int compteur = 0;
    int compteur2 = 0;
    int index;
    int volume = 0;
    int benefice = 0;
    do {
        getline(fichier, ligne);
        if (compteur == 0) {
            for (int i = 0; i < ligne.size(); i++) {
                tmp += ligne[i];
                if (compteur2 == 1) {
                    volumeMax += stoi(tmp);
                    tmp = "";
                    compteur2 = 0;
                    test2.volumeMax = volumeMax;
                    test2.colisMax = nombreColisMax;
                }
                if (ligne[i] == 32) {
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
    } while (ligne != "");  // tant que l'on peut mettre la ligne dans "contenu"

    return test2;
}

vector<colisCapacite> recupColis() {
    //Variable utile pour la suite
    vector<colisCapacite> test;
    int volumeMax = 0;
    int nombreColisMax;
    infoColisMax test2;

    //Variable utile pour la récupération des fichiers
    ifstream fichier("C:/Users/maxen/OneDrive/Documents/5colis30capacite.txt");
    string ligne;
    string tmp;
    int compteur = 0;
    int compteur2 = 0;
    int index;
    int volume = 0;
    int benefice = 0;
    do {
        getline(fichier, ligne);
        if (compteur == 0) {
            for (int i = 0; i < ligne.size(); i++) {
                tmp += ligne[i];
                if (compteur2 == 1) {
                    volumeMax += stoi(tmp);
                    tmp = "";
                    compteur2 = 0;
                    test2.volumeMax = volumeMax;
                    test2.colisMax = nombreColisMax;
                }
                if (ligne[i] == 32) {
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
    } while (ligne != "");  // tant que l'on peut mettre la ligne dans "contenu"

    return test;
}