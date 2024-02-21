#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../exo1/biblioLC.h"
#include "../exo2/biblioH.h"

#define NUM_OUVRAGES 10000

int main() {
    // Création d'une bibliothèque avec une liste chaînée
    Biblio *biblioLC = creer_biblio();

    // Insertion d'ouvrages dans la bibliothèque avec liste chaînée
    for (int i = 0; i < NUM_OUVRAGES; i++) {
        inserer_en_tete(biblioLC, i, "Titre", "Auteur");
    }

    // Recherche par numéro dans la liste chaînée
    clock_t startLC_num = clock();
    for (int i = 0; i < NUM_OUVRAGES; i++) {
        Livre *resultat = recherche_par_num(biblioLC, i);
    }
    clock_t endLC_num = clock();
    double tempsLC_num = ((double) (endLC_num - startLC_num)) / CLOCKS_PER_SEC;

    printf("Temps de recherche par numéro (Liste chaînée) : %f secondes\n", tempsLC_num);

    // Libération de la mémoire de la bibliothèque avec liste chaînée
    liberer_biblio(biblioLC);

    // Création d'une bibliothèque avec une table de hachage
    BiblioH *biblioH = creer_biblioH(10000);

    // Insertion d'ouvrages dans la bibliothèque avec table de hachage
    for (int i = 0; i < NUM_OUVRAGES; i++) {
        inserer(biblioH, i, "Titre", "Auteur");
    }

    // Recherche par numéro dans la table de hachage
    clock_t startH_num = clock();
    for (int i = 0; i < NUM_OUVRAGES; i++) {
        //LivreH *resultat = recherche_par_numH(biblioH, i);
    }
    clock_t endH_num = clock();
    double tempsH_num = ((double) (endH_num - startH_num)) / CLOCKS_PER_SEC;

    printf("Temps de recherche par numéro (Table de hachage) : %f secondes\n", tempsH_num);

    // Libération de la mémoire de la bibliothèque avec table de hachage
    liberer_biblioH(biblioH);

    return 0;
}
