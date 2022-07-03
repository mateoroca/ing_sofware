#ifndef ICOMPOSABLEOFLISTABLE_
#define ICOMPOSABLEOFLISTABLE_

#include "./Ilistable.h"


class IcomposableOflistable
{  private:
    
    public:
        virtual ~IcomposableOflistable(){};
        virtual void add(Ilistable* component) = 0;
        virtual void remove(Ilistable* component) = 0;
};

#endif