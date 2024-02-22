#include "biblioH.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Fonction de hachage pour générer la clé à partir du nom de l'auteur
int fonctionClef(char* auteur) {
    int res = 0;
    int i = 0;

    // Parcourt la chaîne de caractères de l'auteur jusqu'au caractère de fin de chaîne '\0'
    while(auteur[i] != '\0') {
        // Ajoute la valeur ASCII de chaque caractère au résultat
        res += auteur[i];
        i++;
    }
    return res;
}

// Crée un nouveau livre dans la bibliothèque
LivreH* creer_livreH(int num, char* titre, char* auteur) {
    LivreH *l = (LivreH *)malloc(sizeof(LivreH));

    // Initialise les attributs du livre
    l->clef = fonctionClef(auteur);
    l->num = num;
    l->titre = strdup(titre); // Alloue de la mémoire et copie le titre
    l->auteur = strdup(auteur); // Alloue de la mémoire et copie l'auteur
    l->suivant = NULL;

    return l;
}

// Libère la mémoire allouée pour un livre
void liberer_livreH(LivreH *l) {
    if (l != NULL) {
        // Libère la mémoire allouée pour le titre et l'auteur
        free(l->titre);
        free(l->auteur);
        // Libère la mémoire allouée pour le livre
        free(l);
    }
}

// Crée une nouvelle bibliothèque de hachage
BiblioH* creer_biblioH(int m) {
    BiblioH* b = (BiblioH*) malloc(sizeof(BiblioH));

    // Initialise les attributs de la bibliothèque
    b->m = m;
    b->nE = 0;
    // Alloue de la mémoire pour le tableau de pointeurs de livres
    b->T = (LivreH**) calloc(m, sizeof(LivreH*));

    return b;
}

// Libère la mémoire allouée pour une bibliothèque de hachage
void liberer_biblioH(BiblioH* b) {
    LivreH *tmp;
    // Parcourt chaque case du tableau de pointeurs
    for(int i = 0; i < b->m; i++) {
        tmp = b->T[i];
        // Parcourt chaque liste chaînée et libère les livres
        while (tmp != NULL) {
            LivreH *suiv = tmp->suivant;
            liberer_livreH(tmp);
            tmp = suiv;
        }
    }
    // Libère le tableau de pointeurs
    free(b->T);
    // Libère la mémoire allouée pour la bibliothèque
    free(b);
}

// Fonction de hachage pour calculer l'indice dans le tableau
int fonctionHachage(int clef, int m) {
    double a = (sqrt(5) - 1) / 2;
    return (int)(floor(m * (clef * a - floor(clef * a))));
}

// Insère un livre dans la bibliothèque de hachage
void inserer(BiblioH* b, int num, char* titre, char* auteur) {
    LivreH* l = creer_livreH(num, titre, auteur);
    int h = fonctionHachage(fonctionClef(auteur), b->m);

    // Insère en tête de la liste chaînée
    l->suivant = b->T[h];
    b->T[h] = l;
    b->nE++; // Incrémente le nombre de livres
}

// Affiche les détails d'un livre
void afficher_livreH(LivreH *l) {
    if (l != NULL) {
        printf("%d %s %s \n", l->num, l->titre, l->auteur);
    } else {
        printf("Livre non trouvé ou invalide\n");
    }
}

// Affiche tous les livres de la bibliothèque de hachage
void afficher_biblioH(BiblioH* b) {
    if (b != NULL) {
        LivreH* tmp;
        for(int i = 0; i < b->m; i++) {
            tmp = b->T[i];
            while(tmp != NULL) {
                afficher_livreH(tmp);
                tmp = tmp->suivant;
            }
        }
    } else {
        printf("Bibliothèque non trouvée ou invalide\n");
    }
}

// Recherche un livre par son numéro dans la bibliothèque de hachage
LivreH* recherche_par_numH(BiblioH* b, int n) {
    if (b != NULL) {
        LivreH* tmp;
        for(int i = 0; i < b->m; i++) {
            tmp = b->T[i];
            while(tmp != NULL && tmp->num != n) {
                tmp = tmp->suivant;
            }
            if (tmp != NULL) {
                return tmp;
            }
        }
    }
    printf("Livre non trouvé ou invalide\n");
    return NULL;
}

// Recherche un livre par son titre dans la bibliothèque de hachage
LivreH* recherche_par_titreH(BiblioH* b, char* titre) {
    if (b != NULL) {
        LivreH* tmp;
        for(int i = 0; i < b->m; i++) {
            tmp = b->T[i];
            while(tmp != NULL && strcmp(tmp->titre, titre) != 0) {
                tmp = tmp->suivant;
            }
            if (tmp != NULL) {
                return tmp;
            }
        }
    }
    printf("Livre non trouvé ou invalide\n");
    return NULL;
}

// Crée une nouvelle bibliothèque contenant les livres d'un auteur spécifique
BiblioH* recherche_livres_auteurH(BiblioH* b, char* auteur) {
    if (b != NULL) {
        BiblioH* res = creer_biblioH(b->m/2);
        LivreH* tmp;
        for(int i = 0; i < b->m; i++) {
            tmp = b->T[i];
            while(tmp != NULL) {
                if(strcmp(tmp->auteur, auteur) == 0) {
                    inserer(res, tmp->num, tmp->titre, tmp->auteur);
                }
                tmp = tmp->suivant;
            }
        }
        return res;
    } else {
        printf("Bibliothèque non trouvée ou invalide\n");
        return NULL;
    }
}

// Supprime un livre de la bibliothèque de hachage
void supprimer_livreH(BiblioH* b, int num, char* titre, char* auteur) {
    if (b != NULL) {
        int h = fonctionHachage(fonctionClef(auteur), b->m);
        LivreH* prec = NULL;
        LivreH* cour = b->T[h];
        while(cour != NULL && (cour->num != num || strcmp(cour->auteur, auteur) != 0 || strcmp(cour->titre, titre) != 0)) {
            prec = cour;
            cour = cour->suivant;
        }
        if (cour != NULL) {
            if (prec == NULL) {
                b->T[h] = cour->suivant;
            } else {
                prec->suivant = cour->suivant;
            }
            liberer_livreH(cour);
        }
    } else {
        printf("Bibliothèque non trouvée ou invalide\n");
    }
}

// Fusionne deux bibliothèques de hachage en une seule
BiblioH* fusion_biblioH(BiblioH* b1, BiblioH* b2) {
    if (b1 != NULL && b2 != NULL) {
        LivreH* tmp;
        for(int i = 0; i < b2->m; i++) {
            tmp = b2->T[i];
            while(tmp != NULL) {
                inserer(b1, tmp->num, tmp->titre, tmp->auteur);
                tmp = tmp->suivant;
            }
        }
        return b1;
    } else {
        printf("Bibliothèques non trouvées ou invalides\n");
        return NULL;
    }
}

// Trouve les livres qui ont des exemplaires dans la bibliothèque de hachage
BiblioH* livres_exemplairesH(BiblioH* b) {
    LivreH* tmp;
    LivreH* test;
    BiblioH* res = creer_biblioH(b->m/2);
    for(int i = 0; i < b->m; i++) {
        tmp = b->T[i];
        while(tmp != NULL) {
            test = b->T[i];
            while(test != NULL && (strcmp(test->titre, tmp->titre) != 0 || strcmp(test->auteur, tmp->auteur) != 0 || tmp->num == test->num)) {
                test = test->suivant;
            }
            if (test != NULL) {
                inserer(res, tmp->num, tmp->titre, tmp->auteur);
            }
            tmp = tmp->suivant;
        }
    }
    return res;
}
