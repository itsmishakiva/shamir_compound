#include "shamir_separation.h"
#include "random_generator.h"
#include "big_math_functions.h"
#include "secret_part.h"

#include <boost/multiprecision/cpp_int.hpp>

std::vector<SecretPart>
ShamirSeparation::separate(const boost::multiprecision::int512_t &m, const unsigned long &k,
                           const unsigned long &n) {
    std::vector<SecretPart> output(0);
    std::vector<boost::multiprecision::int1024_t> coeffs(0);
    boost::multiprecision::int512_t p = BigMathFunctions::generateSimpleNumber(m);
    for (unsigned long i = 1; i <= k; i++) {
        boost::multiprecision::int1024_t rnd = (boost::multiprecision::int1024_t) RandomGenerator::even(1, (boost::multiprecision::int1024_t) p);
        coeffs.push_back(rnd);
    }
    for (unsigned long i = 1; i <= n; i++) {
        boost::multiprecision::int1024_t part = 0;
        for (unsigned long j = k - 1; j > 0; j--) {
            part += (boost::multiprecision::int512_t) BigMathFunctions::powMod((boost::multiprecision::int512_t) i,
                                                                                (boost::multiprecision::int512_t) j,
                                                                                p) * coeffs[j];
        }
        part += m;
        output.emplace_back((boost::multiprecision::int512_t) (part % p), i, k - 1, p);
    }
    return output;
}