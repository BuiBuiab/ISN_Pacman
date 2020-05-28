//fct° qui dessine les Fantômes
void dessiner_fantome(POINT p,int x, FANTOME fantome[4]){

    if(p.x>0){
        dessiner_image(img_fantome[x][DROITE], fantome[x].position);
    }
        
    if(p.x<0){
        dessiner_image(img_fantome[x][GAUCHE], fantome[x].position);
    }
        
    if(p.y>0){
        dessiner_image(img_fantome[x][HAUT], fantome[x].position);
    }
        
    if(p.y<0){
        dessiner_image(img_fantome[x][BAS], fantome[x].position);
    
    }
    
    if((p.x==0) && (p.y==0)){
        dessiner_image(img_fantome[x][BAS], fantome[x].position);
    }
    
}

//fct° quicréer les 1ers Fantômes dans leur pts de spawn
FANTOME creer_fantome(){
    FANTOME coord_f;
    
    int tps = 0;
    
    while(tps < 4){
        fantome[0].position.x = 380;
        fantome[0].position.y = HAUTEUR/2 + 55;
        
        fantome[1].position.x = 428;
        fantome[1].position.y = HAUTEUR/2 + 55;
    
        fantome[2].position.x = 476;
        fantome[2].position.y = HAUTEUR/2 + 55;
 
        fantome[3].position.x = 524;
        fantome[3].position.y = HAUTEUR/2 + 55;
        
        tps++;
        
        if(tps == 0){
            coord_f.position.x = fantome[0].position.x;
            coord_f.position.y = fantome[0].position.y;}
        
        if(tps == 1){
            coord_f.position.x = fantome[1].position.x;
            coord_f.position.y = fantome[1].position.y;}
        
        if(tps == 2){
            coord_f.position.x = fantome[2].position.x;
            coord_f.position.y = fantome[2].position.y;}
            
        
        if(tps == 3){
            coord_f.position.x = fantome[3].position.x;
            coord_f.position.y = fantome[3].position.y;}
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


