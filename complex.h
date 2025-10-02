#pragma once

struct complex {
    float real;
    float imag;
};

complex recip (complex c) {
    float abs_sq = c.real*c.real + c.imag*c.imag;
    return complex(c.real/abs_sq, -c.imag/abs_sq);
}

complex __operator__add__ (complex a, complex b) {
    return complex(a.real + b.real, a.imag + b.imag);
}

complex __operator__add__ (float a, complex b) {
    return complex(a, 0) + b;
}

complex __operator__sub__ (complex a, complex b) {
    return complex(a.real - b.real, a.imag - b.imag);
}

complex __operator__sub__ (float a, complex b) {
    return complex(a - b.real, -b.imag);
}

complex __operator__mul__ (complex a, complex b) {
    return complex(a.real*b.real - a.imag*b.imag, a.real*b.imag + a.imag*b.real);
}

complex __operator__mul__ (float a, complex b) {
    return complex(a, 0) * b;
}

complex __operator__mul__ (complex a, float b) {
    return a * complex(b, 0);
}

complex __operator__div__ (complex a, complex b) {
    return a * recip(b);
}

complex __operator__div__ (float a, complex b) {
    return complex(a, 0) * recip(b);
}

complex __operator__div__ (complex a, float b) {
    return a * recip(complex(b, 0));
}

float cabs (complex c) {
    return sqrt(c.real*c.real + c.imag*c.imag);
}

float carg (complex c) {
    return atan2(c.imag, c.real);
}

complex sin (complex c) {
    return complex(sin(c.real) * cosh(c.imag), cos(c.real) * sinh(c.imag));
}

complex cos (complex c) {
    return complex(cos(c.real) * cosh(c.imag), 0.0 - sin(c.real) * sinh(c.imag));
}

complex log (complex c) { //principal value
    return complex(log(cabs(c)), carg(c));
}

complex exp (complex c) {
    return complex(exp(c.real) * cos(c.imag), exp(c.real) * sin(c.imag));
}

complex pow (complex c, float e) {
    float phi = carg(c);
    float r = cabs(c);
    
    return complex(cos(e*phi) * pow(r, e), sin(e*phi) * pow(r, e));
}

complex pow (complex c, complex e) {
    return exp(e * log(c));
}