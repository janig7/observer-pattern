#ifndef _OBSERVER_H
#define _OBSERVER_H

class IObserver {
    public:
    virtual ~IObserver() {};
    virtual void Update(const std::string &message_from_subject) = 0;
};

#endif