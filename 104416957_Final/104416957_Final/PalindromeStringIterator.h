#pragma once

#include <string>

class PalindromeStringIterator {
private:
    std::string fString;
    int fIndex;

    void moveToNextIndex();
    void moveToPreviousIndex();

public:
    PalindromeStringIterator(const std::string& aString);

    char operator*() const noexcept;

    PalindromeStringIterator& operator++() noexcept;
    PalindromeStringIterator operator++(int) noexcept;

    PalindromeStringIterator& operator--() noexcept;
    PalindromeStringIterator operator--(int) noexcept;

    bool operator==(const PalindromeStringIterator& aOther) const noexcept;
    bool operator!=(const PalindromeStringIterator& aOther) const noexcept;

    PalindromeStringIterator begin() const noexcept;
    PalindromeStringIterator end() const noexcept;
    PalindromeStringIterator rbegin() const noexcept;
    PalindromeStringIterator rend() const noexcept;
};
