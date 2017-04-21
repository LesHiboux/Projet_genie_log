            .         .                                                
           ,8.       ,8.                   .8.          8 888888888o   
          ,888.     ,888.                 .888.         8 8888    `88. 
         .`8888.   .`8888.               :88888.        8 8888     `88 
        ,8.`8888. ,8.`8888.             . `88888.       8 8888     ,88 
       ,8'8.`8888,8^8.`8888.           .8. `88888.      8 8888.   ,88' 
      ,8' `8.`8888' `8.`8888.         .8`8. `88888.     8 888888888P'  
     ,8'   `8.`88'   `8.`8888.       .8' `8. `88888.    8 8888         
    ,8'     `8.`'     `8.`8888.     .8'   `8. `88888.   8 8888         
   ,8'       `8        `8.`8888.   .888888888. `88888.  8 8888         
  ,8'         `         `8.`8888. .8'       `8. `88888. 8 8888         

Fichier de configuration de la map:

Le fichier de la map doit etre enregistré sous le format "map.db"
et doit suivre le pattern suivant:

4		(nombre de ligne de la map)
6		(nombre de colonne de la map)
000000
001000		(matrice des entitées de la map)
000300		(0=case vide; 1=case monstre; 2=zone de soin; 3=zone de départ)
020000

112300
120300		(matrice de l'apparence de la map)
299599		(0=rien; 1=montagne; 2=arbre; 3=chemin; 5=pont; 9=eau)
000300
   _
  / \
 / ! \		NE PAS PLACER LES ZONES MONSTRES HORS D'ATTEINTE DU JOUEUR
/_____\
