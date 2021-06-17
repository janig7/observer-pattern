#ifndef _WEATHERSTATION_H
#define _WEATHERSTATION_H
#include "observable.h"
#include <iostream>
#include <list>

///
/// Klasa stacja pogodowa implementująca interfejs IObservable 
///

class WeatherStation : public IObservable {
    public:
        /**
        Metoda, która dodająca obserwatora do listy obserwatorów 
        @param IObserver  obiekt obserwatora
        @return void
        */
        void Add(IObserver *observer) override;
        /**
        Metoda usuwająca obserwatora z listy obserwatorów.
        @param IObserver  obiekt obserwatora
        @return void
        */
        void Remove(IObserver *observer) override;
        /**
        Metoda informująca wszystkich obserwatorów o zmianach pogody.
        @param void
        @return void 
        */
        void Notify() override;
        /**
        Metoda informująca ilu jest obserwatorów stacji pogodowej
        @param void
        @return void
        */
        void HowManyObserver();
        /**
        Metoda ustawiająca nowe warunki pogodowe i informująca subskrybentów o zmianach
        @param temperature zmiennoprzecinkowa liczba oznaczająca temperature
        @param pressure zmiennoprzecinkowa liczba okreslajaca cisnienie
        @param humidity zmiennoprzecinkowa liczba określająca wilgotnosc
        @return void 
        */
        void SetState(float temperature, float pressure, float humidity);


        std::list <IObserver *> list_observer_;
        float temperature;
        float humidity;
        float pressure;
};

#endif
