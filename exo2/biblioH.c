#include "biblioH.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int fonctionClef(char* auteur){
  //Initialisation de la valeur ASCII
  int res=0;
  int i=0;

  while(strcmp(&auteur[i],"\0")){
    //ajout de la valeur ASCII de chaque caractère jusque la fin du nom de l'auteur
    res+=auteur[i];
    i++;
    }

  return res;
  }

LivreH* creer_livreH(int num, char* titre, char* auteur){
  //allocation mémoire
  LivreH *l = (LivreH *)malloc(sizeof(LivreH));

  //ajout des attribus de livres
  l->clef = fonctionClef(auteur);
  l->num = num;
  l->titre = strdup(titre);
  l->auteur = strdup(auteur);
  l->suivant = NULL;

  return l;
  }

void liberer_livreH(LivreH *l) {
  if (l != NULL) {
    //libération des attribus dynamique
    free(l->titre);
    free(l->auteur);
    //libération du pointeur sur livre.
    free(l);
  }
}

BiblioH* creer_biblioH(int m){
  //allocation de biblio
  BiblioH* b = (BiblioH*) malloc(sizeof(BiblioH));

  //ajout des attribut de biblio
  b->m=m;
  b->nE = 0;
  //allocation de toutes les listes chainé de la table de hashage de taille m
  b->T = (LivreH**) calloc(m, sizeof(LivreH*));
  return b;
  }

void liberer_biblioH(BiblioH* b){
  LivreH *tmp;
  for(int i=0;i<b->m;i++){
    //On parcour tous les têtes de liste chaîné de la table de hashage
    tmp=b->T[i];
    while (tmp) {
      //On parcours tous les élément de chaque liste chaîné et on libère élément par élément
      LivreH *suiv = tmp->suivant;
      liberer_livreH(tmp);
      tmp = suiv;
    }
  }
  free(b);
  }

int fonctionHachage(int clef, int m){
  //Nombre d'or moins 1
  double a = (sqrt(5)-1)/2;
  //fonction de la table de Hashage
  return (int)(floor(m*(clef*a-floor(clef*a))));
  }

void inserer(BiblioH* b,int num,char* titre,char* auteur){
  //Création du livre
  LivreH* l=creer_livreH(num,titre,auteur);
  //Calcule de la futur position du livre dans la table
  int h=fonctionHachage(fonctionClef(auteur),b->m);
  //augmentation du nombre de livre
  b->nE++;
  //positionnement en tête
  LivreH** tmp=b->T;
  //Condition si la liste chaîné est vide
  if(tmp[h]==NULL){
    tmp[h]=l;
  }
  //Si elle contient au moins un élément
  else{
    l->suivant=tmp[h];
    tmp[h]=l;
  }
}

void afficher_livreH(LivreH *l) {
  //affiche le livre si il n'est pas null
  if (l != NULL){
    printf("%d %s %s \n", l->num, l->titre, l->auteur);
  }
  else{
    printf("Livre non trouvé ou invalide\n");
  }
}

void afficher_biblioH(BiblioH* b){
  if (b != NULL) {
    LivreH* tmp;
    for(int i=0;i<b->m;i++){
      tmp=b->T[i];
      while(tmp){
        afficher_livreH(tmp);
        tmp=tmp->suivant;
      }
    }
  }
  else{
    printf("Bibliothèque non trouvée ou invalide\n");
  }
}

LivreH* recherche_par_numH(BiblioH* b, int n){
  if (b != NULL) {
    LivreH* tmp;
    for(int i=0;i<b->m;i++){
      tmp=b->T[i];
      while(tmp && tmp->num != n){
        tmp=tmp->suivant;
      }
    }
    return tmp;
  }
  else{
    printf("Bibliothèque non trouvée ou invalide\n");
    return NULL;
  }
}

LivreH* recherche_par_titreH(BiblioH* b, char* titre){
  if (b != NULL) {
    LivreH* tmp;
    for(int i=0;i<b->m;i++){
      tmp=b->T[i];
      while(tmp && strcmp(tmp->titre,titre)){
        tmp=tmp->suivant;
      }
    }
    return tmp;
  }
  else{
    printf("Bibliothèque non trouvée ou invalide\n");
    return NULL;
  }
}

BiblioH* recherche_livres_auteurH(BiblioH* b, char* auteur){
  if (b != NULL) {
    BiblioH* res=creer_biblioH(b->m);
    LivreH* tmp;
    //positionnement au début de la liste chaîné en fonction du nom de l'auteur
    int h= fonctionHachage(fonctionClef(auteur),b->m);
    tmp=b->T[h];
    while(tmp){
      if(strcmp(tmp->auteur,auteur)){
        inserer(res,tmp->num,tmp->titre,tmp->auteur);
      }
      tmp=tmp->suivant;
    }
    return res;
  }
  else{
    printf("Bibliothèque non trouvée ou invalide\n");
    return NULL;
  }
}

void supprimer_livreH(BiblioH* b, int num, char* titre, char* auteur){
  if (b != NULL) {
    LivreH* tmp;
    int h= fonctionHachage(fonctionClef(auteur),b->m);
    tmp=b->T[h];
    while(tmp && num!=tmp->num && !strcmp(tmp->auteur,auteur) && !strcmp(tmp->titre,titre)){
      tmp=tmp->suivant;
      }
    if(tmp!=NULL){
      liberer_livreH(tmp);
    }
  }
  else{
    printf("Bibliothèque non trouvée ou invalide\n");
    return;
  }
}

BiblioH* fusion_biblioH(BiblioH* b1, BiblioH* b2){
  if(b1!=NULL || b2!=NULL){
    if(b1!=NULL){
      LivreH* tmp;
      for(int i=0;i<b2->m;i++){
        tmp=b2->T[i];
        while(tmp){
          inserer(b1,tmp->num,tmp->titre,tmp->auteur);
        }
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
