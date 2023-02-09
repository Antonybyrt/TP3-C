//
//  menu.c
//  TP3-C
//
//  Created by Antony Loussararian 
//

#include "menu.h"
#include "tp3-1.h"

int menu(void)
{
    int exercice;
    char choice;
    printf("Bienvenue au TP3 de Loussararian Antony !\n");
    do // Initialisation d'une boucle qui demande à l'utilisateur s'il veut relancer d'autres exercies ou arrêter le programme
    {
        printf("Selectionez un exercice (de 1 à 2 et 0 pour quitter) : \n");
        scanf("%d", &exercice);
        if ( exercice == 0) break;
        switch ( exercice ) // Initialsation d'une condition qui demande à l'utilisateur quel exercice il veut lancer
        {
            case 1 :
                retour();
                break;
            case 2 :
                retour2();
                break;
            default:
                printf("Veuillez selectionner un exercice entre 1 et 2 \n");
                break;
            }

            printf("\nVoulez-vous lancer un autre exercice? [oO] ? N\n");
            scanf(" %c", &choice);
        }
        while (choice == 'o' || choice == 'O');

        printf("Merci et à bientôt !\n");
        return 0;
    }
