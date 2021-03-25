#ifndef _OBSERVER_H
#define _OBSERVER_H

class IObserver {
    public:
    virtual ~IObserver() {};
    virtual void Update(float temperature, float pressure, float humidity) = 0;
};

#endif