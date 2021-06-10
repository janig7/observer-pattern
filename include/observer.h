#ifndef _OBSERVER_H
#define _OBSERVER_H

///
/// Interfejs wykorzystywany dla klas klienckich
///

class IObserver {
    public:
    virtual ~IObserver() {};
    virtual void Update(float temperature, float pressure, float humidity) = 0;
};

#endif
