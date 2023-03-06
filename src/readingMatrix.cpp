#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
	ifstream fichier("5villes.txt");
	string fichierStr;
	string temp;

	cout << fichier.is_open();
	while (fichier)
	{
		fichier>> temp;
		fichierStr += temp;
	}
}
