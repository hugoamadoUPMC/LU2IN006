#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include "exo1/biblioLC.h"
#include "exo1/entreeSortieLC.h"

#include "exo2/biblioH.h"
#include "exo2/entreeSortieH.h"

int main(int argc, char* argv[]) {
	
	float temps_LC = 0, temps_H = 0;
	float temps_debut_LC, temps_fin_LC;
	float temps_debut_H, temps_fin_H;

	FILE* fichier = fopen("graphique.txt", "w");
	if (fichier == NULL) {
		printf("Erreur lors de l'ouverture du fichier \n");
		exit(1);
	}

	for (int n = 1000; n < 20000; n = n + 10) {
		Bibliotheque* bibliothequeLC = charger_n_entrees(argv[1], n);
		BiblioHachage* bibliothequeH = charger_n_entrees(argv[1], n);
		temps_LC = 0;
		temps_H = 0;
		// LISTE CHAINEE
		temps_debut_LC = clock();

		livres_exemplaires(bibliothequeLC);

		temps_fin_LC = clock();

		// TABLE DE HACHAGE
		temps_debut_H = clock();

		livres_identiquesH(bibliothequeH);

		temps_fin_H = clock();
		temps_LC = ((double)(temps_fin_LC - temps_debut_LC)) / CLOCKS_PER_SEC;
		temps_H = ((double)(temps_fin_H - temps_debut_H)) / CLOCKS_PER_SEC;
		fprintf(fichier, "%d %lf %lf\n", n, temps_LC, temps_H);
		liberer_biblio(bibliothequeLC);
		liberer_biblioH(bibliothequeH);
	}
	
	fclose(fichier);

	return 0;
}