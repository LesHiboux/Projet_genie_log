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

4		(nombre de lignes de la map)
6		(nombre de colonnes de la map)
000000
001000		(matrice des entités de la map)
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






Liste des monstres

- Le fichier doit être nommé comme suit: ./config/monstres.db
- Chaque ligne représete un monstre suivant le meme paterne qu'un Character
- Le nombre de lignes (nombre de monstres) >= nombre de monstres décrits dans map (nombre de cases monstre)
- L'apparition des monstres se fera dans l'ordre inverse des lignes du document


Liste des personnages jouables
- Le fichier doit se nommer: ./config/liste_persos.db
- Chaques ligne représente un personnage
- Après le dernier personnage, le fichier doit se terminer par une ligne vide


Lors d'un combat, si le joueur et le monstre ont la même vitesse, le joueur est prioritaire.
            Je vérifie après chaques action (attaque du joueur ou du monstre) si l'un des deux characters est mort, ainsi, les deux characters ne sont pas censés mourir en même temps
            Mais si cela devait arriver, le joueur étant mort, le combat et le jeu seraient perdus.




La présentation de la ligne de création du personnage va être divisée en 3 parties:

Les jauges (Vie et Mana) se présentent sous cette forme:
            Quantité actuelle/Quantité totale
Exemple: 15/20

Les compétences:
            Nom de la compétence/Dégâts/Coût en Mana/Priorité/Cible
Exemple: Attaque de base/3/0/2/0
            L'attaque se nomme "Attaque de base", fait 3 de dégâts, ne coûte pas de Mana, a un niveau de priorité de 2 et cible l'ennemi. Pour se cibler soi-même, il faut mettre un 1 à la place du 0 de la Cible.
            
Enfin, le personnage en général:
            {Nom du personnage;Jauge de Vie; Jauge de Mana;Nombre de Compétences;Compétence 1;Compétence 2;...(autant qu'il y a de Compétences);Vitesse}

Exemple: {Player 1;20/20;12/12;3;Attaque de base/3/0/2/0;Attaque puissante/8/3/2/0;Soin/-4/2/0/1;70}
            Le personnage se nomme "Player 1"
            Il a au maximum 20PV et a toute sa vie.
            De même pour sa Mana qui est à un maximum de 12 points.
            Il a 3 compétences nommées "Attaque de base", "Attaque puissante" et "Soin".
            Vous pourrez voir qu'un sort de régénération prend une valeur négative pour la statistique qu'elle régénère.



/!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\
/!\ S'assurer que "TheGame.exe" puisse bel et bien être exécuté /!\
/!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\



De plus, pour chacun des choix que vous devrez faire, il faudra entrer votre choix puis taper sur la touche "Entrée".

Par exemple, en combat, pour choisir la compétence 2, il faut d'abord entrer la valeur "2" puis faire "Entrée".
De même pour un déplacement sur la map, entrer "z", "q", "s" ou "d" puis faire "Entrée".
