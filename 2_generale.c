float distance(POINT p, POINT p1){

    float dx, dy;
    
    dx = p.x - p1.x;
    dy = p.y - p1.y;

    return sqrt(dx*dx+dy*dy);
}

void initialiser_partie()
{
    initialiser_ecran( LARGEUR, HAUTEUR, "Pacman" ); 
    affiche_auto_off();
    
    img_map = charger_image("map.png");
    img_map_collision = charger_image("map_collisions.png");
    
    pacman = creer_pacman();
    img_pacman[0] = charger_image("pacman.png");
    img_pacman[1] = charger_image("Pacman_bouche_fermee.png");
    
    fantome = creer_fantome();
    img_fantome = charger_image("F bleu look B.png");
}

//fct° qui vérifie si pacman et les fantome se touche ou non
int collision(PACMAN pacman, FANTOME fantome){
    int c_pacman, c_fantome;
    POINT P, F;
    
    P.x = pacman.position.x + 19;
    P.y = pacman.position.y + 20;
    
    c_pacman = couleur_map(img_map_collision, P);
    
    if((c_pacman == 1) || (c_pacman == 2)){
        
    }
    
    F.x = pacman.position.x + 20;
    F.y = pacman.position.y + 20;
    
    c_fantome = couleur_map(img_map_collision, F);
    
    if((c_fantome == 1)){
        
    }
    
    if(c_fantome == 2){
        
    }
    
}

//fct° qui vérifie les conditions de perte (renvoie 0 si le joueur à perdu)
int continuer_a_jouer(){

}

//fct° qui s'occupe de tout dessiner...
void dessiner_le_jeu(int frame){
    
    dessiner_map();    
    dessiner_pacman(pacman, frame);
    dessiner_fantome(fantome);
        
    affiche_tout();
}

//Cette fonction s'occupe de deplacer pacman (action de joueur) et les fantômes
void avancer_le_jeu(){
    POINT f;
    
    f = lire_fleches();
    
    pacman.vitesse.x = f.x * VITESSE;
    pacman.vitesse.y = f.y * VITESSE;
    
    pacman.position.x += pacman.vitesse.x;
    pacman.position.y += pacman.vitesse.y;
    
    //fantome = deplacer_fantome(fantome);
}