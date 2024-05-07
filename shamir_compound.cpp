#include "shamir_compound.h"
#include "big_math_functions.h"
#include <vector>

boost::multiprecision::int512_t
ShamirCompound::compound(const std::vector<SecretPart> &parts) {
    std::vector<boost::multiprecision::int512_t> coeffs(0);
    for (unsigned long a = 0; a < parts.size(); a++) {
        boost::multiprecision::int512_t coef = 0;
        for (unsigned long i = 0; i < parts.size(); i++) {
            boost::multiprecision::int512_t l = 1;
            for (unsigned long j = 0; j < parts.size(); j++) {
                if (i == j) continue;
                l *= (boost::multiprecision::int512_t)(BigMathFunctions::divideMod(((boost::multiprecision::int512_t)a - parts[j].index),
                                                                  ((boost::multiprecision::int512_t)parts[i].index - parts[j].index),
                                                                  parts[a].fieldMod));
            }
            l %= parts[a].fieldMod;
            coef += l * parts[i].part;
            coef %= parts[a].fieldMod;
        }
        coeffs.emplace_back(coef);
    }
    return coeffs[0];
}