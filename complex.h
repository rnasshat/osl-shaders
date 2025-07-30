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