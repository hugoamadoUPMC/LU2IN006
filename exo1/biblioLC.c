#include "biblioLC.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Livre *creer_livre(int num, char *titre, char *auteur) {
  // Allocation de mémoire pour le livre
  Livre *l = (Livre *)malloc(sizeof(Livre));
  if (l == NULL) {
    printf("Erreur: échec de l'allocation de mémoire pour le livre\n");
    return NULL;
  }
  // Attribution des valeurs
  l->num = num;
  l->titre = strdup(titre);
  l->auteur = strdup(auteur);
  l->suiv = NULL;
  return l;
}

void liberer_livre(Livre *l) {
  if (l != NULL) {
    free(l->titre);
    free(l->auteur);
    free(l);
  }
}

Biblio *creer_biblio() {
  Biblio *b = (Biblio *)malloc(sizeof(Biblio));
  if (b == NULL) {
    printf("Erreur: échec de l'allocation de mémoire pour la bibliothèque\n");
    return NULL;
  }
  b->L = NULL;
  return b;
}

void liberer_biblio(Biblio *b) {
  if (b != NULL) {
    Livre *tmp = b->L;

    while (tmp) {
      Livre *suiv = tmp->suiv;
      liberer_livre(tmp);
      tmp = suiv;
    }
    free(b);
  }
}

void inserer_en_tete(Biblio *b, int num, char *titre, char *auteur) {
  // Vérification de la bibliothèque et des pointeurs d'entrée
  if (b == NULL || titre == NULL || auteur == NULL) {
    printf("Erreur: paramètres invalides pour l'insertion en tête\n");
    return;
  }

  Livre *l = creer_livre(num, titre, auteur);
  l->suiv = b->L;
  b->L = l;
}

void afficher_livre(Livre *l) {
  if (l != NULL){
    printf("%d %s %s \n", l->num, l->titre, l->auteur);
  }
  else{
    printf("Livre non trouvé ou invalide\n");
  }
}

void afficher_biblio(Biblio* b){
  if (b != NULL) {
    Livre* tmp = b->L;

    while(tmp){
      afficher_livre(tmp);
      tmp=tmp->suiv;
    }
  }
  else{
    printf("Bibliothèque non trouvée ou invalide\n");
  }
}

Livre* recherche_par_num(Biblio* b, int n){
  if (b != NULL) {
    Livre* tmp = b->L;
    while(tmp && tmp->num != n){
      tmp=tmp->suiv;
    }
    return tmp;
  }
  else{
    printf("Bibliothèque non trouvée ou invalide\n");
    return NULL;
  }
}