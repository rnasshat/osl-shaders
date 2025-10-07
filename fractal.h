#define ESCAPE_TIME_FRACTAL(n, f) shader node_fractal_##n( \
    point Pos = P, \
    complex seed = {0, 0}, \
    complex Power = {2, 0}, \
    float bailout = 50.0, \
    int iterations = 256, \
    int smooth = 1 [[ string widget = "boolean" ]], \
    int julia = 0 [[ string widget = "boolean" ]], \
    int trap_type = 0 [[ string widget = "boolean" ]], \
    point orbit_trap = point(0, 0, 0), \
    output float fac = 0.0, \
    output complex z = {0, 0}, \
    output int inside = 1, \
    output vector trap_dist = vector(0x0FFFFFFF, 0x0FFFFFFF, 0)) \
{ \
    complex c; \
    if(julia) \
    { \
        z = complex(Pos[0], Pos[1]); \
        c = complex(seed.real, seed.imag); \
    } else { \
        z = complex(0, 0); \
        c = complex(Pos[0], Pos[1]); \
    } \
     \
    int iter_num = 0; \
     \
    for(int i=0; i<iterations; i++) \
    { \
        iter_num = i; \
         \
        /* main iterated function */ \
        f; \
         \
        /* orbit traps */ \
        if(trap_type == 0) /* 0 = axis-aligned lines */ \
        { \
            trap_dist.x = min(trap_dist.x, abs(orbit_trap.x - z.real)); \
            trap_dist.y = min(trap_dist.y, abs(orbit_trap.y - z.imag)); \
        } else { /* 1 = point with angle */ \
            trap_dist.x = min(trap_dist.x, distance({z.real, z.imag, 0}, {orbit_trap.x, orbit_trap.y, 0})); \
            trap_dist.y = min(trap_dist.y, atan2(z.imag - orbit_trap.y, z.real - orbit_trap.x)); \
        } \
         \
        if(z.real*z.real + z.imag*z.imag > bailout*bailout) \
        { \
            inside = 0; \
            break; \
        } \
    } \
     \
    /*
        Thanks to https://iquilezles.org/articles/msetsmooth/ 
        for help with math for smooth coloring
    */ \
    if(smooth == 0) \
        fac = (float)iter_num/((float)iterations - 1.0); \
    else { \
        complex temp = ((float)iter_num - (log(log(cabs(z), bailout)) / log(Power)))/((float)iterations - 1.0); \
        fac = temp.real; \
    } \
}