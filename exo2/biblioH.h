#ifndef BIBLIOH_H
#define BIBLIOH_H

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
void supprimer_livreH(BiblioH* b, int num, char* titre, char* auteur);
BiblioH* recherche_livres_auteurH(BiblioH* b, char* auteur);
LivreH* recherche_par_titreH(BiblioH* b, char* titre);
LivreH* recherche_par_numH(BiblioH* b, int n);
void afficher_biblioH(BiblioH* b);
void afficher_livreH(LivreH *l);
BiblioH* fusion_biblioH(BiblioH* b1, BiblioH* b2);
BiblioH* livres_exemplairesH(BiblioH* b);
#endif