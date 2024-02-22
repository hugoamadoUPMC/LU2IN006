#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include "exo1/biblioLC.h"
#include "exo1/entreeSortieLC.h"

#include "exo2/biblioH.h"
#include "exo2/entreeSortieH.h"
#define TAILLE 3000
int main(int argc, char* argv[]) {
    // Déclaration des variables pour mesurer les temps d'exécution
    float temps_LC = 0, temps_H = 0;
    float temps_debut_LC, temps_fin_LC;
    float temps_debut_H, temps_fin_H;

    // Ouverture du fichier pour enregistrer les résultats
    FILE* fichier = fopen("graphique.txt", "w");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier \n");
        return 1;
    }

    // Boucle pour tester différentes tailles de bibliothèques
    for (int n = 0; n < TAILLE; n++) {
        // Chargement des entrées dans les deux structures de données pour la taille actuelle
        Biblio* bibliothequeLC = charger_n_entrees(argv[1], n);
        BiblioH* bibliothequeH = charger_n_entreesH(argv[1], n);
        temps_LC = 0;
        temps_H = 0;

        // Mesure du temps pour la liste chaînée
        temps_debut_LC = clock();
        livres_exemplaires(bibliothequeLC); // Recherche des livres exemplaires dans la bibliothèque chaînée
        temps_fin_LC = clock();

        // Mesure du temps pour la table de hachage
        temps_debut_H = clock();
        livres_exemplairesH(bibliothequeH); // Recherche des livres exemplaires dans la bibliothèque avec table de hachage
        temps_fin_H = clock();

        // Calcul des temps d'exécution en secondes
        temps_LC = ((double)(temps_fin_LC - temps_debut_LC)) / CLOCKS_PER_SEC;
        temps_H = ((double)(temps_fin_H - temps_debut_H)) / CLOCKS_PER_SEC;

        // Enregistrement des résultats dans le fichier
        fprintf(fichier, "%d %lf %lf\n", n, temps_LC, temps_H);

        // Libération de la mémoire des structures créées pour cette taille de bibliothèque
        liberer_biblio(bibliothequeLC);
        liberer_biblioH(bibliothequeH);
    }

    // Fermeture du fichier
    fclose(fichier);

    return 0;
}
