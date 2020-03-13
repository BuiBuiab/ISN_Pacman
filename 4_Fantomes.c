//fct° qui dessine les Fantômes
void dessiner_fantome(FANTOME f){
     dessiner_image(img_fantome, f.position);
     
}

//fct° quicréer les 1ers Fantômes dans leur pts de spawn
FANTOME creer_fantome(){
     FANTOME f;
     
     f.position.x = LARGEUR/2;
     f.position.y = HAUTEUR/2;
    
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
FANTOME vers_pacman(FANTOME f){

}