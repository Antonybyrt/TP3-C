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
    Date* pDeDate; // Pointeur pour la variable structurée
    
    short int nb_date = 0;
    
    printf("Combien de date(s) souhaitez-vous créer ? ");
    scanf("%hd", &nb_date);
    
    //Allocation d'une variable structurée
    pDeDate = (Date*) malloc( sizeof(Date));
    if (pDeDate == NULL)
    {
        printf("\n Allocation impossible");
        exit(84); //On quitte le programme
    }

    // Définition de la date du jour
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    // Stockage de cette date dans la structure
    pDeDate->jour = (unsigned short)timeinfo->tm_mday;
    pDeDate->mois = (enum Mois)(timeinfo->tm_mon + 1);
    pDeDate->annee = (unsigned)timeinfo->tm_year + 1900;
    
    return pDeDate;
}

void liberer_Date(Date** d)
{
    free(*d);
}

void initialiser_Date(Date* d)
{
    printf ("Rentrez le jour de votre date\n");
    scanf("%hd", &d->jour);
    
    printf("Rentrez le mois de votre date\n");
    scanf("%d", &d->mois);
    
    printf("Rentrez l'année de votre date\n");
    scanf("%d", &d->annee);
}

void increment_Date(Date* d, unsigned n)
{
    printf("De combien de jours souhaitez-vous incrémenter votre date ?");
    scanf("%u", &n);
    
    for (int i = 0; i < n; i ++)
    {
        if ((d->mois == 1 || d->mois == 3 || d->mois == 5 || d->mois == 7 || d->mois == 8 || d->mois == 10 || d->mois == 12) && (bissextile(d->annee == true)))
        {
            d->jour ++;
            
            if ((i % 31) == 0)
            {
                d->jour = 0;
                d->mois ++;
            }
            if ((i % 366) == 0)
            {
                d->mois = 0;
                d->annee ++;
            }
        }
        
        if ((d->mois == 4 || d->mois == 6 || d->mois == 9 || d->mois == 11) && (bissextile(d->annee == true)))
        {
            d->jour ++;
            
            if ((i % 30) == 0)
            {
                d->jour = 0;
                d->mois ++;
            }
            if ((i % 366) == 0)
            {
                d->mois = 0;
                d->annee ++;
            }
        }
        
        if ((d->mois == 1 || d->mois == 3 || d->mois == 5 || d->mois == 7 || d->mois == 8 || d->mois == 10 || d->mois == 12) && (bissextile(d->annee == false)))
        {
            d->jour ++;
            
            if ((i % 31) == 0)
            {
                d->jour = 0;
                d->mois ++;
            }
            if ((i % 365) == 0)
            {
                d->mois = 0;
                d->annee ++;
            }
        }
        
        if ((d->mois == 4 || d->mois == 6 || d->mois == 9 || d->mois == 11) && (bissextile(d->annee == false)))
        {
            d->jour ++;
            
            if ((i % 30) == 0)
            {
                d->jour = 0;
                d->mois ++;
            }
            if ((i % 365) == 0)
            {
                d->mois = 0;
                d->annee ++;
            }
        }
        
        if ((d->mois == 2) && (bissextile(d->annee == true)))
        {
            d->jour ++;
            
            if ((i % 29) == 0)
            {
                d->jour = 0;
                d->mois ++;
            }
            if ((i % 366) == 0)
            {
                d->mois = 0;
                d->annee ++;
            }
        }
        
        if ((d->mois == 2) && (bissextile(d->annee == false)))
        {
            d->jour ++;
            
            if ((i % 28) == 0)
            {
                d->jour = 0;
                d->mois ++;
            }
            if ((i % 365) == 0)
            {
                d->mois = 0;
                d->annee ++;
            }
        }
    }
}

short int comparer_Date( const Date* d1, const Date* d2)
{
    if (d1->annee < d2->annee)
        {
            return -1;
        }
        else if (d1->annee > d2->annee)
        {
            return 1;
        }
        else
        {
            if (d1->mois < d2->mois)
            {
                return -1;
            }
            else if (d1->mois > d2->mois)
            {
                return 1;
            }
            else
            {
                if (d1->jour < d2->jour)
                {
                    return -1;
                }
                else if (d1->jour > d2->jour)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
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
