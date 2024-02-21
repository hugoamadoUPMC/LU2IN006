#include "biblioH.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int fonctionClef(char* auteur){
  int res=0;
  int i=0;
  while(strcmp(&auteur[i],"\0")){
    res+=auteur[i];
    i++;
    }
  return res;
  }

LivreH* creer_livreH(int num, char* titre, char* auteur){
  LivreH *l = (LivreH *)malloc(sizeof(LivreH));
  l->clef = fonctionClef(auteur);
  l->num = num;
  l->titre = strdup(titre);
  l->auteur = strdup(auteur);
  return l;
  }

void liberer_livreH(LivreH *l) {
  free(l->titre);
  free(l->auteur);
  free(l);
  }

BiblioH* creer_biblioH(int m){
  BiblioH* b = (BiblioH*) malloc(sizeof(BiblioH));
  b->m=m;
  b->T=(LivreH**) malloc(sizeof(LivreH*)*m);
  return b;
  }

void liberer_biblioH(BiblioH* b){
  LivreH *tmp = *b->T;
  while (tmp) {
    LivreH *suiv = tmp->suivant;
    liberer_livreH(tmp);
    tmp = suiv;
    }
  free(b);
  }

int fonctionHachage(int clef, int m){
    int res=0;
    double a = (sqrt(5)-1)/2;
    res=floor(m*(clef*a-floor(clef*a)));
    return res;
    }

void inserer(BiblioH* b,int num,char* titre,char* auteur){
    LivreH* l=creer_livreH(num,titre,auteur);
    int h=fonctionHachage(fonctionClef(auteur),b->m);
    b->nE++;
    LivreH** tmp=b->T;
    if(tmp[h]==NULL){
        tmp[h]=l;
        }
    else{
        l->suivant=tmp[h];
        tmp[h]=l;
        }
    }

void afficher_livreH(LivreH *l) {
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
        afficher_livre(tmp);
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
    BiblioH* res=creer_biblio();
    LivreH* tmp;
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
      liberer_livre(tmp);
    }
  }
  else{
    printf("Bibliothèque non trouvée ou invalide\n");
    return NULL;
  }
}

BiblioH* fusion_biblioH(BiblioH* b1, BiblioH* b2){
  if(b1!=NULL || b2!=NULL){
    if(b1!=NULL){
      LivreH* tmp;
      for(int i=0;i<b2->m;i++){
        tmp=b2->T[i];
        while(tmp){
          inserer_en_tete(b1,tmp->num,tmp->titre,tmp->auteur);
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
