#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "exo1/biblioLC.h"
#include "exo1/entreeSortieLC.h"

#include "exo2/biblioH.h"
#include "exo2/entreeSortieH.h"

int main(int argc, char* argv[]){
    if(argc != 3){
        printf("Il faut 2 arguments : nom_du_fichier et nb_de_lignes.\n");
        return 0;
    }

    /* Création des bibliothèques et mesure du temps d'exécution entre les deux structures pour la fonction de chargement */

    printf("Calcul du temps d'exécution de la fonction charger_n_entrees :\n");

    clock_t tps_DebutLC = clock();
    Biblio* biblioLC = charger_n_entrees(argv[1], atoi(argv[2]));
    clock_t tps_FinLC = clock();

    clock_t tps_DebutH = clock();
    BiblioH* biblioH = charger_n_entreesH(argv[1], atoi(argv[2]));
    clock_t tps_FinH = clock();

    double tps_TotalLC = ((double)(tps_FinLC - tps_DebutLC)) / CLOCKS_PER_SEC;
    double tps_TotalH = ((double)(tps_FinH - tps_DebutH)) / CLOCKS_PER_SEC;

    printf ("Temps d'exécution de la fonction charger_n_entrees pour LISTE CHAINEE : %f s\n", tps_TotalLC);
    printf ("Temps d'exécution de la fonction charger_n_entrees pour TABLE HACHAGE : %f s\n", tps_TotalH);

    /* Mesure du temps pour les différentes fonctions de recherche d'ouvrages entre les deux structures */

    /* 1 - Recherche d'un ouvrage par numéro */
    /* Cas où l'ouvrage est présent dans la bibliothèque */
    printf("Calcul du temps d'exécution de la fonction recherche d'un ouvrage par son numéro (cas existant) :\n");

    tps_DebutLC = clock();
    rechercher_par_num(biblioLC, 5);
    tps_FinLC = clock();

    tps_DebutH = clock();
    rechercher_par_numH(biblioH, 5);
    tps_FinH = clock();

    double tps_TotalLC_N = ((double)(tps_FinLC - tps_DebutLC)) / CLOCKS_PER_SEC;
    double tps_TotalH_N = ((double)(tps_FinH - tps_DebutH)) / CLOCKS_PER_SEC;

    printf ("Temps d'exécution de la fonction recherche_livre_num pour LISTE CHAINEE : %f s\n", tps_TotalLC_N);
    printf ("Temps d'exécution de la fonction recherche_livre_num pour TABLE HACHAGE : %f s\n", tps_TotalH_N);

    /* Cas où l'ouvrage est absent de la bibliothèque */
    printf("Calcul du temps d'exécution de la fonction recherche d'un ouvrage par son numéro (cas absent) :\n");

    tps_DebutLC = clock();
    rechercher_par_num(biblioLC, 4555666);
    tps_FinLC = clock();

    tps_DebutH = clock();
    rechercher_par_numH(biblioH, 4555666);
    tps_FinH = clock();

    double tps_TotalLC_N1 = ((double)(tps_FinLC - tps_DebutLC)) / CLOCKS_PER_SEC;
    double tps_TotalH_N1 = ((double)(tps_FinH - tps_DebutH)) / CLOCKS_PER_SEC;

    printf ("Temps d'exécution de la fonction recherche_livre_num pour LISTE CHAINEE : %f s\n", tps_TotalLC_N1);
    printf ("Temps d'exécution de la fonction recherche_livre_num pour TABLE HACHAGE : %f s\n", tps_TotalH_N1);

    /* 2 - Recherche d'un ouvrage par le titre du livre */
    /* Cas où l'ouvrage est présent dans la bibliothèque */
    printf("Calcul du temps d'exécution de la fonction recherche d'un ouvrage par son titre (cas existant) :\n");

    tps_DebutLC = clock();
    rechercher_par_titre(biblioLC, "DJEQV");
    tps_FinLC = clock();

    tps_DebutH = clock();
    rechercher_par_titreH(biblioH, "DJEQV");
    tps_FinH = clock();

    double tps_TotalLC_T = ((double)(tps_FinLC - tps_DebutLC)) / CLOCKS_PER_SEC;
    double tps_TotalH_T = ((double)(tps_FinH - tps_DebutH)) / CLOCKS_PER_SEC;

    printf ("Temps d'exécution de la fonction recherche_livre_titre pour LISTE CHAINEE : %f s\n", tps_TotalLC_T);
    printf ("Temps d'exécution de la fonction recherche_livre_titre pour TABLE HACHAGE : %f s\n", tps_TotalH_T);

    /* Cas où l'ouvrage est absent de la bibliothèque */
    printf("Calcul du temps d'exécution de la fonction recherche d'un ouvrage par son titre (cas absent) :\n");

    tps_DebutLC = clock();
    rechercher_par_titre(biblioLC, "Splendides");
    tps_FinLC = clock();

    tps_DebutH = clock();
    rechercher_par_titreH(biblioH, "Splendides");
    tps_FinH = clock();

    double tps_TotalLC_T1 = ((double)(tps_FinLC - tps_DebutLC)) / CLOCKS_PER_SEC;
    double tps_TotalH_T1 = ((double)(tps_FinH - tps_DebutH)) / CLOCKS_PER_SEC;

    printf ("Temps d'exécution de la fonction recherche_livre_titre pour LISTE CHAINEE : %f s\n", tps_TotalLC_T1);
    printf ("Temps d'exécution de la fonction recherche_livre_titre pour TABLE HACHAGE : %f s\n", tps_TotalH_T1);

    /* 3 - Recherche d'ouvrages par le nom d'auteur */
    /* Cas où les ouvrages sont présents dans la bibliothèque */
    printf("Calcul du temps d'exécution de la fonction recherche d'ouvrages par le nom d'auteur (cas existant) :\n");

    tps_DebutLC = clock();
    Biblio* b1 = livres_par_auteur(biblioLC, "pslgvlcsa");
    tps_FinLC = clock();

    tps_DebutH = clock();
    BiblioH* b2 = livres_par_auteurH(biblioH, "pslgvlcsa");
    tps_FinH = clock();

    double tps_TotalLC_A = ((double)(tps_FinLC - tps_DebutLC)) / CLOCKS_PER_SEC;
    double tps_TotalH_A = ((double)(tps_FinH - tps_DebutH)) / CLOCKS_PER_SEC;

    printf ("Temps d'exécution de la fonction recherche_livre_auteur pour LISTE CHAINEE : %f s\n", tps_TotalLC_A);
    printf ("Temps d'exécution de la fonction recherche_livre_auteur pour TABLE HACHAGE : %f s\n", tps_TotalH_A);

    /* Cas où les ouvrages sont absents de la bibliothèque */
    printf("Calcul du temps d'exécution de la fonction recherche d'ouvrages par le nom d'auteur (cas absents):\n");

    tps_DebutLC = clock();
    Biblio* b3 = livres_par_auteur(biblioLC, "Bronte");
    tps_FinLC = clock();

    tps_DebutH = clock();
    BiblioH* b4 = livres_par_auteurH(biblioH, "Bronte");
    tps_FinH = clock();

    double tps_TotalLC_A1 = ((double)(tps_FinLC - tps_DebutLC)) / CLOCKS_PER_SEC;
    double tps_TotalH_A1 = ((double)(tps_FinH - tps_DebutH)) / CLOCKS_PER_SEC;

    printf ("Temps d'exécution de la fonction recherche_livre_auteur pour LISTE CHAINEE : %f s\n", tps_TotalLC_A1);
    printf ("Temps d'exécution de la fonction recherche_livre_auteur pour TABLE HACHAGE : %f s\n", tps_TotalH_A1);

    /* Libération de la mémoire des structures créées */

    liberer_biblioLC(b1);
    liberer_biblioH(b2);
    liberer_biblioLC(b3);
    liberer_biblioH(b4);
    liberer_biblioLC(biblioLC);
    liberer_biblioH(biblioH);
    return 0;
}
