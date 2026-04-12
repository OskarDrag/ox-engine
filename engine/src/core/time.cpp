#include "time.h"

#include "../includes/vendor.h"


double getTime() {
    return glfwGetTime();
}

double setTime(double value) {
    glfwSetTime(value);
    return value;
}