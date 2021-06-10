# Observer pattern

The observer pattern is a software design pattern in which
an object, called the subject or observable, manages a list
of dependents, called observers, and notifies them automatically
of any internal state changes, and calls one of thier methods.

## Running

    1.Clone this repo.
    2.Go into observer-pattern directory.
    3.Run `make weatherstation` and build program.
    4.Run `make run`.
    5.Run `make clean` to remove executable files.

## File structure

**src**: Application source files. <br/>
**include**: All project header files.

## source files

**client.cpp**: contains implementation of methods for the client class <br/>
**weatherstation.cpp**: contains implementation of methods for the WeatherStation class <br/>
**main.cpp**: client code - here u can deal with weatherstation :)

## include files

**observable.h**: declaration of interface for ovservables classes <br />
**observer.h**: declaration of interface for observers classes <br />
**client.h**: declaration of client class <br />
**weatherstation.h**: declaration of weatherstation class <br />

![uml](https://user-images.githubusercontent.com/85672253/121580477-16376400-ca2d-11eb-835c-e8aca578fbe6.png)