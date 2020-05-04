void dessiner_map(){
    POINT p;
    
    p.x = LARGEUR/2;
    p.y = HAUTEUR/2;
    dessiner_image(img_map, p);
}

//renvoie 1 ou 2 en fonction de la couleur du pixel sur la map_collisions
int couleur_map(POINT p){
    COULEUR c;
    int couleur; 
    
    c = lire_pixel_image(img_map_collision, p);
    
    /*printf("Couleur lue : 0x%08X\n", c);
    printf("Couleur  C1 : 0x%08X\n\n", couleur_RGB(9, 250, 255));
    fflush(stdout);*/
    
    if(c == couleur_RGB(255, 0, 0)){
        couleur = 1;
    }
    
    if(c == couleur_RGB(255, 255, 0)){
        couleur = 2;
    }
    
    if(c == couleur_RGB(9, 250, 255)){
        couleur = 3;
    }
    
    return couleur;
}
