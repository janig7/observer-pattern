#ifndef _CLIENT_H
#define _CLIENT_H
#include "observer.h"
#include "weatherstation.h"

class Client : public IObserver {
public:
    Client(WeatherStation &weatherstation);
    /**
    Metoda informująca o nowych warunkach pogodowych 
    @param temperature zmiennoprzecinkowa liczba oznaczająca temperature
    @param pressure zmiennoprzecinkowa liczba okreslajaca cisnienie
    @param humidity zmiennoprzecinkowa liczba określająca wilgotnosc
    @return void 
    */
    void Update(float temperature, float pressure, float humidity) override;
    void removeMeFromList();
    

    private:
        WeatherStation &weatherstation_;

};


#endif
