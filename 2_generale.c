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

//fct° qui vérifie si pacman touche les murs
int collision_mur(PACMAN pacman, POINT fleche){ 
    int c_pacman = 3, go = 4; 
    
    POINT P;

    //Suivant la direction, donne le points a regarder pour la collision        
    if(fleche.x > 0){
        fleche.y = 0;
        
        P.x = pacman.position.x + 20;
        P.y = pacman.position.y;}    
        
    if(fleche.x < 0){
        fleche.y = 0;
        
        P.x = pacman.position.x - 20;
        P.y = pacman.position.y;}
    
    if(fleche.y > 0){
        fleche.x = 0;
        
        P.x = pacman.position.x ;
        P.y = pacman.position.y + 20;}
        
    if(fleche.y < 0){
        fleche.x = 0;

        P.x = pacman.position.x ;
        P.y = pacman.position.y - 20;}
        
    if((fleche.x == 0) && (fleche.y == 0)){
        P.x = pacman.position.x;
        P.y = pacman.position.y;}

    c_pacman = couleur_map(P); //1 = rouge, 2 = jaune, 3 = bleu
    
    //renvoie 0 ou 1 si mur détecté et 4 si rien
    if((c_pacman == 1) && ((fleche.x > 0) || (fleche.y>0)) ){
        go = 0;
    }
    
    if((c_pacman == 1) && ((fleche.x<0) || (fleche.y<0)) ){
        go = 1;
    }
    
    if(c_pacman == 3){
        go = 4;
    }
    
    return go;
}

//fct° qui vérifie la collision entre pacman et les fantome
/*int collision(PACMAN pacman, FANTOME fantome){
    
    
}*/

//fct qui centre pacman et les fantômes au millieu des couloirs 
void centrer(PACMAN p, FANTOME f){
    
}


//fct° qui vérifie les conditions de perte (renvoie 0 si le joueur à perdu)
/*int continuer_a_jouer(){

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
    POINT f;
    int go = 4;
    
    f = lire_fleches();
    go = collision_mur(pacman, f);
    
    //empèche d'aller sur un mur 
    if(go == 0){
        pacman.vitesse.x = f.x - 1;
        pacman.vitesse.y = f.y - 1;}
        
    if(go == 1){
        pacman.vitesse.x = f.x + 1;
        pacman.vitesse.y = f.y + 1;}
    
    if(go == 4){
        pacman.vitesse.x = f.x * VITESSE;
        pacman.vitesse.y = f.y * VITESSE;}
    
    
    //empèche le déplacement en X et en Y en même temps
    if((f.x > 0) || (f.x < 0)){
        pacman.vitesse.y = 0;
        
        pacman.position.x += pacman.vitesse.x;
        pacman.position.y += pacman.vitesse.y;}
      
    
    if((f.y > 0) || (f.y < 0)){
        pacman.vitesse.x = 0;
        
        pacman.position.x += pacman.vitesse.x;
        pacman.position.y += pacman.vitesse.y;}
    
    
    //fantome = deplacer_fantome(fantome);
}

