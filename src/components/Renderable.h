#pragma once
#include "components/AbstractComponent.h"
//Component that can be rendered
class Renderable : public AbstractComponent //DO TO : Change that inheritance to something better, it's bad way to handle it, too lazy to change it now so deal with it for the time
{
public:
    Renderable();
    ~Renderable();

    virtual void render();
};

