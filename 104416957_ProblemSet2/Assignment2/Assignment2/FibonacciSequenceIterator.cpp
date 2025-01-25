//COS30008 - 104416957 - Avery Flannery. Semester 1 2024
//Fibonacci Sequence Iterator

#include "FibonacciSequenceIterator.h"

// constructor 
FibonacciSequenceIterator::FibonacciSequenceIterator(const FibonacciSequenceGenerator& aSequenceObject, long long aStart) noexcept
    : fSequenceObject(aSequenceObject), fIndex(aStart) {}


// deference operator 
const long long& FibonacciSequenceIterator::operator*() const noexcept {
    return *fSequenceObject; // deferring the object
}

// prefix increment operator
FibonacciSequenceIterator& FibonacciSequenceIterator::operator++() noexcept {
    ++fIndex; // increments iterator position
    fSequenceObject.next(); //move to the next Fibonacci number 
    return *this;
}

// postfix increment operator 
FibonacciSequenceIterator FibonacciSequenceIterator::operator++(int) noexcept {
    FibonacciSequenceIterator temp = *this; // create a copy of the current iterator
    ++(*this); // increment the iterator position
    return temp; // return the copy
}

// == equals comparison operator
bool FibonacciSequenceIterator::operator==(const FibonacciSequenceIterator& aOther) const noexcept {
    // comparing the sequence objects' ID and iterator positions
    return (fSequenceObject.id() == aOther.fSequenceObject.id()) && (fIndex == aOther.fIndex);
}

// != does not equal comparison operator
bool FibonacciSequenceIterator::operator!=(const FibonacciSequenceIterator& aOther) const noexcept {
    return !(*this == aOther);
}

FibonacciSequenceIterator FibonacciSequenceIterator::begin() const noexcept {
    FibonacciSequenceIterator beginIterator = *this;
    beginIterator.fIndex = 1; // sets the iterator to 1 to start 
    beginIterator.fSequenceObject.reset();
    return beginIterator; // returns the iterator 
}

FibonacciSequenceIterator FibonacciSequenceIterator::end() const noexcept {
    FibonacciSequenceIterator endIterator = *this;
    endIterator.fIndex = 93; // sets the iterator position to 93 at the end 
    return endIterator; // returns the iterator 
}
