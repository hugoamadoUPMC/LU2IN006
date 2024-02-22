#include "entreeSortieLC.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

Biblio* charger_n_entrees(char* nomfic, int n){
    FILE *f = fopen(nomfic,"r"); // Ouverture du fichier en mode lecture
    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier %s\n", nomfic);
        return NULL;
    }
    Biblio *bi = creer_biblio(); // Création d'une nouvelle bibliothèque
    char buffer[256];
    int num;
    char maj[256];
    char min[256];
    // Lecture des entrées du fichier ligne par ligne
    while(fgets(buffer, sizeof(buffer), f) && n > 0){
        // Extraction des informations de la ligne lue
        if(sscanf(buffer, "%d %256s %256s\n", &num, maj, min) == 3) {
            inserer_en_tete(bi, num, maj, min); // Insertion du livre dans la bibliothèque
            n--; // Décrémentation du compteur d'entrées restantes
        }
    }
    fclose(f); // Fermeture du fichier
    return bi; // Retour de la bibliothèque créée
}

void enregistrer_biblio(Biblio *b, char* nomfic){
    FILE *f = fopen(nomfic, "w"); // Ouverture du fichier en mode écriture
    if (f == NULL) {
        printf("Erreur d'ouverture : %s\n", nomfic);
        return;
    } 

    Livre *current = b->L;
    // Parcours de chaque livre dans la bibliothèque
    while (current != NULL) {
        // Vérification des pointeurs titre et auteur pour éviter les erreurs
        if (current->titre != NULL && current->auteur != NULL) {
            // Écriture des informations du livre dans le fichier
            fprintf(f, "%d %s %s\n", current->num, current->titre, current->auteur);
        }
        current = current->suiv; // Passage au livre suivant dans la liste chaînée
    }

    fclose(f); // Fermeture du fichier après l'écriture
}
