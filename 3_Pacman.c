//fct° qui déssine Pacman
void dessiner_pacman(PACMAN p, int frame){
    if(frame<10)
        dessiner_image(img_pacman[0], p.position);
    else
        dessiner_image(img_pacman[1], p.position);
}

//fct° quicréer le 1er Pacman au centre de la carte
PACMAN creer_pacman(){
    PACMAN p;
    
    p.position.x = LARGEUR/2;
    p.position.y = HAUTEUR/2-35;
    
    return p;
}



