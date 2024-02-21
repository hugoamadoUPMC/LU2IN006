#include <stdio.h>
#include "biblioLC.h"
#include "entreeSortieLC.h"

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <nom_fichier> <nombre_lignes>\n", argv[0]);
        return 1;
    }

    char *nom_fichier = argv[1];
    int nombre_lignes = atoi(argv[2]);

    Biblio *bibliotheque = charger_n_entrees(nom_fichier, nombre_lignes);
    if (bibliotheque == NULL) {
        printf("Erreur lors de la lecture du fichier.\n");
        return 1;
    }

    // Afficher la bibliothèque
    afficher_biblio(bibliotheque);

    // Enregistrer la bibliothèque dans un fichier
    enregistrer_biblio(bibliotheque, "bibliotheque.txt");

    // Libérer la mémoire occupée par la bibliothèque
    liberer_biblio(bibliotheque);

    return 0;
}