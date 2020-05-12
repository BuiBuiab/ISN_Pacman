//fct° qui dessine les Fantômes
void regard_fantome(FANTOME f){
    
    /*f.position.x = 380;
    f.position.y = HAUTEUR/2 + 55;
    dessiner_image(img_fantome_bas[0], f.position);
    
    f.position.x = 428;
    f.position.y = HAUTEUR/2 + 55;
    dessiner_image(img_fantome_bas[1], f.position);
    
    f.position.x = 476;
    f.position.y = HAUTEUR/2 + 55;
    dessiner_image(img_fantome_bas[2], f.position);
    
    f.position.x = 524;
    f.position.y = HAUTEUR/2 + 55;*/
    //dessiner_image(img_fantome_bas[3], f.position);  
}

void dessiner_fantome(FANTOME f, POINT p){

    if(p.x>0){
        dessiner_image(img_fantome_dte[3], f.position);}
        
    if(p.x<0){
        dessiner_image(img_fantome_gche[3], f.position);}
        
    if(p.y>0){
        dessiner_image(img_fantome_haut[3], f.position);}
        
    if(p.y<0){
        dessiner_image(img_fantome_bas[3], f.position);}
    
    if((p.x==0) && (p.y==0)){
        dessiner_image(img_fantome_bas[3], f.position);}
    
}

//fct° quicréer les 1ers Fantômes dans leur pts de spawn
FANTOME creer_fantome(){
     FANTOME f;
     
     f.position.x = LARGEUR/2;
     f.position.y = HAUTEUR/2 + 55;
    
    return f;
}
    

//fct° qui déplace juste les fantômes
/*FANTOME deplacer_fantome(FANTOME f){
    f.vitesse.x = VITESSE;
    f.vitesse.y = f.vitesse.x;
    
    f.position.x += f.vitesse.x;
    f.position.y += f.vitesse.y;
    
   
}*/

//fct° qui envoie les fantômes (qui sont des bots) vers Pacman
/*FANTOME vers_pacman(FANTOME f){

}*/
