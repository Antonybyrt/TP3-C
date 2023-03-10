//
//  tp3-1.c
//  TP3-C
//
//  Created by Antony Loussararian 
//

#include "tp3-1.h"



unsigned short nbJours(enum Mois mois)
{
    printf("Rentrez le mois de votre date\n");
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
                return 31;
                break;
            case 2:
                return 28;
                break;
            case 3:
                return 31;
                break;
            case 4:
                return 30;
                break;
            case 5:
                return 31;
                break;
            case 6:
                return 30;
                break;
            case 7:
                return 31;
                break;
            case 8:
                return 31;
                break;
            case 9:
                return 30;
                break;
            case 10:
                return 31;
                break;
            case 11:
                return 30;
                break;
            case 12 :
                return 31;
                break;
        }
    
    printf("\n");
    
    return mois;
}

bool bissextile(unsigned annee)
{
    if(annee % 4 == 0 && annee % 100 != 0  )

        {
            return true;
        }
    else
    {
        return false;
    }
}

const char* MoisToString(enum Mois mois)
{
    switch (mois)
    {
        case 1: return "Janvier";

        case 2: return "Février";

        case 3: return "Mars";

        case 4: return "Avril";

        case 5: return "Mai";

        case 6: return "Juin";

        case 7: return "Juillet";

        case 8: return "Août";

        case 9: return "Septembre";

        case 10: return "Octobre";

        case 11: return "Novembre";

        case 12: return "Décembre";
            
        default: return "Inconnu";
    }
}

Date* creer_Date(void)
{
    time_t date = time(NULL);

     
        struct tm dateconvert = *localtime(&date);


        char pDeDate[sizeof "JJ/MM/AAAA HH:MM:SS"];

        strftime(pDeDate, sizeof pDeDate, "%d/%m/%Y", &dateconvert);


        printf("la date cree est %s\n", pDeDate);

        return 0;
}

void liberer_Date(Date** d)
{
    free(*d);
}

void initialiser_Date(Date* d)
{
    d = (Date*)malloc(sizeof(Date));
        if (d == NULL) {
            exit(84);
        }
    
    printf ("Rentrez le jour de votre date\n");
    scanf("%hd", &d->jour);
    
    if (d->jour > 31)
    {
        exit (84);
    }
    
    if (d->jour == 31 && (d->mois == 2 || d->mois == 4 || d->mois == 6 || d->mois == 9 || d->mois == 11 ))
        {
        exit (84);
        }
    
    if (d->jour == 30 && d->mois == 2)
        {
        exit (84);
        }
    
    printf ("Rentrez le mois de votre date\n");
    scanf("%d", &d->mois);
    
    if (d->mois < 1 || d->mois > 12)
    {
        exit (84);
    }
    
    printf("Rentrez l'année de votre date\n");
    scanf("%d", &d->annee);
    
    if (bissextile(d->annee == false) && d->jour == 29)
    {
        exit (84);
    }
}

void increment_Date(Date* d, unsigned n)
{
    for (int i = 0; i < n; i ++)
    {
            d->jour ++;
            
            if ((d->jour + i) > (nbJours(d->mois)))
            {
                d->jour = 1;
                d->mois ++;
            }
            if (d->mois > 12)
            {
                d->mois = 1;
                d->annee ++;
            }
        }
    
    printf("\n La date incrémentée est : %hd/%d/%d\n", d->jour, d->mois, d->annee);
}

short int comparer_Date( const Date* d1, const Date* d2)
{
    if (d1->annee < d2->annee)
        {
            printf("-1\n");
        }
        else if (d1->annee > d2->annee)
        {
            printf("1\n");
        }
        else
        {
            if (d1->mois < d2->mois)
            {
                printf("-1\n");
            }
            else if (d1->mois > d2->mois)
            {
                printf("1\n");
            }
            else
            {
                if (d1->jour < d2->jour)
                {
                    printf("-1\n");
                }
                else if (d1->jour > d2->jour)
                {
                    printf("1\n");
                }
                else
                {
                    printf("0\n");
                }
            }
        }
    return 0;
    }



int retour (void)
{
    Date* d1 = NULL;
    Date* d2 = NULL;
    char choice;

    do{
        d1 = creer_Date();
        d2 = creer_Date();
        initialiser_Date(d1);
        initialiser_Date(d2);
        
        increment_Date(d1, 5);
        increment_Date(d2, 34);
        comparer_Date(d1, d2);
        
        liberer_Date(&d1);
        liberer_Date(&d2);
        
        printf("Voulez-vous recommencer l'exercice? [oO] ? N\n");
        scanf(" %c", &choice);
        
      } while (choice == 'o' || choice == 'O');
    
    return 0;
}
