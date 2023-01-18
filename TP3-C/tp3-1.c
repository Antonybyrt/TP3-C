//
//  tp3-1.c
//  TP3-C
//
//  Created by Antony Loussararian 
//

#include "tp3-1.h"

const char* MoisToString(enum Mois mois)
{
    switch (mois)
    {
        case 1:
            printf("Janvier");
            break;
        case 2:
            printf("Février");
            break;
        case 3:
            printf("Mars");
            break;
        case 4:
            printf("Avril");
            break;
        case 5:
            printf("Mai");
            break;
        case 6:
            printf("Juin");
            break;
        case 7:
            printf("Juillet");
            break;
        case 8:
            printf("Août");
            break;
        case 9:
            printf("Septembre");
            break;
        case 10:
            printf("Octobre");
            break;
        case 11:
            printf("Novembre");
            break;
        case 12:
            printf("Décembre");
            break;
    }
    
    return 0;
}

unsigned short nbJours(enum Mois mois)
{
    printf("Sélectionnez un mois dans l'année entre 1 et 12: ");
    scanf("%u", &mois);
    
        while (mois < 1 || mois > 12)
        {
            printf("Veuillez indiquer un nombre entre 1 et 12\n\n");
            printf("Sélectionnez un mois dans l'année entre 1 et 12: ");
            scanf("%u", &mois);
        }
    
        switch (mois)
        {
            case 1:
                printf("Il y a 31 jours dans le mois de ");
                break;
            case 2:
                printf("Il y a 28 jours dans le mois de ");
                break;
            case 3:
                printf("Il y a 31 jours dans le mois de ");
                break;
            case 4:
                printf("Il y a 30 jours dans le mois d'");
                break;
            case 5:
                printf("Il y a 31 jours dans le mois de ");
                break;
            case 6:
                printf("Il y a 30 jours dans le mois de ");
                break;
            case 7:
                printf("Il y a 31 jours dans le mois de ");
                break;
            case 8:
                printf("Il y a 31 jours dans le mois d'");
                break;
            case 9:
                printf("Il y a 30 jours dans le mois de ");
                break;
            case 10:
                printf("Il y a 31 jours dans le mois d'");
                break;
            case 11:
                printf("Il y a 30 jours dans le mois de ");
                break;
            case 12 :
                printf("Il y a 31 jours dans le mois de ");
                break;
        }
    
    MoisToString(mois);
    printf("\n");
    
    return 0;
}

bool bissextile(unsigned annee)
{
    printf("Entrez une année ");
    scanf("%d", &annee);
    
    if(annee % 4 == 0)
        {
            if( annee % 100 == 0)
            {
                if ( annee % 400 == 0)
                    printf("%d est une année bissextile\n", annee);
                else
                    printf("%d n'est pas une année bissextile\n", annee);
            }
            else
                printf("%d est une année bissextile\n", annee );
        }
        else
            printf("%d n'est pas une année bissextile\n", annee);
    
    return 0;
}

int retour (void)
{
    enum Mois mois;
    mois = 0;
    unsigned annee = 0;
    char choice;
    
    do{
        nbJours(mois);
        bissextile(annee);
        printf("Voulez-vous recommencer l'exercice? [oO] ? N\n");
        scanf(" %c", &choice);
        
      } while (choice == 'o' || choice == 'O');
    
    return 0;
}
