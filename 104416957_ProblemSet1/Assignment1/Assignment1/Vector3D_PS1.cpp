//COS30008 - 104416957 - Avery Flannery
//Problem 1 is to extend Vector3D with the toString() method to return a textual representation of a 3D vector

#include "Vector3D.h"

#include <sstream>
#include <iomanip>

using namespace std;

string Vector3D::toString() const noexcept {
    stringstream ss;

    // Check if x, y, and w have decimal parts
    // this is done so that the output is not cluttered and does not go into decimals if unnecessary
    bool hasDecimals = (x() != static_cast<int>(x())) ||
        (y() != static_cast<int>(y())) ||
        (w() != static_cast<int>(w()));

    if (hasDecimals) {
        ss << "[" << fixed << setprecision(4) << x() << ","
            // fixed is used for consistancy and setprecision(4) ensures it only goes to 4 decimal places
            << y() << "," << w() << "]";
    }
    else {
        ss << "[" << static_cast<int>(x()) << "," // Converting to int if no decimals
            << static_cast<int>(y()) << ","
            << static_cast<int>(w()) << "]";
    }

    return ss.str();
}
