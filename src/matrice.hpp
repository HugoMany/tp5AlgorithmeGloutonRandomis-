#ifndef ALGORITHMGLOUTONRANDOMIS_MATRICE_HPP
#define ALGORITHMGLOUTONRANDOMIS_MATRICE_HPP

#include <iostream>

class matrice {
public:
    matrice(int n, int m);
    ~matrice();
    [[nodiscard]]int get(int i, int j);
    void set(int i, int j, int val);
    void afficher();
    [[nodiscard]]int getN() const;
    [[nodiscard]]int getM() const;
    [[nodiscard]]int *getLine(int i);
    [[nodiscard]]int *getColumn(int j);

private:
    int n;
    int m;
    int **mat;
};


#endif //ALGORITHMGLOUTONRANDOMIS_MATRICE_HPP
