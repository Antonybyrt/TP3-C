//
//  tp3-2.c
//  TP3-C
//
//  Created by Antony Loussararian on 09/02/2023.
//

#include "tp3-1.h"

const char* SexeToString(enum Sexe s)
{
    switch (s) {

    case 0:
        return "Sexe Inconnu";
        break;
    case 1:
        return "sexe Masculin";
        break;
    case 2:
        return "sexe feminin";
        break;
    }
}

Personne* creer_personne(void)
{
    Personne* personne = (Personne*)malloc(sizeof(Personne));
    if (personne == NULL) {
        printf("Erreur d'allocation de memoire pour la personne\n");
        exit (84);
    }

    initialiser_Personne(personne);

    return personne;
}

void liberer_Personne(Personne ** d)
{
    free(*d);
}

void initialiser_Personne(Personne * d)
{
    char nom[100];
    printf("Entrez le nom: ");
    if (scanf("%s", nom) != 1) {
        printf("Erreur de lecture du nom\n");
        free(d);
        exit (84);
    }

    char prenom[100];
    printf("Entrez le prenom: ");
    if (scanf("%s", &prenom) != 1) {
        printf("Erreur de lecture du prenom\n");
        free(d);
        exit (84);
    }

    char numSecuriteSociale[16];
    printf("Entrez le numero de securite sociale: ");
    if (scanf("%s", numSecuriteSociale) != 1) {
        printf("Erreur de lecture du numero de securite sociale\n");
        free(d);
        exit (84);
    }

    d->nom = (char*)malloc((strlen(nom) + 1) * sizeof(char));
    if (d->nom == NULL) {
        printf("Erreur d'allocation de memoire pour le nom\n");
        free(d);
        exit (84);
    }
    strcpy(d->nom, nom);

    d->prenom = (char*)malloc((strlen(prenom) + 1) * sizeof(char));
    if (d->prenom == NULL) {
        printf("Erreur d'allocation de memoire pour le prenom\n");
        free(d->nom);
        free(d);
        exit (84);
    }
    strcpy(d->prenom, prenom);

    strcpy(d->numSecuriteSociale, numSecuriteSociale);
}

void afficher_Personne(const Personne * d)
{
    Personne* p = creer_personne();
    if (p == NULL) {
        exit(84);
    }

    printf("\n\nNom: %s\n", p->nom);
    printf("Prenom: %s\n", p->prenom);
    printf("Numero de securite sociale: %s\n", p->numSecuriteSociale);
}

int retour2(void)
{
    Personne* personne = NULL;
    char choice;
    
    do{
        afficher_Personne(personne);
        
        liberer_Personne(&personne);
        
    printf("Voulez-vous recommencer l'exercice? [oO] ? N\n");
    scanf(" %c", &choice);
        
    } while (choice == 'o' || choice == 'O');
    

    return 0;
}
