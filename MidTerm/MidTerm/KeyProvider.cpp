// COS30008 - 104416957 - Avery Flannery. Semester 1 2024
// MidTerm - KeyProvider

#include "KeyProvider.h"
#include <cassert>
#include <cctype>

// removes any non-alphabetical characters and converts them to uppercase
std::string KeyProvider::preprocessString(const std::string& aString) noexcept {
    std::string result;
    for (char c : aString) {
        if (std::isalpha(c)) {
            result.push_back(std::toupper(c));
        }
    }
    return result;
}

// constructor 
KeyProvider::KeyProvider(const std::string& aKeyword, const std::string& aSource) noexcept :
    fKeys(preprocessString(aSource)), 
    fIndex(0) // initialize fIndex to 0
{
    // assert to ensure the length of fKeys is less than or equal to the length of the preprocessed source string
    assert(fKeys.length() <= preprocessString(aSource).length());

    // reserve space in fKeys to avoid reallocations
    fKeys.reserve(aSource.length());

    // fill fKeys with the keyword characters, repeating if necessary
    for (size_t i = 0; i < fKeys.length(); ++i) {
        fKeys[i] = preprocessString(aKeyword)[i % preprocessString(aKeyword).length()];
    }
}

// deference operator 
char KeyProvider::operator*() const noexcept {
    return fKeys[fIndex];
}

// prefix increment operator
KeyProvider& KeyProvider::operator++() noexcept {
    ++fIndex;
    return *this;
}

// postfix increment operator 
KeyProvider KeyProvider::operator++(int) noexcept {
    KeyProvider temp(*this);
    ++(*this);
    return temp;
}

// == equals comparison of iterators
bool KeyProvider::operator==(const KeyProvider& aOther) const noexcept {
    return fIndex == aOther.fIndex && fKeys == aOther.fKeys;
}

// != does not equal comparison of iterators
bool KeyProvider::operator!=(const KeyProvider& aOther) const noexcept {
    return !(*this == aOther);
}

// return an iterator positioned at the first keyword character
KeyProvider KeyProvider::begin() const noexcept {
    KeyProvider begite(*this);
    begite.fIndex = 0;
    return begite;
}

// return an iterator positioned after the last keyword character
KeyProvider KeyProvider::end() const noexcept {
    KeyProvider endite(*this);
    endite.fIndex = fKeys.size();
    return endite;
}
