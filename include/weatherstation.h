#ifndef _WEATHERSTATION_H
#define _WEATHERSTATION_H
#include "observable.h"
#include <iostream>
#include <list>

class WeatherStation : public IObservable {
    public: 
        virtual ~WeatherStation() {};
        void Add(IObserver *observer) override;
        void Remove(IObserver *observer) override;
        void Notify() override;
        void CreateMessage(std::string message = "Empty");
        void HowManyObserver();
        void setTemperature();



    private:
        std::list <IObserver *> list_observer_;
        std::string message_;
        float temperature;
};

#endif