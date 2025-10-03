#pragma once

struct dual {
    float real;
    float imag;
};

dual __operator__add__ (dual a, dual b) {
    return dual(a.real + b.real, a.imag + b.imag);
}

dual __operator__add__ (float a, dual b) {
    return dual(a, 0) + b;
}

dual __operator__sub__ (dual a, dual b) {
    return dual(a.real - b.real, a.imag - b.imag);
}

dual __operator__sub__ (float a, dual b) {
    return dual(a - b.real, -b.imag);
}

dual __operator__mul__ (dual a, dual b) {
    return dual(a.real*b.real, a.real*b.imag + a.imag+b.real);
}

dual __operator__mul__ (float a, dual b) {
    return dual(a, 0) * b;
}

dual __operator__mul__ (dual a, float b) {
    return a * dual(b, 0);
}

float dabs (dual d) {
    return abs(d.real);
}