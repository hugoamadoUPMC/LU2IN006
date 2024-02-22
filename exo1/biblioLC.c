#include "biblioLC.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Fonction pour créer un livre avec les détails spécifiés
Livre *creer_livre(int num, char *titre, char *auteur) {
    Livre *l = (Livre *)malloc(sizeof(Livre)); // Allocation de mémoire pour le livre
    if (l == NULL) {
        printf("Erreur: échec de l'allocation de mémoire pour le livre\n");
        return NULL;
    }
    l->num = num; // Attribution des valeurs
    l->titre = strdup(titre);
    l->auteur = strdup(auteur);
    l->suiv = NULL;
    return l;
}

// Fonction pour libérer la mémoire allouée pour un livre
void liberer_livre(Livre *l) {
    if (l != NULL) {
        free(l->titre);
        free(l->auteur);
        free(l);
    }
}

// Fonction pour créer une bibliothèque de livres
Biblio *creer_biblio() {
    Biblio *b = (Biblio *)malloc(sizeof(Biblio)); // Allocation de mémoire pour la bibliothèque
    if (b == NULL) {
        printf("Erreur: échec de l'allocation de mémoire pour la bibliothèque\n");
        return NULL;
    }
    b->L = NULL; // Initialisation de la liste des livres à NULL
    return b;
}

// Fonction pour libérer la mémoire allouée pour une bibliothèque de livres
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

// Fonction pour insérer un livre au début de la bibliothèque
void inserer_en_tete(Biblio *b, int num, char *titre, char *auteur) {
    if (b == NULL || titre == NULL || auteur == NULL) {
        printf("Erreur: paramètres invalides pour l'insertion en tête\n");
        return;
    }
    Livre *l = creer_livre(num, titre, auteur); // Création du livre
    l->suiv = b->L; // Insertion en tête
    b->L = l;
}

// Fonction pour afficher les détails d'un livre
void afficher_livre(Livre *l) {
    if (l != NULL) {
        printf("%d %s %s \n", l->num, l->titre, l->auteur);
    } else {
        printf("Livre non trouvé ou invalide\n");
    }
}

// Fonction pour afficher tous les livres dans la bibliothèque
void afficher_biblio(Biblio *b) {
    if (b != NULL) {
        Livre *tmp = b->L;
        while (tmp) {
            afficher_livre(tmp);
            tmp = tmp->suiv;
        }
    } else {
        printf("Bibliothèque non trouvée ou invalide\n");
    }
}

// Fonction pour rechercher un livre par son numéro dans la bibliothèque
Livre *recherche_par_num(Biblio *b, int n) {
    if (b != NULL) {
        Livre *tmp = b->L;
        while (tmp && tmp->num != n) {
            tmp = tmp->suiv;
        }
        return tmp;
    } else {
        printf("Bibliothèque non trouvée ou invalide\n");
        return NULL;
    }
}

// Fonction pour rechercher un livre par son titre dans la bibliothèque
Livre *recherche_par_titre(Biblio *b, char *titre) {
    if (b != NULL) {
        Livre *tmp = b->L;
        while (tmp && strcmp(tmp->titre, titre)) {
            tmp = tmp->suiv;
        }
        return tmp;
    } else {
        printf("Bibliothèque non trouvée ou invalide\n");
        return NULL;
    }
}

// Fonction pour créer une nouvelle bibliothèque contenant tous les livres d'un auteur spécifique
Biblio *recherche_livres_auteur(Biblio *b, char *auteur) {
    if (b != NULL) {
        Biblio *res = creer_biblio(); // Création de la bibliothèque de résultats
        Livre *tmp = b->L;
        while (tmp) {
            if (strcmp(tmp->auteur, auteur) == 0) { // Si l'auteur correspond
                inserer_en_tete(res, tmp->num, tmp->titre, tmp->auteur); // Insérer le livre dans la nouvelle bibliothèque
            }
            tmp = tmp->suiv;
        }
        return res;
    } else {
        printf("Bibliothèque non trouvée ou invalide\n");
        return NULL;
    }
}

// Fonction pour supprimer un livre de la bibliothèque
void supprimer_livre(Biblio *b, int num, char *titre, char *auteur) {
    if (b != NULL) {
        Livre *prec = NULL;
        Livre *cour = b->L;
        while (cour && (cour->num != num || strcmp(cour->auteur, auteur) != 0 || strcmp(cour->titre, titre) != 0)) {
            prec = cour;
            cour = cour->suiv;
        }
        if (cour != NULL) {
            if (prec == NULL) {
                b->L = cour->suiv;
            } else {
                prec->suiv = cour->suiv;
            }
            liberer_livre(cour); // Libérer le livre supprimé
        }
    } else {
        printf("Bibliothèque non trouvée ou invalide\n");
        return;
    }
}

// Fonction pour fusionner deux bibliothèques de livres
Biblio *fusion_biblio(Biblio *b1, Biblio *b2) {
    if (b1 != NULL && b2 != NULL) {
        Livre *tmp = b2->L;
        while (tmp) {
            inserer_en_tete(b1, tmp->num, tmp->titre, tmp->auteur); // Insérer les livres de la deuxième bibliothèque dans la première
            tmp = tmp->suiv;
        }
        return b1;
    } else {
        printf("Bibliothèques non trouvées ou invalides\n");
        return NULL;
    }
}

// Fonction pour trouver les livres exemplaires dans une bibliothèque
Biblio *livres_exemplaires(Biblio *b) {
    Livre *tmp = b->L;
    Livre *test = b->L;
    Biblio *res = creer_biblio(); // Création de la bibliothèque de résultats
    while (tmp) {
        test = b->L;
        while (test && !(!strcmp(test->titre, tmp->titre) && !strcmp(test->auteur, tmp->auteur) && tmp->num != test->num)){
            test = test->suiv;
        }
        if (test) {
            inserer_en_tete(res, tmp->num, tmp->titre, tmp->auteur); // Insérer le livre dans la nouvelle bibliothèque
        }
        tmp = tmp->suiv;
    }
    return res;
}
