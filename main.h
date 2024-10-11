#ifndef MAIN_H  
#define MAIN_H  
  

struct s_joueur 
{  
    int x;
    int y;
};  

typedef struct s_joueur position_joueur;  
  
// ------------------------------------------

struct s_objet
{
    int x;
    int y;
};

typedef struct s_objet position_objet;

struct s_winpoint
{
    int x;
    int y;
};

typedef struct s_winpoint winpoint;

#endif //MAIN_H
