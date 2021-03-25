#include "client.h"


Client::Client(WeatherStation &weatherstation) : weatherstation_(weatherstation) {
    this->weatherstation_.Add(this);
    std::cout<<"Client created!";
}

void Client::Update(float temperature, float pressure, float humidity) {
    std::cout << "New temperature: " << temperature << ", pressure: " << pressure << ", humidity: " << humidity << std::endl;
}