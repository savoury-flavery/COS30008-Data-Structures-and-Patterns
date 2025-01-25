#include "PalindromeStringIterator.h"
#include <cctype>

void PalindromeStringIterator::moveToNextIndex()
{
    while (fIndex < static_cast<int>(fString.size()) && !std::isalpha(fString[fIndex]))
    {
        fIndex++;
    }
}

void PalindromeStringIterator::moveToPreviousIndex()
{
    while (fIndex >= 0 && !std::isalpha(fString[fIndex]))
    {
        fIndex--;
    }
}

PalindromeStringIterator::PalindromeStringIterator(const std::string& aString)
    : fString(aString), fIndex(-1)
{

    for (char& c : fString)
    {
        c = std::toupper(c);
    }
}

char PalindromeStringIterator::operator*() const noexcept
{
    return fString[fIndex];
}

PalindromeStringIterator& PalindromeStringIterator::operator++() noexcept
{
    fIndex++;
    moveToNextIndex();
    return *this;
}

PalindromeStringIterator PalindromeStringIterator::operator++(int) noexcept
{
    PalindromeStringIterator old = *this;
    ++(*this);
    return old;
}

PalindromeStringIterator& PalindromeStringIterator::operator--() noexcept
{
    fIndex--;
    moveToPreviousIndex();
    return *this;
}

PalindromeStringIterator PalindromeStringIterator::operator--(int) noexcept
{
    PalindromeStringIterator old = *this;
    --(*this);
    return old;
}

bool PalindromeStringIterator::operator==(const PalindromeStringIterator& aOther) const noexcept
{
    return fIndex == aOther.fIndex;
}

bool PalindromeStringIterator::operator!=(const PalindromeStringIterator& aOther) const noexcept
{
    return !(*this == aOther);
}

PalindromeStringIterator PalindromeStringIterator::begin() const noexcept
{
    PalindromeStringIterator it(fString);
    it.fIndex = 0;
    it.moveToNextIndex();
    return it;
}

PalindromeStringIterator PalindromeStringIterator::end() const noexcept
{
    PalindromeStringIterator it(fString);
    it.fIndex = static_cast<int>(fString.size());
    return it;
}

PalindromeStringIterator PalindromeStringIterator::rbegin() const noexcept
{
    PalindromeStringIterator it(fString);
    it.fIndex = static_cast<int>(fString.size()) - 1;
    it.moveToPreviousIndex();
    return it;
}

PalindromeStringIterator PalindromeStringIterator::rend() const noexcept
{
    PalindromeStringIterator it(fString);
    it.fIndex = -1;
    return it;
}