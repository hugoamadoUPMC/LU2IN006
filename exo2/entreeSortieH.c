#include "entreeSortieH.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

BiblioH* charger_n_entreesH(char* nomfic, int n){
    FILE *f = fopen(nomfic,"r");
    if (f==NULL) {
        printf("Erreur lors de l'ouverture du fichier %s\n", nomfic);
        return NULL;
    }
    BiblioH *bi = creer_biblio();
    char buffer[256];
    int num;
    char maj[256];
    char min[256];
    while(fgets(buffer, sizeof(buffer), f) && n > 0){
        if(sscanf(buffer, "%d %256s %256s\n", &num, maj, min)==3);
        inserer(bi, num, maj, min);
        n--;
    }
    fclose(f);
    return bi;
    
}

void enregistrer_biblioH(BiblioH *b, char* nomfic){
    FILE *f = fopen(nomfic, "w"); // ouvrir un fichier en mode ecriture
    if (f == NULL) {
        printf("Erreur d'ouverture : %s\n", nomfic);
        return;
    } 

    LivreH *current;
    for(int i=0;i<b->m;i++){
        current=b->T[i];
        while (current != NULL) {
            if (current->titre != NULL && current->auteur != NULL) {
                fprintf(f, "%d %s %s\n", current->num, current->titre, current->auteur);
            }
            current = current->suivant;
        }
    }

    fclose(f);
}