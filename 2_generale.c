//au cas où j'en ai besoin
/*float distance(POINT p, POINT p1){

    float dx, dy;
    
    dx = p.x - p1.x;
    dy = p.y - p1.y;

    return sqrt(dx*dx+dy*dy);
}*/

void initialiser_partie()
{
    initialiser_fenetre( LARGEUR, HAUTEUR, "Pacman" ); 
    affiche_auto_off();
    
    img_map = charger_image("map.png");
    img_map_collision = charger_image("map_collisions.png");
    
    pacman = creer_pacman();
    img_pacman[0] = charger_image("pacman.png");
    img_pacman[1] = charger_image("Pacman_bouche_fermee.png");
    
    fantome = creer_fantome();
    img_fantome = charger_image("F bleu look B.png");
}

//fct° qui vérifie la collision entre pacman et les fantome
/*int collision(PACMAN pacman, FANTOME fantome){
    
    
}

//fct° qui vérifie les conditions de perte (renvoie 0 si le joueur à perdu)
int continuer_a_jouer(){

}*/

//fct° qui s'occupe de tout dessiner...
void dessiner_le_jeu(int frame){
    
    dessiner_map();    
    dessiner_pacman(pacman, frame);
    dessiner_fantome(fantome);
        
    affiche_tout();
}

//Cette fonction s'occupe de deplacer pacman (action de joueur) et les fantômes
void avancer_le_jeu(){
    POINT f, P;
    int c_pacman;

    f = lire_fleches();
    
    P.x = pacman.position.x + 20;
    P.y = pacman.position.y;
    
    c_pacman = couleur_map(P);
    
    printf("c_pacman = %d\n", c_pacman);
    fflush(stdout);
    
    if(c_pacman == 3){
        pacman.vitesse.x = f.x * VITESSE;
        pacman.vitesse.y = f.y * VITESSE;
    }
    else{
        pacman.vitesse.x = f.x - 5;
        pacman.vitesse.y = f.y - 5;
    }
    
    pacman.position.x += pacman.vitesse.x;
    pacman.position.y += pacman.vitesse.y;
    
    //fantome = deplacer_fantome(fantome);
}