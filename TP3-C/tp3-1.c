//
//  tp3-1.c
//  TP3-C
//
//  Created by Antony Loussararian 
//

#include "tp3-1.h"

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
    
        if (mois == Janvier)
        {
            char nom[]="Janvier";
            printf("Il y a 31 jours dans le mois de %s\n", nom);
        }
        else if (mois == Fevrier)
        {
            char nom[]="Février";
            printf("Il y a 28 jours dans le mois de %s\n", nom);
        }
        else if (mois == Mars)
        {
            char nom[]="Mars";
            printf("Il y a 31 jours dans le mois de %s\n", nom);
        }
        else if (mois == Avril)
        {
            char nom[]="Avril";
            printf("Il y a 30 jours dans le mois d'%s\n", nom);
        }
        else if (mois == Mai)
        {
            char nom[]="Mai";
            printf("Il y a 31 jours dans le mois de %s\n", nom);
        }
        else if (mois == Juin)
        {
            char nom[]="Juin";
            printf("Il y a 30 jours dans le mois de %s\n", nom);
        }
        else if (mois == Juillet)
        {
            char nom[]="Juillet";
            printf("Il y a 31 jours dans le mois de %s\n", nom);
        }
        else if (mois == Aout)
        {
            char nom[]="Aout";
            printf("Il y a 31 jours dans le mois d'%s\n", nom);
        }
        else if (mois == Septembre)
        {
            char nom[]="Septembre";
            printf("Il y a 30 jours dans le mois de %s\n", nom);
        }
        else if (mois == Octobre)
        {
            char nom[]="Octobre";
            printf("Il y a 31 jours dans le mois d'%s\n", nom);
        }
        else if (mois  == Novembre)
        {
            char nom[]="Novembre";
            printf("Il y a 30 jours dans le mois de %s\n", nom);
        }
        else if (mois == Decembre)
        {
            char nom[]="Décembre";
            printf("Il y a 31 jours dans le mois de %s\n", nom);
        }
    
    
    return 0;
}

bool bissextile(unsigned annee)
{
    printf("Entrez une année");
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
