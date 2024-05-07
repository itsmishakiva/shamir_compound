#ifndef LAB_2_BIG_MATH_FUNCTIONS_H
#define LAB_2_BIG_MATH_FUNCTIONS_H

#include <boost/multiprecision/cpp_int.hpp>
#include <utility>
#include <iostream>
#include "random_generator.h"

class BigMathFunctions {
public:
    static boost::multiprecision::int512_t generateSimpleNumber(boost::multiprecision::int512_t t);

    static boost::multiprecision::int1024_t
    powMod(boost::multiprecision::int1024_t a, boost::multiprecision::int1024_t w,
           const boost::multiprecision::int1024_t &n);

    static boost::multiprecision::int1024_t
    divideMod(boost::multiprecision::int1024_t a, boost::multiprecision::int1024_t b,
              boost::multiprecision::int1024_t m);
};


#endif
