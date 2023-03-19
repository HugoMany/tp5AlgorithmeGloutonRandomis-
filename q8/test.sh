#Faire un script qui execute plusieur fois le programme AlgorithmGloutonRandomis avec comme parametre une seed (de 1 à 10) et ensuite les fichiers 5colis30capacite.txt et 4villes.txt
#Le script doit ensuite afficher le resultat de la commande dans un fichier resultat.txt

#!/bin/bash

for i in {1..10}
do
    ./AlgorithmGloutonRandomis $i 5colis30capacite.txt 4villes.txt >> resultat.txt
done
