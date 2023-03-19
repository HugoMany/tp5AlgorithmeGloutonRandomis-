#include "createFiles.hpp"

using namespace std;

#define nombreObjetMax 20
#define nombreObjetMin 4
#define volumeCamionMax 50
#define volumeCamionMin 20
#define nombreVilleMax 10
#define nombreVilleMin 3

int main() {
	probleme1();//Génère un fichier avec les données du problème 1
	probleme2();//Génère un fichier avec les données du problème 2
}

void probleme1() {
	string const nomFichier("camion.txt");//Nom du fichier
	ofstream monFlux(nomFichier.c_str());//Ouverture du flux
	if (monFlux)
	{
		srand(time(0));
		int nombreObjet = 0; //Nombre d'objet
		int volumeMax = 0; //Volume du camion

		//Choix du nombre d'objet
		do {
			nombreObjet = rand() % nombreObjetMax + 1;//Génère un nombre entre 0 et 20
		} while (nombreObjet < nombreObjetMin); //Tant que le nombre d'objet est inférieur à 4

		//Choix du volume du camion.
		do {
			volumeMax = rand() % volumeCamionMax + 1; //Génère un nombre entre 0 et 50
		} while (volumeMax < volumeCamionMin); //Tant que le volume est inférieur à 20.

		monFlux << volumeMax << " " << nombreObjet << endl;//Ecrit dans le fichier le volume et le nombre d'objet

		for (int i = 0; i < nombreObjet; i++) {//Boucle allant de 0 au nombre d'objet
			int index = i + 1; //L'index de l'objet
			//La conso de l'objet défini par le volumeMax/le nombre d'objet + un nombre entre 0 et 5
			int consommation = volumeMax / nombreObjet + (rand() % 5 + 1); 
			//Le bénéfice compris entre 0 et 6
			int benefice = rand() % 6 + 1;
			//Ecrit dans le fichier l'index, la conso, le bénéfice
			monFlux << index << " " << consommation << " " << benefice << endl;
		}
	}
	else
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
	}
}

void probleme2() {
	string const nomFichier("villes.txt");//Nom du fichier
	ofstream monFlux(nomFichier.c_str());//Ouverture du flux
	if (monFlux)
	{
		//On va créer un nombre d'objet aléatoirement
		srand(time(0));
		int nombreVille = 0; //Nombre de ville

		//Choix du nombre de villes
		do {
			nombreVille = rand() % nombreVilleMax + 1;
		} while (nombreVille < nombreVilleMin); //Tant que le nombre de ville est inférieur à 3

		monFlux << nombreVille << endl; //Ecrit le nombre de ville

		for (int i = 0; i < nombreVille; i++) { //Boucle allant de 0 à nombre de ville
			string accepte = "abcdefghijklmnopqrstuvwxyz"; //Caractère acceptés pour le nom de ville
			string ville; //Nom de la ville
			for (int i = 0; i < 10; i++) //Boucle allant de 0 à 10
			{
				size_t pos = rand() % 26; //Tire aléatoirement un nombre entre 0 et 26
				ville += accepte[pos]; //Ajoute la lettre à ville correspondant à la position dans string accepte
			}
			monFlux << ville << endl; //Ecrit le nom de la ville
		}

		int a[nombreVilleMax][nombreVilleMax];//Génère un tableau a double entrée de la taille nxn maximale.
		for (int i = 0; i < nombreVille; i++) { //Boucle allant de 0 à nombre de ville
			for (int j = 0; j < nombreVille; j++) {//Boucle allant de 0 à nombre de ville
				if (i == j) { //Si i = j alors 0
					a[i][j] = 0;
				}
				else //Sinon aléatoire entre 0 et 50
				{
					a[i][j] = rand() % 50 + 1;
					a[j][i] = a[i][j]; //Symétrie
				}
			}
		}

		for (int i = 0; i < nombreVille; i++) {//Boucle allant de 0 à nombre de ville
			for (int j = 0; j < nombreVille; j++) {//Boucle allant de 0 à nombre de ville
				monFlux << a[i][j] << " "; //Ecrit la case
			}
			monFlux << endl; //Retour à la ligne dans le .txt
		}
	}
	else
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
	}
}