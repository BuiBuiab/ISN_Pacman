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
    img_fantome_haut[0] = charger_image("F bleu look T.png");
    img_fantome_bas[0] = charger_image("F bleu look B.png");
    img_fantome_dte[0] = charger_image("F bleu look R.png");
    img_fantome_gche[0] = charger_image("F bleu look L.png");
    
    img_fantome_haut[1] = charger_image("F orange look T.png");
    img_fantome_bas[1] = charger_image("F orange look B.png");
    img_fantome_dte[1] = charger_image("F orange look R.png");
    img_fantome_gche[1] = charger_image("F orange look L.png");
    
    img_fantome_haut[2] = charger_image("F rose look T.png");
    img_fantome_bas[2] = charger_image("F rose look B.png");
    img_fantome_dte[2] = charger_image("F rose look R.png");
    img_fantome_gche[2] = charger_image("F rose look L.png");
    
    img_fantome_haut[3] = charger_image("F rouge look T.png");
    img_fantome_bas[3] = charger_image("F rouge look B.png");
    img_fantome_dte[3] = charger_image("F rouge look R.png");
    img_fantome_gche[3] = charger_image("F rouge look L.png");
}

//fct° qui vérifie si pacman touche les murs
int collision_mur(POINT centre_objet, POINT fleche){ 
    int c_objet = 3, go = 2; 
    
    POINT P;

    //Suivant la direction, donne le points a regarder pour la collision        
    if(fleche.x > 0){//test vers la droite
        fleche.y = MVT_STOP;
        
        P.x = centre_objet.x + 20;
        P.y = centre_objet.y;}    
        
    if(fleche.x < 0){//test vers la gauche
        fleche.y = MVT_STOP;
        
        P.x = centre_objet.x - 20;
        P.y = centre_objet.y;}
    
    if(fleche.y > 0){//test vers le haut
        fleche.x = MVT_STOP;
        
        P.x = centre_objet.x ;
        P.y = centre_objet.y + 20;}
        
    if(fleche.y < 0){//test vers le bas
        fleche.x = MVT_STOP;

        P.x = centre_objet.x ;
        P.y = centre_objet.y - 20;}
        
    if((fleche.x == 0) && (fleche.y == 0)){
        P.x = centre_objet.x;
        P.y = centre_objet.y;}

    c_objet = couleur_map(P); //1 = rouge, 2 = jaune, 3 = bleu
    
    //printf("c = : %d\n", c_pacman);
    //fflush(stdout);
    
    
    /*renvoie: * 0 si "x" ou "y" > 0
               * 1 si "x" ou "y" < 0
               * 2 si pacman veut passer dans le téléporteur (et les fantômes plus tard)*/
    if((c_objet == 1) && ((fleche.x > 0) || (fleche.y>0)) ){
        go = MVT_NEG_STOP;
    }
    
    if((c_objet == 1) && ((fleche.x<0) || (fleche.y<0)) ){
        go = MVT_STOP;
    }
    
    if((c_objet == 3) || (c_objet == 4)){
        go = MVT_OK;
    }
    
    if( ((c_objet == 1) && (centre_objet.x >= 880)) || ((c_objet == 1) && (centre_objet.x <= 20)) ){
        go = MVT_OK;
    }
    
    return go;
}


//fct° qui vérifie la collision entre pacman et les fantome
/*int collision(PACMAN pacman, FANTOME fantome){
    
    
}

//fct qui centre pacman et les fantômes au millieu des couloirs 
void centrer(PACMAN p, FANTOME f){
    
}

//fct° qui vérifie les conditions de perte (renvoie 0 si le joueur à perdu)
int continuer_a_jouer(){

}*/

//fct° qui s'occupe de tout dessiner...
void dessiner_le_jeu(int frame){
    
    dessiner_map();    
    dessiner_pacman(pacman, frame);
    
    POINT f = lire_fleches();
    dessiner_fantome(fantome, f);
    
    
    affiche_tout();
}

//Cette fonction s'occupe de deplacer pacman (action de joueur) et les fantômes
void avancer_le_jeu(){
    POINT f;
    int go_pacman = 2, go_fantome;
    
    f = lire_fleches();
    go_pacman = collision_mur(pacman.position, f);
    
    /********************déplacement pacman********************/
    //empèche d'aller sur un mur 
    /*if(go_pacman == MVT_NEG_STOP){
        pacman.vitesse.x = f.x - 1;
        pacman.vitesse.y = f.y - 1;}
        
    if(go_pacman == MVT_STOP){
        pacman.vitesse.x = f.x + 1;
        pacman.vitesse.y = f.y + 1;}
    
    if(go_pacman == MVT_OK){
        pacman.vitesse.x = f.x * VITESSE;
        pacman.vitesse.y = f.y * VITESSE;}
    
    
    //empèche le déplacement en X et en Y en même temps
    if((f.x > 0) || (f.x < 0)){
        pacman.vitesse.y = MVT_STOP;
        
        pacman.position.x += pacman.vitesse.x;
        pacman.position.y += pacman.vitesse.y;}
      
    
    if((f.y > 0) || (f.y < 0)){
        pacman.vitesse.x = MVT_STOP;
        
        pacman.position.x += pacman.vitesse.x;
        pacman.position.y += pacman.vitesse.y;}   */
        
    //printf("X = %d\n\n", pacman.position.x);
    //fflush(stdout);

    
    
    
    /********************déplacement fantômes********************/
    //fantome = deplacer_fantome(fantome);
    
    
    
    go_fantome = collision_mur(fantome.position, f);
    
    if(go_fantome == MVT_NEG_STOP){
        fantome.vitesse.x =  MVT_STOP;
        fantome.vitesse.y =  MVT_STOP;}
        
    if(go_fantome == MVT_STOP){
        fantome.vitesse.x =  MVT_STOP;
        fantome.vitesse.y =  MVT_STOP;}
    
    /*****pour tester le déplacement avec les flèches*****/
    if(go_fantome == MVT_OK){
        fantome.vitesse.x = f.x * VITESSE;
        fantome.vitesse.y = f.y * VITESSE;}
    
    
    //empèche le déplacement en X et en Y en même temps
    if((f.x > 0) || (f.x < 0)){
        fantome.vitesse.y = MVT_STOP;
        
        fantome.position.x += fantome.vitesse.x;
        fantome.position.y += fantome.vitesse.y;}
      
    
    if((f.y > 0) || (f.y < 0)){
        fantome.vitesse.x = MVT_STOP;
        
        fantome.position.x += fantome.vitesse.x;
        fantome.position.y += fantome.vitesse.y;}
        
    
    /**********téléporteur**********/
    if((pacman.position.x > 920) || (fantome.position.x > 920)){
        pacman.position.x = -20;
        
        fantome.position.x = -20;}
    
    
    if((pacman.position.x < -20) || (fantome.position.x < -20)){
        pacman.position.x = 920;
        
        fantome.position.x = 920;}
}



