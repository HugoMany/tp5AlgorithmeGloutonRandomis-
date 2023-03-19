#include "readingMatrix.hpp"


matrice readingFileCity(vector<string> *city, int &nbOfCity, string pathtofile) {
    ifstream fichier(pathtofile);
    string fichierStr;
    string temp;
    string stringNbOfCity;
    string valueDist;
    string nameOfCity;

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
    vector<int> parcours; // Vecteur qui contient les index des villes � parcourir dans l'ordre
    parcours.push_back(0); // On d�marre � la premi�re ville
    vector<bool> isTraveled; // Vecteur qui permet de savoir quelles villes ont �t� parcourus (ex : [1, 0, 0, 1, 0] indique que les villes 1 et 4 ont d�j� �t� parcouru)
    for (int i = 0; i < NbCity; i++) isTraveled.push_back(false); // Initialisation de isTraveled : [false, false, false, false, false]

    while (nbParcouru < NbCity - 1)
    {
        int idxVilleLaPlusProche1;
        int idxVilleLaPlusProche2;
        int idxVilleLaPlusProcheRand;

        if ((nbParcouru == 0)) { // Si on est au d�part
            idxVilleLaPlusProche1 = 1; // On initialise l'index de la ville la plus proche � 1 par d�faut
            idxVilleLaPlusProche2 = 2; // Et on initialise l'index de la deuxi�me ville la plus proche � 2 par d�faut
        }
        else {
            for (int i = 1; i < NbCity; i++)
            {
                if (isTraveled[i] == false) // Si la ville n'a pas encore �t� parcouru
                {
                    idxVilleLaPlusProche1 = i; // On initialise l'index de la ville la plus proche � cette ville
                    idxVilleLaPlusProche2 = i; // On initialise l'index de la deuxi�me ville la plus proche � cette ville par d�faut
                    break;
                }
            }
        }

        auto Line = matDistance.getLine(previous); // On r�cup�re la ligne actuelle dans la matrice

        for (int i = 1; i < NbCity; i++) // Note : i ne part pas de 0 car on ne doit retourner � la premiere ville qu'� la fin !
        {
            // Si la prochaine ville � parcourir n'est pas celle dans laquelle on est actuelement
            if (i != nbParcouru)
            {
                // Si la ville n'a pas d�j� �t� parcouru
                if (isTraveled[i] == false)
                {
                    // Si la ville est encore plus proche que celle trouv�e pr�c�demment
                    if (Line[i] < Line[idxVilleLaPlusProche1])
                    {
                        idxVilleLaPlusProche2 = idxVilleLaPlusProche1; // L'anciene ville la plus proche devient la deuxi�me plus proche
                        idxVilleLaPlusProche1 = i; // Cette ville est la nouvelle ville la plus proche
                    }
                }
            }
        }

        int randChoixVille = rand() % 2 + 1; // On choisit al�atoirement entre 1 et 2 (1 = on ira � la ville la plus proche, 2 = on ira � la deuxi�me ville la plus proche

        if (randChoixVille == 1) idxVilleLaPlusProcheRand = idxVilleLaPlusProche1; // On ira � la ville la plus proche
        else idxVilleLaPlusProcheRand = idxVilleLaPlusProche2; // On ira � la deuxi�me ville la plus proche
        
        energieConso += Line[idxVilleLaPlusProcheRand];

        parcours.push_back(idxVilleLaPlusProcheRand); // On ajoute la ville choisi au vecteur
        isTraveled[idxVilleLaPlusProcheRand] = 1; // On dit que cette ville � d�j� �t� parcouru
        previous = idxVilleLaPlusProcheRand; // On retient dans quelle ville on est pour la suite
        nbParcouru++; // On incr�mente le nombre de ville parcouru
    }
    return parcours;
}


