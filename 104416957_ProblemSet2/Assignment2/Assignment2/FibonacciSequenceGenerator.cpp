//COS30008 - 104416957 - Avery Flannery. Semester 1 2024
//Fibonacci Sequence Generator 


#include "FibonacciSequenceGenerator.h"

#include <cassert>

// constructor
FibonacciSequenceGenerator::FibonacciSequenceGenerator(const std::string& aID) noexcept :
    fID(aID), fPrevious(0), fCurrent(1) {}


// get sequence id
const std::string& FibonacciSequenceGenerator::id() const noexcept {
    return fID;
}

//deference operator to get current Fibonacci number
const long long& FibonacciSequenceGenerator::operator*() const noexcept {
    return fCurrent; // returning the current number 
}

// converting operator to bool
FibonacciSequenceGenerator::operator bool() const noexcept {
    return hasNext(); // check if there is a next Fibonacci number
}

// used to reset the sequence generator
void FibonacciSequenceGenerator::reset() noexcept {
    fPrevious = 0; // return previous
    fCurrent = 1; // return current
}

// used to check if there is a next Fibonacci number
bool FibonacciSequenceGenerator::hasNext() const noexcept {
    long long next = fPrevious + fCurrent; // calculates the next number 
    return next >= 0; // checks if the number is negative
}

// used to go on to the next Fibonacci number in the sequence
void FibonacciSequenceGenerator::next() noexcept {
    long long next = fPrevious + fCurrent; // calculates the number
    fPrevious = fCurrent; // updates the previous Fibonacci number
    fCurrent = next; // updates the current Fibonacci number
}   

