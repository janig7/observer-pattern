#ifndef _OBSERVABLE_H
#define _OBSERVABLE_H

class IObservable {
    public:
    virtual ~IObservable() {};
    virtual void Add(IObserver *observer) = 0;
    virtual void Remove(IObserver *observer) = 0;
    virtual void Notify()  = 0;
};

#endif 