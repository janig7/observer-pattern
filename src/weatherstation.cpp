#include "weatherstation.h"
#include "observer.h"

void WeatherStation::Add(IObserver *observer) {
    list_observer_.push_back(observer);
}

void WeatherStation::Remove(IObserver *observer) {
    list_observer_.remove(observer);
}

void WeatherStation::Notify() {
    std::list<IObserver *>::iterator iterator = list_observer_.begin();
    HowManyObserver();
    while (iterator != list_observer_.end()) {
        (*iterator)->Update(temperature, humidity, pressure);
        ++iterator;
    }
}

void WeatherStation::HowManyObserver() {
    std::cout << "There are " << list_observer_.size() << " observers in the list.\n";
}

void WeatherStation::SetState(float temperature, float pressure, float humidity) {
    this->temperature = temperature;
    this->pressure = pressure;
    this->humidity = humidity;
    Notify();
}
