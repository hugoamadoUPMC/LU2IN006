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

Livre* recherche_par_titre(Biblio* b, char* titre){
  if (b != NULL) {
    Livre* tmp = b->L;
    while(tmp && !strcmp(tmp->titre,titre)){
      tmp=tmp->suiv;
    }
    return tmp;
  }
  else{
    printf("Bibliothèque non trouvée ou invalide\n");
    return NULL;
  }
}

Biblio* recherche_livres_auteur(Biblio* b, char* auteur){
  if (b != NULL) {
    Biblio* res=creer_biblio();
    Livre* tmp = b->L;
    while(tmp){
      if(strcmp(tmp->auteur,auteur)){
        inserer_en_tete(b,tmp->num,tmp->titre,tmp->auteur);
      }
      tmp=tmp->suiv;
    }
    return b;
  }
  else{
    printf("Bibliothèque non trouvée ou invalide\n");
    return NULL;
  }
}

void supprimer_livre(Biblio* b, int num, char* titre, char* auteur){
  if (b != NULL) {
    Livre* tmp = b->L;
    while(tmp && num!=tmp->num && !strcmp(tmp->auteur,auteur) && !strcmp(tmp->titre,titre)){
      tmp=tmp->suiv;
      }
    if(tmp!=NULL){
      liberer_livre(tmp);
    }
  }
  else{
    printf("Bibliothèque non trouvée ou invalide\n");
    return NULL;
  }
}

Biblio* fusion_biblio(Biblio* b1, Biblio* b2){
  if(b1!=NULL || b2!=NULL){
    if(b1!=NULL){
      Livre* tmp=b2->L;
      while(tmp){
        inserer_en_tete(b1,tmp->num,tmp->titre,tmp->auteur);
      }
      return b1;
    }
    else{
      return b2;
    }
  }
  else{
    printf("Bibliothèques non trouvées ou invalides\n");
    return NULL;
  }
}