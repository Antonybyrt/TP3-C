//
//  tp3-1.h
//  TP3-C
//
//  Created by Antony Loussararian 
//

#ifndef tp3_1_h
#define tp3_1_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


enum Mois
{
    Janvier=1, Fevrier, Mars, Avril, Mai, Juin, Juillet, Aout, Septembre, Octobre, Novembre, Decembre
};

typedef struct
{
    unsigned short jour;
    enum Mois mois;
    unsigned annee;
} Date;

unsigned short nbJours(enum Mois mois);
bool bissextile(unsigned annee);
const char* MoisToString(enum Mois mois);

Date* creer_Date(void);
void liberer_Date(Date** d);
void initialiser_Date(Date* d);
void increment_Date(Date* d, unsigned n);


#endif
