#pragma once

class IObserver {
public:
    virtual ~IObserver() = default;
    virtual void Update() = 0;  // Pure virtual function
};

class ISubject {
public:
    virtual ~ISubject() = default;
    virtual void Attach(IObserver* observer) = 0;  // Pure virtual function
    virtual void Detach(IObserver* observer) = 0;  // Pure virtual function
    virtual void Notify() = 0;  // Pure virtual function
};
