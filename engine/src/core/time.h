#pragma once 

#include "../defines.h"

struct s_time {
    double delta;
    double absolute;
};

OX_API double getTime();

OX_API double setTime(double value);