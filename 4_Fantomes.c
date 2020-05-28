//fct° qui dessine les Fantômes
void dessiner_fantome(POINT p, int x, FANTOME fantome){
    
    if(p.x>0)
        dessiner_image(img_fantome[x][DROITE], fantome.position);
    
        
    if(p.x<0)
        dessiner_image(img_fantome[x][GAUCHE], fantome.position);
    
        
    if(p.y>0)
        dessiner_image(img_fantome[x][HAUT], fantome.position);
    
        
    if(p.y<0)
        dessiner_image(img_fantome[x][BAS], fantome.position);

    
    if((p.x==0) && (p.y==0))
        dessiner_image(img_fantome[x][BAS], fantome.position);
    
}

//fct° quicréer les 1ers Fantômes dans leur pts de spawn
FANTOME creer_fantome(){
    FANTOME coord_f;
    
    int tps = 0;
    
    while(tps < 4){
        fantome_bleu.position.x = 380;
        fantome_bleu.position.y = HAUTEUR/2 + 55;
        
        fantome_orange.position.x = 428;
        fantome_orange.position.y = HAUTEUR/2 + 55;
    
        fantome_rose.position.x = 476;
        fantome_rose.position.y = HAUTEUR/2 + 55;
 
        fantome_rouge.position.x = 524;
        fantome_rouge.position.y = HAUTEUR/2 + 55;
        
        tps++;
        
        if(tps == 0){
            coord_f.position.x = fantome_bleu.position.x;
            coord_f.position.y = fantome_bleu.position.y;}
        
        if(tps == 1){
            coord_f.position.x = fantome_orange.position.x;
            coord_f.position.y = fantome_orange.position.y;}
        
        if(tps == 2){
            coord_f.position.x = fantome_rose.position.x;
            coord_f.position.y = fantome_rose.position.y;}
            
        
        if(tps == 3){
            coord_f.position.x = fantome_rouge.position.x;
            coord_f.position.y = fantome_rouge.position.y;}

    }
    return coord_f;
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


