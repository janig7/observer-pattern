
#include "client.h"
#include "weatherstation.h"


#include <iostream>


int main() {
    WeatherStation *weatherstation = new WeatherStation();
    Client *client1 = new Client(*weatherstation);
    Client *client2 = new Client(*weatherstation);
    weatherstation->SetState(25.3, 115.4, 263);

    delete weatherstation;
    delete client1;
    delete client2;
    return 0;

}