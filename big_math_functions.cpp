#include "big_math_functions.h"

#include <utility>

boost::multiprecision::int512_t BigMathFunctions::generateSimpleNumber(boost::multiprecision::int512_t t) {
    boost::multiprecision::int512_t p = t + 1;
    if (p % 2 == 0) p++;
    bool simple = false;
    while (!simple) {
        simple = true;
        for (int i = 2; i <= sqrt(p); i++) {
            if (p % i == 0) {
                simple = false;
                p += 2;
                break;
            }
        }
    }
    return p;
}

boost::multiprecision::int1024_t
BigMathFunctions::powMod(boost::multiprecision::int1024_t a, boost::multiprecision::int1024_t w,
                         const boost::multiprecision::int1024_t &n) {
    boost::multiprecision::int1024_t S = 1;
    boost::multiprecision::int1024_t V = std::move(w);
    boost::multiprecision::int1024_t c = std::move(a);
    while (true) {
        if (V == 0) break;
        if (V % 2 == 1) {
            S = (S * c) % n;
            V = (V - 1) / 2;
        } else {
            V = V / 2;
        }
        c = pow(c, 2) % n;
    }
    return S;
}

boost::multiprecision::int1024_t
BigMathFunctions::divideMod(boost::multiprecision::int1024_t a, boost::multiprecision::int1024_t b,
                            boost::multiprecision::int1024_t m) {
    while (a < 0) {
        a += m;
    }
    while (b < 0) {
        b += m;
    }
    boost::multiprecision::int1024_t k = powMod(std::move(b), m - 2, m);
    return (a * powMod(std::move(b), m - 2, m)) % m;
}