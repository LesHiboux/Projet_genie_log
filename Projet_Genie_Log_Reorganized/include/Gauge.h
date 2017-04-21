#include <iostream>
#include <string>
#include <utility>

#ifndef GAUGE_H
#define GAUGE_H

class Gauge                                         // Jauge
{
    public:
        Gauge();                                    // Ctor par défaut
        Gauge(std::string, std::string);            // Ctor à partir d'un String
        virtual ~Gauge();                           // Dtor
        std::pair <int, int> getValMax();           // Renvoie la paire <Restant, Max>
        int getMax();                               // Renvoie la valeur Max
        int getVal();                               // Renvoie la valeur Restant
        void edit(int);                             // Modifie la valeur Restant selon une valeur donnée (Valeur négative = Régénération)

    protected:

    private:
        std::string name;                           // Nom de la Jauge
        std::pair <int, int> ValueMax;              // Paire de valeurs <Restant, Max>
};

#endif // GAUGE_H
