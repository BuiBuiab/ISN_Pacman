void dessiner_map(){
    POINT p;
    
    p.x = LARGEUR/2;
    p.y = HAUTEUR/2;
    
    dessiner_image(img_map, p);
}

//renvoie 1 ou 2 en fonction de la couleur du pixel sur la map_collisions
int couleur_map(IMAGE map, POINT p){
    COULEUR c; 
    
    c = lire_pixel_image(map, p);
    
    if(c == couleur_RGB(255, 0, 0)){
        return 1;
    }
    
    if(c == couleur_RGB(0, 255, 255)){
        return 2;
    }
}
