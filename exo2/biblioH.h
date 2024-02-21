#ifndef _BIBLIOH_H_
#define _BIBLIOH_H_

typedef struct livreh {
  int clef ;
  int num;
  char* titre;
  char* auteur;
  struct livreh * suivant ;
  }LivreH;

typedef struct table {
  int nE ; /*nombre d’elements contenus dans la table de hachage */
  int m ; /*taille de la table de hachage */
  LivreH** T ; /*table de hachage avec resolution des collisions par chainage */
  } BiblioH ;

int fonctionClef(char* auteur);
LivreH *creer_livreH(int num, char *titre, char *auteur);
void liberer_livreH(LivreH *l);
BiblioH* creer_biblioH(int m);
void liberer_biblioH(BiblioH* b);
int fonctionHachage(int clef, int m);
void inserer(BiblioH* b,int num,char* titre,char* auteur);

#endif