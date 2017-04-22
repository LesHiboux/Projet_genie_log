#include <iostream>
#include <string>
#include <utility>

#ifndef GAUGE_H
#define GAUGE_H

class Gauge                                         // Jauge
{
    public:
        //!Constructeur de Gauge par défault
        Gauge();
        
        //!Constructeur de Gauge
        /*!Construit à partir d'une string
           \param Name le nom de la gauge
           \param gauge string contenant les infos de la gauge: val min et val max
        */
        Gauge(std::string name, std::string gauge);
    
        //!Destructeur de Gauge
        virtual ~Gauge();
    
        //!Interface valeurs de la Gauge
        /*! \return Une pair <Restant, Max> */
        std::pair <int, int> getValMax();
    
        //!Interface valeur Max
        /*! \return Un entier représentant la valeur Max */
        int getMax();
    
        //!Interface valeur restante
        /*! \return Un entier représentant la valeur Restante */
        int getVal();
    
        //!Modifie la valeur Restante
        /*! 
            Restant = Restant - value
            \param value valeur pour modifier la valeur Restant (value <0 Régénération)
        */
        void edit(int value);

    protected:

    private:
        std::string name;                           // Nom de la Jauge
        std::pair <int, int> ValueMax;              // Paire de valeurs <Restant, Max>
};

#endif // GAUGE_H
