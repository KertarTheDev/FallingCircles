#include "fcUtilities.h"
#include <QtGlobal>

//==========================================================================
//! \brief Returns a pseudo-random value in the range [0,1]
float NfcUtilities::uniformRandomVal()
{
    return static_cast<float>(qrand())/RAND_MAX;
}
//==========================================================================
//! \brief Returns a pseudo-random value in the range [min, max]
float NfcUtilities::uniformRandomVal(float min, float max)
{
    float range = max-min;
    return min + range*uniformRandomVal();
}
//==========================================================================
