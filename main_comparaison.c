#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include "exo1/biblioLC.h"
#include "exo1/entreeSortieLC.h"

#include "exo2/biblioH.h"
#include "exo2/entreeSortieH.h"

#define NOMBREMIN 10
#define NOMBREMAX 500000

int main(int argc, char* argv[]){
    if(argc != 3){
        printf("Il faut 2 arguments : nom_du_fichier et nb_de_lignes.\n");
        return 0;
    }

    // Mesure du temps d'exécution entre les deux structures pour la fonction de chargement
    printf("Calcul du temps d'exécution de la fonction charger_n_entrees :\n");

    clock_t debut_lc = clock(); // Début du chronomètre pour la liste chaînée
    Biblio* biblio_lc = charger_n_entrees(argv[1], atoi(argv[2])); // Chargement des entrées dans une liste chaînée
    clock_t fin_lc = clock(); // Fin du chronomètre pour la liste chaînée

    clock_t debut_h = clock(); // Début du chronomètre pour la table de hachage
    BiblioH* biblio_h = charger_n_entreesH(argv[1], atoi(argv[2])); // Chargement des entrées dans une table de hachage
    clock_t fin_h = clock(); // Fin du chronomètre pour la table de hachage

    double temps_lc = ((double)(fin_lc - debut_lc)) / CLOCKS_PER_SEC; // Calcul du temps pour la liste chaînée
    double temps_h = ((double)(fin_h - debut_h)) / CLOCKS_PER_SEC; // Calcul du temps pour la table de hachage

    printf("Temps d'exécution de la fonction charger_n_entrees pour LISTE CHAINEE : %f s\n", temps_lc);
    printf("Temps d'exécution de la fonction charger_n_entrees pour TABLE HACHAGE : %f s\n", temps_h);

    // Mesure du temps pour les différentes fonctions de recherche d'ouvrages entre les deux structures

    // 1 - Recherche d'un ouvrage par numéro
    printf("Calcul du temps d'exécution de la fonction recherche d'un ouvrage par son numéro :\n");

    clock_t debut_lc_n = clock();
    recherche_par_num(biblio_lc, NOMBREMIN);
    clock_t fin_lc_n = clock();

    clock_t debut_h_n = clock();
    recherche_par_numH(biblio_h, NOMBREMIN);
    clock_t fin_h_n = clock();

    double temps_lc_n = ((double)(fin_lc_n - debut_lc_n)) / CLOCKS_PER_SEC;
    double temps_h_n = ((double)(fin_h_n - debut_h_n)) / CLOCKS_PER_SEC;

    printf("Temps d'exécution pour la recherche par numéro (cas existant) - LISTE CHAINEE : %f s\n", temps_lc_n);
    printf("Temps d'exécution pour la recherche par numéro (cas existant) - TABLE HACHAGE : %f s\n", temps_h_n);

    // 2 - Recherche d'un ouvrage par le titre du livre
    printf("Calcul du temps d'exécution de la fonction recherche d'un ouvrage par son titre :\n");

    clock_t debut_lc_t = clock();
    recherche_par_titre(biblio_lc, "KEZXDU");
    clock_t fin_lc_t = clock();

    clock_t debut_h_t = clock();
    recherche_par_titreH(biblio_h, "KEZXDU");
    clock_t fin_h_t = clock();

    double temps_lc_t = ((double)(fin_lc_t - debut_lc_t)) / CLOCKS_PER_SEC;
    double temps_h_t = ((double)(fin_h_t - debut_h_t)) / CLOCKS_PER_SEC;

    printf("Temps d'exécution pour la recherche par titre (cas existant) - LISTE CHAINEE : %f s\n", temps_lc_t);
    printf("Temps d'exécution pour la recherche par titre (cas existant) - TABLE HACHAGE : %f s\n", temps_h_t);

    // 3 - Recherche d'ouvrages par le nom d'auteur
    printf("Calcul du temps d'exécution de la fonction recherche d'ouvrages par le nom d'auteur :\n");

    clock_t debut_lc_a = clock();
    Biblio* biblio_a_lc = recherche_livres_auteur(biblio_lc, "pslgvlcsa");
    clock_t fin_lc_a = clock();

    clock_t debut_h_a = clock();
    BiblioH* biblio_a_h = recherche_livres_auteurH(biblio_h, "pslgvlcsa");
    clock_t fin_h_a = clock();

    double temps_lc_a = ((double)(fin_lc_a - debut_lc_a)) / CLOCKS_PER_SEC;
    double temps_h_a = ((double)(fin_h_a - debut_h_a)) / CLOCKS_PER_SEC;

    printf("Temps d'exécution pour la recherche par auteur (cas existant) - LISTE CHAINEE : %f s\n", temps_lc_a);
    printf("Temps d'exécution pour la recherche par auteur (cas existant) - TABLE HACHAGE : %f s\n", temps_h_a);

    // Cas où l'ouvrage est absent de la bibliothèque
    clock_t debut_lc_t1 = clock();
    recherche_par_titre(biblio_lc, "BOHEME");
    clock_t fin_lc_t1 = clock();

    clock_t debut_h_t1 = clock();
    recherche_par_titreH(biblio_h, "BOHEME");
    clock_t fin_h_t1 = clock();

    double temps_lc_t1 = ((double)(fin_lc_t1 - debut_lc_t1)) / CLOCKS_PER_SEC;
    double temps_h_t1 = ((double)(fin_h_t1 - debut_h_t1)) / CLOCKS_PER_SEC;

    printf("Temps d'exécution pour la recherche par titre (cas inexistant) - LISTE CHAINEE : %f s\n", temps_lc_t1);
    printf("Temps d'exécution pour la recherche par titre (cas inexistant) - TABLE HACHAGE : %f s\n", temps_h_t1);

    // Cas où les ouvrages sont absents de la bibliothèque
    clock_t debut_lc_a1 = clock();
    Biblio* biblio_a_lc1 = recherche_livres_auteur(biblio_lc, "Jacques");
    clock_t fin_lc_a1 = clock();

    clock_t debut_h_a1 = clock();
    BiblioH* biblio_a_h1 = recherche_livres_auteurH(biblio_h, "Jacques");
    clock_t fin_h_a1 = clock();

    double temps_lc_a1 = ((double)(fin_lc_a1 - debut_lc_a1)) / CLOCKS_PER_SEC;
    double temps_h_a1 = ((double)(fin_h_a1 - debut_h_a1)) / CLOCKS_PER_SEC;

    printf("Temps d'exécution pour la recherche par auteur (cas inexistant) - LISTE CHAINEE : %f s\n", temps_lc_a1);
    printf("Temps d'exécution pour la recherche par auteur (cas inexistant) - TABLE HACHAGE : %f s\n", temps_h_a1);

    // Libération de la mémoire des structures créées
    liberer_biblio(biblio_lc);
    liberer_biblioH(biblio_h);
    liberer_biblio(biblio_a_lc);
    liberer_biblioH(biblio_a_h);

    return 0;
}
