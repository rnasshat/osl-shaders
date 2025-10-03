#pragma once

struct splitc {
    float real;
    float imag;
};

splitc __operator__add__ (splitc a, splitc b) {
    return splitc(a.real + b.real, a.imag + b.imag);
}

splitc __operator__add__ (float a, splitc b) {
    return splitc(a, 0) + b;
}

splitc __operator__sub__ (splitc a, splitc b) {
    return splitc(a.real - b.real, a.imag - b.imag);
}

splitc __operator__sub__ (float a, splitc b) {
    return splitc(a - b.real, -b.imag);
}

splitc __operator__mul__ (splitc a, splitc b) {
    return splitc(a.real*b.real + a.imag*b.imag, a.real*b.imag + a.imag*b.real);
}

splitc __operator__mul__ (float a, splitc b) {
    return splitc(a, 0) * b;
}

splitc __operator__mul__ (splitc a, float b) {
    return a * splitc(b, 0);
}

float smod (splitc s) {
    return sqrt(s.real*s.real - s.imag*s.imag);
}
