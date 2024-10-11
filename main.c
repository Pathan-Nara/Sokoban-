#include <stdlib.h>
#include <stdio.h>
#include "main.h"

char ** creer_tab()
{
    char ** tab;
    
    tab = malloc(10 * sizeof(*tab));
    for (int i = 0; i < 10; i++)

    {

        tab[i] = malloc(10 * sizeof(char));
        for (int j = 0; j < 10; j++)
        {
            if(i == 0 || i == 9)
            {
                tab[i][j] = '#';
            }
            else if(j == 0 || j == 9)
            {
                tab[i][j] = '#';
            }
            else
            {
                tab[i][j] = ' ';
            }
        }

    }

    return tab;
}



void print_tab(char ** tab)
{
    for (int i = 0; i < 10; i++)
    {
        for (int k = 0; k < 10; k++)
        {
            printf("%c", tab[i][k]);
        }
        printf("\n");
    }
}


void afficher_joueur(char ** tab, position_joueur joueur)
{
    tab[joueur.y][joueur.x] = 'X';
}

void afficher_objet(char ** tab, position_objet objet)
{
    tab[objet.y][objet.x] = 'O';
}

void afficher_winpoint(char ** tab, winpoint winpoint)
{
    tab[winpoint.y][winpoint.x] = 'W';
}

int victoire(char ** tab, position_objet objet, winpoint winpoint)
{
    if(objet.x == winpoint.x && objet.y == winpoint.y)
    {
        return 1;
    }
    return 0;
}

void defaite(char ** tab, position_objet objet)
{
    if (objet.x == 1 || objet.x == 8 || objet.y == 0 || objet.y == 8)
    {
        afficher_objet(tab, objet);
        printf("Vous avez perdu !\n");
        exit(0);
    }
}

void deplacement_joueur(char ** tab, position_joueur *joueur, position_objet *objet)
{
    char direction;
    printf("Dans quelle direction voulez-vous aller ? (z, s, q, d)\n");
    scanf(" %c", &direction);
    if(direction == 's')
    {
        if(joueur->y == 8)
        {
            printf("Vous ne pouvez pas aller plus haut\n");
            deplacement_joueur(tab, joueur, objet);
        }
        else
        {
            tab[joueur->y][joueur->x] = ' ';
            joueur->y ++;
            if (joueur->x == objet->x && joueur->y == objet->y)
            {
                objet->y ++;
                afficher_objet(tab, *objet);
                printf("------------------------------------\n");
                defaite(tab, *objet);
            }
            afficher_joueur(tab, *joueur);
            afficher_objet(tab, *objet);
        }
    }
    else if(direction == 'z')
    {
        if(joueur->y == 1)
        {
            printf("Vous ne pouvez pas aller plus bas\n");
            deplacement_joueur(tab, joueur, objet);
        }
        else
        {
            tab[joueur->y][joueur->x] = ' ';
            joueur->y --;
            if (joueur->x == objet->x && joueur->y == objet->y)
            {
                objet->y --;
                afficher_objet(tab, *objet);
                printf("------------------------------------\n");
                defaite(tab, *objet);
            };
            afficher_joueur(tab, *joueur);
            afficher_objet(tab, *objet);
        }
    }
    else if (direction == 'q')
    {
        if(joueur->x == 1)
        {
            printf("Vous ne pouvez pas aller plus à gauche\n");
            deplacement_joueur(tab, joueur, objet);
        }
        else
        {
            tab[joueur->y][joueur->x] = ' ';
            joueur->x --;
            if (joueur->x == objet->x && joueur->y == objet->y)
            {
                objet->x --;
                afficher_objet(tab, *objet);
                printf("------------------------------------\n");
                defaite(tab, *objet);
            };
            afficher_joueur(tab, *joueur);
            afficher_objet(tab, *objet);
        }
    }
    else if (direction == 'd')
    {
        if(joueur->x == 8)
        {
            printf("Vous ne pouvez pas aller plus à droite\n");
            deplacement_joueur(tab, joueur, objet);
        }
        else
        {
            tab[joueur->y][joueur->x] = ' ';
            joueur->x ++;
            if (joueur->x == objet->x && joueur->y == objet->y)
            {
                objet->x ++;
                afficher_objet(tab, *objet);
                printf("------------------------------------\n");
                defaite(tab, *objet);
            }
            afficher_joueur(tab, *joueur);
            afficher_objet(tab, *objet);
        }
    }
}





int main()
{
    char ** tab = creer_tab();
    position_joueur joueur = {3, 3};
    position_objet objet = {2, 4};
    winpoint winpoint = {7, 5};
    int w = 0;
    afficher_joueur(tab, joueur);
    afficher_objet(tab, objet);
    afficher_winpoint(tab, winpoint);
    print_tab(tab);

    while(victoire(tab, objet, winpoint) == 0)
    {
        deplacement_joueur(tab, &joueur, &objet);
        print_tab(tab);
        victoire(tab, objet, winpoint);
    }
    printf("Vous avez gagné !\n");
    exit(0);
}