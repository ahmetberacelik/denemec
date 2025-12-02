#include "../header/gymmanager.h"
#include <stdexcept>

using namespace Coruh::Gymmanager;

double Gymmanager::add(double a, double b) {
    return a + b;
}

double Gymmanager::subtract(double a, double b) {
    return a - b;
}

double Gymmanager::multiply(double a, double b) {
    return a * b;
}

double Gymmanager::divide(double a, double b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero is not allowed.");
    }
    return a / b;
}