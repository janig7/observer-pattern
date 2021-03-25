#ifndef _WEATHERSTATION_H
#define _WEATHERSTATION_H
#include "observable.h"
#include <iostream>
#include <list>

class WeatherStation : public IObservable {
    public: 
        void Add(IObserver *observer) override;
        void Remove(IObserver *observer) override;
        void Notify() override;
        void HowManyObserver();
        void SetState(float temperature, float pressure, float humidity);



    private:
        std::list <IObserver *> list_observer_;
        float temperature;
        float humidity;
        float pressure;
};

#endif