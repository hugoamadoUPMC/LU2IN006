#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../exo1/biblioLC.h"
#include "../exo2/biblioH.h"

#define NUM_OUVRAGES 10000

int main() {
    // Temps de recherche pour la liste chaînée
    clock_t startLC, endLC;
    double tempsLC;

    // Création d'une bibliothèque avec une liste chaînée
    Biblio *biblioLC = creer_biblio();

    // Insertion d'ouvrages dans la bibliothèque avec liste chaînée
    for (int i = 0; i < NUM_OUVRAGES; i++) {
        inserer_en_tete(biblioLC, i, "Titre", "Auteur");
    }

    // Recherche par numéro dans la liste chaînée (livre présent)
    startLC = clock();
    for (int i = 0; i < NUM_OUVRAGES; i++) {
        recherche_par_num(biblioLC, i);
    }
    endLC = clock();
    tempsLC = ((double)(endLC - startLC)) / CLOCKS_PER_SEC;
    printf("Temps de recherche par numéro (Liste chaînée, livre présent) : %f secondes\n", tempsLC);

    // Recherche par numéro dans la liste chaînée (livre absent)
    startLC = clock();
    for (int i = NUM_OUVRAGES; i < NUM_OUVRAGES + 100; i++) {
        recherche_par_num(biblioLC, i);
    }
    endLC = clock();
    tempsLC = ((double)(endLC - startLC)) / CLOCKS_PER_SEC;
    printf("Temps de recherche par numéro (Liste chaînée, livre absent) : %f secondes\n", tempsLC);

    // Libération de la mémoire de la bibliothèque avec liste chaînée
    liberer_biblio(biblioLC);

    // Temps de recherche pour la table de hachage
    clock_t startH, endH;
    double tempsH;

    // Création d'une bibliothèque avec une table de hachage
    BiblioH *biblioH = creer_biblioH(NUM_OUVRAGES);

    // Insertion d'ouvrages dans la bibliothèque avec table de hachage
    for (int i = 0; i < NUM_OUVRAGES; i++) {
        inserer(biblioH, i, "Titre", "Auteur");
    }

    // Recherche par numéro dans la table de hachage (livre présent)
    startH = clock();
    for (int i = 0; i < NUM_OUVRAGES; i++) {
        recherche_par_numH(biblioH, i);
    }
    endH = clock();
    tempsH = ((double)(endH - startH)) / CLOCKS_PER_SEC;
    printf("Temps de recherche par numéro (Table de hachage, livre présent) : %f secondes\n", tempsH);

    // Recherche par numéro dans la table de hachage (livre absent)
    startH = clock();
    for (int i = NUM_OUVRAGES; i < NUM_OUVRAGES + 100; i++) {
        recherche_par_numH(biblioH, i);
    }
    endH = clock();
    tempsH = ((double)(endH - startH)) / CLOCKS_PER_SEC;
    printf("Temps de recherche par numéro (Table de hachage, livre absent) : %f secondes\n", tempsH);

    // Libération de la mémoire de la bibliothèque avec table de hachage
    liberer_biblioH(biblioH);

    return 0;
}
