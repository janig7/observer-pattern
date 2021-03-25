#ifndef _CLIENT_H
#define _CLIENT_H
#include "observer.h"
#include "weatherstation.h"

class Client : public IObserver {
public:
    Client(WeatherStation &weatherstation);
    void Update(float temperature, float pressure, float humidity) override;
    void removeMeFromList();
    

    private:
        WeatherStation &weatherstation_;

};


#endif