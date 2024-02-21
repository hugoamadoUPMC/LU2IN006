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