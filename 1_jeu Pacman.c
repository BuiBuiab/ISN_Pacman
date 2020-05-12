#include "toolbox.h"

/* Quelques constantes qui seront utilisees dans tout le programme */
#define HAUTEUR 1000             // Dimensions la photo map.png
#define LARGEUR 900
#define VITESSE 5               // Vitesse de déplacement
#define MVT_NEG_STOP 1 //= stopper le mouvement si "x" ou "y" < 0
#define MVT_STOP 0
#define MVT_OK 2


#include "6_definition.c"

PACMAN pacman;
IMAGE img_pacman[2];

IMAGE img_map;
IMAGE img_map_collision;

FANTOME fantome;
IMAGE img_fantome_haut[4];
IMAGE img_fantome_bas[4];
IMAGE img_fantome_dte[4];
IMAGE img_fantome_gche[4];


#include "5_map.c"
#include "4_Fantomes.c"
#include "3_Pacman.c"

#include "2_generale.c"


// Le programme !
int main( int argc, char** argv )
{
    initialiser_partie();
    
    // Une variable qui permet de ²controler si la partie doit continuer...
    int jouer = 1;  
    int frame=0;
    
    while( jouer==1 )       // La boucle principale du jeu
    {
        
        dessiner_le_jeu(frame);         // 1. On affiche les objets
        
        frame++;
        
        if(frame==20){
            frame = 0;}
        
        avancer_le_jeu();               // 2. On fait avancer la partie
        
        //jouer = continuer_a_jouer();    // 3. On teste si le joueur a perdu        
        attendre(30);                   // 4. Un pause pour que le jeu n'aille pas trop vite
    }   
    
    // Perdu! 
    attendre_echap();

    quitter(0);
}