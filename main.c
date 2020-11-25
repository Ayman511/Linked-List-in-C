#include <stdio.h>
#include <stdlib.h>

typedef struct Element Element;
struct Element{
    int nombre;
    Element *next;
};

typedef struct Liste Liste;
struct Liste{
    Element *premier;
};

Liste *initialisation();
void insertion(Liste *liste, int nbr);
void insertionAuMilieu(Liste *liste, int nombreCherche, int nbr);
void suppression(Liste *liste, int nbrASupp);
void afficherListe(Liste *liste);

int main(){
    Liste *maListe = initialisation();

    insertion(maListe, 1);
    insertion(maListe, 2);
    insertion(maListe, 3);
    insertion(maListe, 4);

    insertionAuMilieu(maListe, 2, 12);

    suppression(maListe, 0);

    afficherListe(maListe);
}

Liste *initialisation()
{
    /* Création des instances */
    Element *element = malloc(sizeof(*element));
    Liste *liste = malloc(sizeof(*liste));

    if(liste == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    element->nombre = 0;
    element->next = NULL;
    liste->premier = element;

    return liste;
}

void insertion(Liste *liste, int nbr)
{
    /* Création du nouvel élément */
    Element *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->nombre = nbr;

    /* Insertion de l'élément au début de la liste */
    nouveau->next = liste->premier;
    liste->premier = nouveau;
}
void insertionAuMilieu(Liste *liste, int nombreCherche, int nbr)
{
    Element *nouveau = malloc(sizeof(*nouveau));
    Element *temp = liste->premier;

    if(nouveau == NULL){
        exit(EXIT_FAILURE);
    }

    while(temp->next != NULL && temp->next->nombre != nombreCherche)
    {
        temp = temp->next;
    }

    if(temp->next != NULL)
    {
        nouveau->nombre = nbr;
        nouveau->next = temp->next;
        temp->next = nouveau;
    }
}

void suppression(Liste *liste, int nbrASupp)
{
    Element *aSupprimer = NULL;
    if(liste->premier->nombre == nbrASupp)
    {
        aSupprimer = liste->premier;
        liste->premier = liste->premier->next;
        free(aSupprimer);
    }else
    {
        Element *temp = liste->premier;

        while(temp->next->nombre != nbrASupp && temp->next != NULL)
            temp = temp->next;

        if(temp->next != NULL)
        {
           aSupprimer = temp->next;
           temp->next = temp->next->next;
           free(aSupprimer);
        }
    }
}

void afficherListe(Liste *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *actuel = liste->premier;

    while (actuel != NULL)
    {
        printf("%d -> ", actuel->nombre);
        actuel = actuel->next;
    }
    printf("NULL\n");
}