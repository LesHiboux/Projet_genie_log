#include "../include/Gauge.h"

Gauge::Gauge()
{
    //ctor
    name = "Gauge";
    ValueMax = std::make_pair(10, 10);
}

Gauge::Gauge(std::string name, std::string gauge)
{
    //ctor
    this->name = name;
    ValueMax = std::make_pair(std::stoi(gauge.substr(0, gauge.find_first_of('/'))), std::stoi(gauge.substr(gauge.find_first_of('/') + 1)));
}

Gauge::~Gauge()
{
    //dtor
}

std::pair <int, int> Gauge::getValMax()
{
    return ValueMax;
}

int Gauge::getVal()
{
    return ValueMax.first;
}

int Gauge::getMax()
{
    return ValueMax.second;
}

void Gauge::edit(int value)
{
    if (value == 0) return;
    else if (value < 0)
    {
        if (ValueMax.first - value > ValueMax.second) ValueMax = std::make_pair(ValueMax.second, ValueMax.second);
        else ValueMax = std::make_pair(ValueMax.first - value, ValueMax.second);
    }
    else if (value > ValueMax.first) ValueMax = std::make_pair(0, ValueMax.second);
    else ValueMax = std::make_pair(ValueMax.first - value, ValueMax.second);
}
