#include "./include/Character.cpp"

int main()
{
    Character player("{Bryan;15/15;10/10;1;Lancer de banane/1/0/1/0;70}");                                          // Chara fonctionnel

    Character player1("{Bryan;15;10/10;1;Lancer de banane/1/0/1/0;70}");                                            // Erreur vie

    Character player2("{Bryan;15/15;10;1;Lancer de banane/1/0/1/0;70}");                                            // Erreur mana

    Character player3("{Bryan;15/15;10/10;2;Lancer de banane/1/0/1/0;70}");                                         // Erreur nb Skills < nb demandé

    Character player4("{Bryan;15/15;10/10;1;Lancer de banane/1/0/1/0; Lancer de tomate/1/0/1/0;70}");               // Erreur nb Skills > nb demandé

    Character player5("{Bryan;15/15;10/10;1;Lancer de banane/1/0/-1/0;70}");                                        // Erreur Skill priorité invalide

    Character player5("{Bryan;15/15;10/10;1;Lancer de banane/-1/-0/1/1;70}");                                       // Chara fonctionnel -- Demonstration degats/mana_cost négatifs (régén) fonctionnel + cible soi-même (target = 1)

    Character player6("{Bryan;15/15;10/10;1;Lancer de banane/1/0/1/0;}");                                           // Erreur speed

    Character player7("{Bryan;15/15;10/10;1;Lancer de banane/1/0/1/0;-70}");                                        // Erreur speed (>0)

    affiche(player);
}

void affiche(Character player)
{
    std::cout << "Nom: " << player.getName() << std::endl << std::flush;

    std::cout << "## " << std::flush;

    std::cout << "Vie: " << player.getLife().first << "/" << player.getLife().second << std::endl << std::flush;

    std::cout << "## " << std::flush;

    std::cout << "Mana: " << player.getMana().first << "/" << player.getMana().second << std::endl << std::flush;

    std::cout << "## " << std::flush;

    std::cout << "nbSkills: " << player.getNbSkills() << std::endl << std::flush;

    for (int i = 0; i < player.getNbSkills(); i++)
    {
        Skill skill = player.getSkill(i);

        std::cout << "## ## " << std::flush;

        std::cout << "Skill " << i << ": " << skill.getName() << std::endl << std::flush;

        std::cout << "## ## " << std::flush;

        std::cout << "-- " << "Degats: " << skill.getDamage() << std::endl << std::flush;

        std::cout << "## ## " << std::flush;

        std::cout << " -- " << "Coût en Mana: " << skill.getManaCost() << std::endl << std::flush;

        std::cout << "## ## " << std::flush;

        std::cout << "-- " << "Niveau de priorité: " << skill.getPriority() << std::endl << std::flush;

        std::cout << "## ## " << std::flush;

        if (skill.getTarget == 0)
            std::cout << "-- " << "Cible: Monstre" << std::endl << std::flush;
        else
            std::cout << "-- " << "Cible: Lui-même" << std::endl << std::flush;

        std::cout << "## ## " << std::flush;

        if (player.available(skill))
            std::cout << "Compétence utilisable (assez de mana)" << std::endl << std::flush;

        else
            std::cout << "Compétence inutilisable (pas assez de mana)" << std::endl << std::flush;
    }

    std::cout << "## " << std::flush;

    std::cout << "Speed: " << player.getSpeed() << std::endl << std::flush;

    std::cout << std::endl << std::endl << "Tests sur la vie (le résultat serait le même sur le Mana)" << std::endl << std::flush;

    std::cout << "Vie actuelle: " << player.getLife().first << std::flush;

    player.editLife(5)
    std::cout << " || Perte de 5 PV || " << std::flush;

    std::cout << "Vie restante: " << player.getLife().first << std::endl << std::flush;

    player.editLife(-6)
    std::cout << " || Regain de 6 PV || " << std::flush;

    std::cout << "Vie restante: " << player.getLife().first << std::endl << std::flush;                             // Démonstration que Vie actuelle <= Vie mac

    player.editLife(20)
    std::cout << " || Perte de 20 PV || " << std::flush;

    std::cout << "Vie restante: " << player.getLife().first << std::endl << std::flush;                              // Démonstration que Vie actuelle >= 0

    player.editLife(-6)
    std::cout << " || Regain de 6 PV || " << std::endl << std::flush;

    if (player.isAlive())
        std::cout << "Joueur vivant" << std::endl << std::flush;
    else
        std::cout << "Joueur mort" << std::endl << std::flush;

    player.editLife(6)
    std::cout << " || Perte de 6 PV || " << std::endl << std::flush;

    if (player.isAlive())
        std::cout << "Joueur vivant" << std::endl << std::flush;
    else
        std::cout << "Joueur mort" << std::endl << std::flush;



}
