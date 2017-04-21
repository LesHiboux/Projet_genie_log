#include <iostream>
#include <string>
#include <utility>

#ifndef GAUGE_H
#define GAUGE_H

class Gauge                                         // Jauge
{
    public:
        //!Constructeur de Gauge par défault
        Gauge();                                    // Ctor par défaut
        
        //!Constructeur de Gauge
        /*!Construit à partir d'une string
           \param Name le nom de la gauge
           \param gauge string contenant les infos de la gauge: val min et val max
        */
        Gauge(std::string name, std::string gauge);            // Ctor à partir d'un String
    
        //!Destructuer de Gauge
        virtual ~Gauge();                           // Dtor
    
        //!Interface de Gauge
        /*!
            Retourne une pair <Restant, Max>
        */
        std::pair <int, int> getValMax();           // Renvoie la paire <Restant, Max>
    
        //!Interface de Gauge
        /*! Retourne la valeur Max */
        int getMax();                               // Renvoie la valeur Max
    
        //!Interface de Gauge
        /*! Retourne la Valeur Restante */
        int getVal();                               // Renvoie la valeur Restant
    
        //!
        /*! Modifie la valeur Restante
            Restant = Restant - value
            \param value valeur pour modifier la valeur Restant (value <0 Régénération)
        */
        void edit(int value);                             // Modifie la valeur Restant selon une valeur donnée (Valeur négative = Régénération)

    protected:

    private:
        std::string name;                           // Nom de la Jauge
        std::pair <int, int> ValueMax;              // Paire de valeurs <Restant, Max>
};

#endif // GAUGE_H
