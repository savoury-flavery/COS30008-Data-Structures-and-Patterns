// COS30008 - 104416957 - Avery Flannery. Semester 1 2024
// MidTerm - VigenereForwardIterator


#include <cctype>

#include "VigenereForwardIterator.h"
 
// encode function
void VigenereForwardIterator::encodeCurrentChar() noexcept
{
    if (std::isalpha(fSource[fIndex]))
    {
        char sChar = fSource[fIndex];
        char kChar = std::toupper(*fKeys);

        if (std::islower(sChar))
        {
            fCurrentChar = std::tolower(fMappingTable[kChar - 'A'][std::toupper(sChar) - 'A']);
        }
        else
        {
            fCurrentChar = fMappingTable[kChar - 'A'][std::toupper(sChar) - 'A'];
        }
        ++fKeys;
    }
    else
    {
        fCurrentChar = fSource[fIndex];
    }
}

// decode function
void VigenereForwardIterator::decodeCurrentChar() noexcept
{
    if (std::isalpha(fSource[fIndex]))
    {
        char sChar = fSource[fIndex];
        char kChar = std::toupper(*fKeys);

        for (int i = 0; i < CHARACTERS; ++i)
        {
            if (std::islower(sChar))
            {
                if (std::tolower(fMappingTable[kChar - 'A'][i]) == std::tolower(sChar))
                {
                    fCurrentChar = std::tolower('A' + i);
                    break;
                }
            }
            else
            {
                if (fMappingTable[kChar - 'A'][i] == std::toupper(sChar))
                {
                    fCurrentChar = 'A' + i;
                    break;
                }
            }
        }
        ++fKeys;
    }
    else
    {
        fCurrentChar = fSource[fIndex];
    }
}


// constructor 
VigenereForwardIterator::VigenereForwardIterator(const std::string& aKeyword, const std::string& aSource, EVigenereMode aMode) noexcept :
    fMode(aMode),
    fKeys(aKeyword, aSource),
    fSource(aSource),
    fIndex(0),
    fCurrentChar('\0')
{
    initializeTable();
    if (!fSource.empty())
    {
        if (fMode == EVigenereMode::Encode)
            encodeCurrentChar();
        else
            decodeCurrentChar();
    }
}


// deference operator 
char VigenereForwardIterator::operator*() const noexcept {
    //returning the current character
    return fCurrentChar;
}

// prefix increment operator
VigenereForwardIterator& VigenereForwardIterator::operator++() noexcept {
    ++fIndex;
    if (fIndex < fSource.size()) {
        if (fMode == EVigenereMode::Encode)
            encodeCurrentChar();
        else
            decodeCurrentChar();
    }
    return *this;
}

// postfix increment operator 
VigenereForwardIterator VigenereForwardIterator::operator++(int) noexcept {
    VigenereForwardIterator temp = *this;
    ++(*this);
    return temp;
}

// == equals comparison of iterators
bool VigenereForwardIterator::operator==(const VigenereForwardIterator& aOther) const noexcept {
    return (fIndex == aOther.fIndex) && (fSource == aOther.fSource);
}

// != does not equal comparison of iterators
bool VigenereForwardIterator::operator!=(const VigenereForwardIterator& aOther) const noexcept {
    return !(*this == aOther);
}

// return an iterator positioned at the first keyword character
VigenereForwardIterator VigenereForwardIterator::begin() const noexcept {
    VigenereForwardIterator begite = *this;
    begite.fIndex = 0;
    return begite;
}

// return an iterator positioned after the last keyword character
VigenereForwardIterator VigenereForwardIterator::end() const noexcept
{
    VigenereForwardIterator endite = *this;
    endite.fIndex = fSource.size();
    return endite;
}