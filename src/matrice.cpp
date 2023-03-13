#include "matrice.hpp"

matrice::matrice(int n, int m) {
    this->n = n;
    this->m = m;
    this->mat = new int*[n];
    for (int i = 0; i < n; i++) {
        this->mat[i] = new int[m];
    }
}

matrice::~matrice() {
    for (int i = 0; i < this->n; i++) {
        delete[] this->mat[i];
    }
    delete[] this->mat;
}

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

int *matrice::getLine(int i) {
    return this->mat[i];
}

int *matrice::getColumn(int j) {
    int *col = new int[this->n];
    for (int i = 0; i < this->n; i++) {
        col[i] = this->mat[i][j];
    }
    return col;
}