#include "biblioLC.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Livre *creer_livre(int num, char *titre, char *auteur) {
  Livre *l = (Livre *)malloc(sizeof(Livre));
  l->num = num;
  l->titre = strdup(titre);
  l->auteur = strdup(auteur);
  return l;
}

void liberer_livre(Livre *l) {
  free(l->titre);
  free(l->auteur);
  free(l);
}

Biblio *creer_biblio() {
  Biblio *b = (Biblio *)malloc(sizeof(Biblio));
  return b;
}

void liberer_biblio(Biblio *b) {
  Livre *tmp = b->L;
  while (tmp) {
    Livre *suiv = tmp->suiv;
    liberer_livre(tmp);
    tmp = suiv;
  }
  free(b);
}

void inserer_en_tete(Biblio *b, int num, char *titre, char *auteur) {
  Livre *l = creer_livre(num, titre, auteur);
  l->suiv = b->L;
  b->L = l;
}

void afficher_livre(Livre *l) {
  printf("%d %s %s \n", l->num, l->titre, l->auteur);
  }

void afficher_biblio(Biblio* b){
  Livre* tmp=b->L;
  while(tmp){
    afficher_livre(tmp);
    tmp=tmp->suiv;
    }
  }

Livre* recherche_par_num(Biblio* b, int n){
  Livre* tmp=b->L;
  while(tmp || tmp->num!=n){
    tmp=tmp->suiv;
    }
  return tmp;
  }