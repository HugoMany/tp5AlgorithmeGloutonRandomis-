#ifndef ALGORITHMGLOUTONRANDOMIS_READINGMATRIX_HPP
#define ALGORITHMGLOUTONRANDOMIS_READINGMATRIX_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include "matrice.hpp"
using namespace std;

matrice readingFileCity(vector<string> *city, int &nbOfCity, string pathtofile);
vector<int> randBestRoute(matrice matDistance, int NbCity, int &energieConso);

#endif //ALGORITHMGLOUTONRANDOMIS_READINGMATRIX_HPP
