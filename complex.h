#pragma once

struct complex {
    float real;
    float imag;
};

complex __operator__add__ (complex a, complex b) {
    return complex(a.real + b.real, a.imag + b.imag);
}

complex __operator__sub__ (complex a, complex b) {
    return complex(a.real - b.real, a.imag - b.imag);
}

complex __operator__mul__ (complex a, complex b) {
    return complex(a.real*b.real - a.imag*b.imag, a.real*b.imag + a.imag*b.real);
}

float cabs (complex c) {
    return sqrt(c.real*c.real + c.imag*c.imag);
}

float carg (complex c) {
    return atan2(c.imag, c.real);
}

complex pow (complex c, float e) {
    float phi = carg(c);
    float r = cabs(c);
    
    return complex(cos(e*phi) * pow(r, e), sin(e*phi) * pow(r, e));
}

complex log (complex c) {
    return complex(log(cabs(c)), carg(c));
}