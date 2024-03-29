#ifndef BIBLIOLC_H
#define BIBLIOLC_H

typedef struct livre{
        int num;
        char* titre;
        char* auteur;
        struct livre * suiv;
        }Livre;

typedef struct{
        Livre* L;
        }Biblio;

Livre* creer_livre(int num, char* titre, char* auteur);
void liberer_livre(Livre* l);
Biblio* creer_biblio();
void liberer_biblio(Biblio* b);
void inserer_en_tete(Biblio* b, int num, char* titre, char* auteur);
void afficher_livre(Livre *l);
void afficher_biblio(Biblio* b);
Livre* recherche_par_num(Biblio* b, int n);
Livre* recherche_par_titre(Biblio* b, char* titre);
Biblio* recherche_livres_auteur(Biblio* b, char* auteur);
void supprimer_livre(Biblio* b, int num, char* titre, char* auteur);
Biblio* fusion_biblio(Biblio* b1, Biblio* b2);
Biblio* livres_exemplaires(Biblio* b);
#endif
