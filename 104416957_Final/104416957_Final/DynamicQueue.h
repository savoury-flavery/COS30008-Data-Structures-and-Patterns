// COS30008, Final Exam, 2024

#pragma once

#include <optional>
#include <cassert>

#include <iostream>

template<typename T>
class DynamicQueue
{
private:
    T* fElements;
    size_t fFirstIndex;
    size_t fLastIndex;
    size_t fCurrentSize;

    void resize(size_t aNewSize)
    {
        T* newElements = new T[aNewSize];
        size_t newSize = fLastIndex - fFirstIndex;

        for (size_t i = 0; i < newSize; ++i)
        {
            newElements[i] = std::move(fElements[fFirstIndex + i]);
        }

        delete[] fElements;

        fElements = newElements;
        fFirstIndex = 0;
        fLastIndex = newSize;
        fCurrentSize = aNewSize;
    }

    void ensure_capacity()
    {
        if (fLastIndex == fCurrentSize)
        {
            resize(fCurrentSize * 2 + 1);
        }
    }

    void adjust_capacity()
    {
        if (fLastIndex - fFirstIndex <= fCurrentSize / 4 && fCurrentSize > 1)
        {
            resize(fCurrentSize / 2);
        }
    }

public:

    DynamicQueue() : fElements(nullptr), fFirstIndex(0), fLastIndex(0), fCurrentSize(0)
    {
    }

    ~DynamicQueue()
    {
        delete[] fElements;// COS30008, Final Exam, 2024

#pragma once

#include <optional>
#include <cassert>

#include <iostream>

template<typename T>
class DynamicQueue
{
private:
    T* fElements;
    size_t fFirstIndex;
    size_t fLastIndex;
    size_t fCurrentSize;

    void resize(size_t aNewSize)
    {
        T* newElements = new T[aNewSize];
        size_t newSize = fLastIndex - fFirstIndex;

        for (size_t i = 0; i < newSize; ++i)
        {
            newElements[i] = std::move(fElements[fFirstIndex + i]);
        }

        delete[] fElements;

        fElements = newElements;
        fFirstIndex = 0;
        fLastIndex = newSize;
        fCurrentSize = aNewSize;
    }

    void ensure_capacity()
    {
        if (fLastIndex == fCurrentSize)
        {
            resize(fCurrentSize * 2 + 1);
        }
    }

    void adjust_capacity()
    {
        if (fLastIndex - fFirstIndex <= fCurrentSize / 4 && fCurrentSize > 1)
        {
            resize(fCurrentSize / 2);
        }
    }

public:

    DynamicQueue() : fElements(nullptr), fFirstIndex(0), fLastIndex(0), fCurrentSize(0)
    {
    }

    ~DynamicQueue()
    {
        delete[] fElements;
    }

    DynamicQueue(const DynamicQueue&) = delete;
    DynamicQueue& operator=(const DynamicQueue&) = delete;

    std::optional<T> top() const noexcept
    {
        if (fFirstIndex == fLastIndex)
        {
            return std::nullopt;
        }

        return fElements[fFirstIndex];
    }

    void enqueue(const T& aValue)
    {
        ensure_capacity();
        fElements[fLastIndex++] = aValue;
    }

    void dequeue()
    {
        assert(fFirstIndex != fLastIndex && "Queue is empty");
        fFirstIndex++;
        adjust_capacity();
    }
};
    }

    DynamicQueue(const DynamicQueue&) = delete;
    DynamicQueue& operator=(const DynamicQueue&) = delete;

    std::optional<T> top() const noexcept
    {
        if (fFirstIndex == fLastIndex)
        {
            return std::nullopt;
        }

        return fElements[fFirstIndex];
    }

    void enqueue(const T& aValue)
    {
        ensure_capacity();
        fElements[fLastIndex++] = aValue;
    }

    void dequeue()
    {
        assert(fFirstIndex != fLastIndex && "Queue is empty");
        fFirstIndex++;
        adjust_capacity();
    }
};