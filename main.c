#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "exo1/biblioLC.h"
#include "exo1/entreeSortieLC.h"

#include "exo2/biblioH.h"
#include "exo2/entreeSortieH.h"

// Fonction pour afficher le menu
void menu() {
    printf("\n");
    printf("0-sortie du programme\n");
    printf("1-Affichage\n");
    printf("2-Inserer ouvrage\n");
    printf("3-Recherche d’un ouvrage par son numéro\n");
    printf("4-Recherche d’un ouvrage par son titre\n");
    printf("5-Recherche de tous les livres d’un même auteur (retourne une bibliothèque\n");
    printf("6-Suppression d’un ouvrage (à partir de son numéro, son auteur et son titre\n");
    printf("7-fusion de deux bibliothèques\n");
    printf("8-recherche de tous les ouvrages avec plusieurs exemplaires\n");
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <nom_fichier> <nombre_lignes>\n", argv[0]);
        return 1;
    }
    
    // Charger les lignes dans la bibliothèque avec liste chaînée et table de hachage
    Biblio* bC = charger_n_entrees(argv[1], atoi(argv[2]));
    BiblioH* bH = charger_n_entreesH(argv[1], atoi(argv[2]));

    int rep;
    int cas;
    char buffer[256];
    
    // Boucle principale pour le menu
    do {
        printf("Veuillez ecrire le numero du gestion d'une bibliothèque:\n 1.Gestion d’une bibliothèque avec une liste chaı̂née de struct \n 2.Gestion d’une bibliothèque avec une table de hachage.\n");
        fgets(buffer, 256, stdin);
        rep = atoi(buffer);
        
        switch (rep) {
            case 1:
                do {
                    printf("\nGestion de la bibliothèque avec la liste chainée\n");		    
                    menu(); // Afficher le menu
                    fgets(buffer, 256, stdin);
                    cas = atoi(buffer);
                    
                    switch (cas) {
                        case 1: // Affichage
                            printf("Affichage: \n");
                            afficher_biblio(bC);
                            break;
                        case 2: // Insertion d'un ouvrage
                            int num;
                            char titre[256];
                            char auteur[256];
                            printf("Veuillez ecrire le numero, le titre, et l'auteur de l'ouvrage.\n");
                            fgets(buffer, 256, stdin);
                            sscanf(buffer, "%d %s %s", &num, titre, auteur);
                            inserer_en_tete(bC, num, titre, auteur);
                            afficher_biblio(bC);
                            printf("Ajout fait.\n");
                            break;
                        case 3: // Recherche par numéro
                            printf("Veuillez ecrire le numero de l'ouvrage recherchée\n");
                            fgets(buffer, 256, stdin);
                            sscanf(buffer, "%d", &num);
                            afficher_livre(recherche_par_num(bC, num));
                            break;
                        case 4: // Recherche par titre
                            printf("Veuillez ecrire le titre de l'ouvrage recherchée\n");
                            fgets(buffer, 256, stdin);
                            sscanf(buffer, "%s", titre);
                            afficher_livre(recherche_par_titre(bC, titre));
                            break;
                        case 5: // Recherche par auteur
                            printf("Veuillez ecrire le nom de l'auteur\n");
                            fgets(buffer, 256, stdin);
                            sscanf(buffer, "%s", auteur);
                            afficher_biblio(recherche_livres_auteur(bC, auteur));
                            break;
                        case 6: // Suppression d'un ouvrage
                            printf("Veuillez ecrire le numero, le titre, et l'auteur de l'ouvrage que vous voulez supprimer.\n");
                            fgets(buffer, 256, stdin);
                            sscanf(buffer, "%d %s %s", &num, titre, auteur);
                            supprimer_livre(bC, num, titre, auteur);
                            printf("suppresion terminée.\n");
                            break;
                        case 7: // Fusion de deux bibliothèques
                            printf("Veuillez ecrire le nombre de lignes que vous vouliez charger dans votre deuxieme bibliothèque.\n");
                            int nblignes;
                            fgets(buffer, 256, stdin);
                            sscanf(buffer, "%d", &nblignes);
                            Biblio* b1 = charger_n_entrees(argv[1], nblignes);
                            afficher_biblio(fusion_biblio(bC, b1));
                            printf("fusion terminée.\n");
                            break;
                        case 8: // Recherche des ouvrages avec plusieurs exemplaires
                            livres_exemplaires(bC);
                            printf("Recherche des doublons d'ouvrages d'emplaires terminée.\n");
                            break;
                    }
                } while (cas != 0);
                break;
                
            case 2:
                do {
                    printf("\nGestion de la bibliothèque avec la table de hachage\n");
                    menu();
                    fgets(buffer, 256, stdin);
                    cas = atoi(buffer);
                    
                    switch (cas) {
                        // Cas 1 à 8 similaires à ceux de la gestion avec une liste chainée
                    }
                } while (cas != 0);
                break;
        }
    } while (rep != 0);
    
    // Libération de la mémoire des bibliothèques
    liberer_biblio(bC);
    liberer_biblioH(bH);
    return 0;
}
