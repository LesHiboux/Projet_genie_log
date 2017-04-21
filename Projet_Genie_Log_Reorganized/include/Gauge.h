#include <iostream>
#include <string>
#include <utility>

#ifndef GAUGE_H
#define GAUGE_H

class Gauge
{
    public:
        Gauge();
        Gauge(std::string, std::string);
        virtual ~Gauge();
        std::pair <int, int> getValMax();
        int getMax();
        int getVal();
        void edit(int);

    protected:

    private:
        std::string name;
        std::pair <int, int> ValueMax;
};

#endif // GAUGE_H
