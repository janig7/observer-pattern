#include "client.h"


Client::Client(WeatherStation &weatherstation) : weatherstation_(weatherstation) {
    this->weatherstation_.Add(this);
    std::cout<<"Client created!";
}
/**
Metoda informująca o nowych warunkach pogodowych 
@param temperature zmiennoprzecinkowa liczba oznaczająca temperature
@param pressure zmiennoprzecinkowa liczba okreslajaca cisnienie
@param humidity zmiennoprzecinkowa liczba określająca wilgotnosc
@return void 
*/
void Client::Update(float temperature, float pressure, float humidity) {
    std::cout << "New temperature: " << temperature << ", pressure: " << pressure << ", humidity: " << humidity << std::endl;
}
