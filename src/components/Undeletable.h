#pragma once
#include "components/AbstractComponent.h"
//If this is found on a component, prevent it from being deleted, such as the transform
class Undeletable : public AbstractComponent //DO TO : Change that inheritance to something better, it's bad way to handle it, too lazy to change it now so deal with it for the time
{

};