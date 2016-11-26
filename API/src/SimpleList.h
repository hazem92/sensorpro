// SimpleList.h

#ifndef _SIMPLELIST_h
#define _SIMPLELIST_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#ifndef NULL
#define NULL 0
#endif

template<typename T>
class SimpleList
{
public:
    typedef T* iterator;

    SimpleList()
    {
        _internalArray = NULL;
        _endPosition = 0;
        _allocBlocks = 0;
        _preAllocBlocks = 0;
    }

    ~SimpleList()
    {
        delete[] _internalArray;
        _internalArray = NULL;
        _endPosition = 0;
        _allocBlocks = 0;
        _preAllocBlocks = 0;
    }

    SimpleList(const SimpleList& from)
    {
        _endPosition = from._endPosition;
        _allocBlocks = from._allocBlocks;
        _preAllocBlocks = from._preAllocBlocks;

        _internalArray = new T[_allocBlocks];

        for (int i = 0; i < _endPosition; ++i)
            _internalArray[i] = from._internalArray[i];
    }

    SimpleList& operator=(const SimpleList& from)
    {
        if (this != &from)
        {
            _endPosition = from._endPosition;
            _allocBlocks = from._allocBlocks;
            _preAllocBlocks = from._preAllocBlocks;

            delete[] _internalArray;
            _internalArray = NULL;

            if (_allocBlocks)
            {
                _internalArray = new T[_allocBlocks];

                for (int i = 0; i < _endPosition; ++i)
                    _internalArray[i] = from._internalArray[i];
            }
        }

        return *this;
    }

    void push_back(T item)
    {
        if (_endPosition == _allocBlocks)
            AllocOneBlock(false);

        _internalArray[_endPosition] = item;
        ++_endPosition;
    }

    void push_front(T item)
    {
        if (_endPosition == _allocBlocks)
            AllocOneBlock(true);
        else
        {
            for (int i = _endPosition; i > 0; --i)
                _internalArray[i] = _internalArray[i - 1];
        }

        _internalArray[0] = item;
        ++_endPosition;
    }

    void pop_back()
    {
        if (_endPosition == 0)
            return;

        --_endPosition;

        if (_allocBlocks > _preAllocBlocks)
            DeAllocOneBlock(false);
    }

    void pop_front()
    {
        if (_endPosition == 0)
            return;

        --_endPosition;

        if (_allocBlocks > _preAllocBlocks)
            DeAllocOneBlock(true);
        else
        {
            for (int i = 0; i < _endPosition; ++i)
                _internalArray[i] = _internalArray[i + 1];
        }
    }

    iterator erase(iterator position)
    {
        int offSet = int(position - _internalArray);

        if (offSet == _endPosition - 1) // Last item.
        {
            pop_back();
            return end();
        }

        --_endPosition;

        if (_allocBlocks > _preAllocBlocks)
        {
            --_allocBlocks;
            T* newArray = new T[_allocBlocks];

            for (int i = 0; i < _endPosition; ++i)
            {
                if (i >= offSet)
                    newArray[i] = _internalArray[i + 1];
                else
                    newArray[i] = _internalArray[i];
            }

            delete[] _internalArray;
            _internalArray = newArray;
        }
        else
        {
            for (int i = offSet; i < _endPosition; ++i)
                _internalArray[i] = _internalArray[i + 1];
        }

        return _internalArray + offSet;
    }

    void reserve(int size)
    {
        if (size == 0 || size < _allocBlocks)
            return;

        _allocBlocks = size;
        _preAllocBlocks = size;

        T* newArray = new T[_allocBlocks];

        for (int i = 0; i < _endPosition; ++i)
            newArray[i] = _internalArray[i];

        delete[] _internalArray;
        _internalArray = newArray;
    }

    void clear()
    {
        if (_allocBlocks > _preAllocBlocks)
        {
            _allocBlocks = _preAllocBlocks;

            T* newArray = NULL;

            if (_allocBlocks > 0)
                newArray = new T[_allocBlocks];

            delete[] _internalArray;
            _internalArray = newArray;
        }

        _endPosition = 0;
    }

    void shrink_to_fit()
    {
        _preAllocBlocks = _endPosition;
        _allocBlocks = _endPosition;

        T* newArray = NULL;

        if (_allocBlocks > 0)
            newArray = new T[_allocBlocks];

        for (int i = 0; i < _endPosition; ++i)
            newArray[i] = _internalArray[i];

        delete[] _internalArray;
        _internalArray = newArray;
    }

    inline iterator begin() { return _internalArray; }
    inline iterator end() { return _internalArray + _endPosition; }

    inline bool empty() { return (_endPosition == 0); }
    inline unsigned int size() { return _endPosition; }
    inline unsigned int capacity() { return _allocBlocks; }

private:

    void AllocOneBlock(bool shiftItems)
    {
        ++_allocBlocks;
        T* newArray = new T[_allocBlocks];

        for (int i = 0; i < _endPosition; ++i)
            newArray[shiftItems ? (i + 1) : i] = _internalArray[i];

        delete[] _internalArray;
        _internalArray = newArray;
    }

    void DeAllocOneBlock(bool shiftItems)
    {
        --_allocBlocks;

        if (_allocBlocks == 0)
        {
            delete[] _internalArray;
            _internalArray = NULL;
            return;
        }

        T* newArray = new T[_allocBlocks];

        for (int i = 0; i < _endPosition; ++i)
            newArray[i] = _internalArray[shiftItems ? (i + 1) : i];

        delete[] _internalArray;
        _internalArray = newArray;
    }

private:

    T* _internalArray;
    int _endPosition;
    int _allocBlocks;
    int _preAllocBlocks;
};

#endif








/*
 // SimpleList.h

#ifndef _SIMPLELIST_h
#define _SIMPLELIST_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#ifndef NULL
#define NULL 0
#endif

template<typename T>
class SimpleList
{
public:

    SimpleList()
    {
        _list = NULL;
        _size = 0;
        _preAlloc = 0;
    }

    ~SimpleList()
    {
        delete[] _list;
        _list = NULL;
        _size = 0;
        _preAlloc = 0;
    }

    void push_back(T obj)
    {
        ++_size;

        bool alloc = (_preAlloc < _size);

        T* newBuffer = alloc ? new T[_size] : _list;

        if (alloc)
        {
            for (unsigned int i = 0; i < _size - 1; ++i)
                newBuffer[i] = _list[i];
        }

        newBuffer[_size - 1] = obj;

        if (alloc)
        {
            delete[] _list;
            _list = newBuffer;
        }
    }

    void push_front(T obj)
    {
        ++_size;

        bool alloc = (_preAlloc < _size);

        T* newBuffer = alloc ? new T[_size] : _list;

        for (unsigned int i = _size - 1; i > 0; --i)
            newBuffer[i] = _list[i - 1];
        newBuffer[0] = obj;


        if (alloc)
        {
            delete[] _list;
            _list = newBuffer;
        }
    }

    void pop_back()
    {
        if (empty())
            return;

        --_size;
        if (empty())
        {
            if (!_preAlloc)
                delete[] _list;
            return;
        }

        bool alloc = (!_preAlloc || _preAlloc < _size + 1);

        T* newBuffer = alloc ? new T[_size] : _list;

        if (alloc)
        {
            for (unsigned int i = 0; i < _size; ++i)
                newBuffer[i] = _list[i];

            delete[] _list;
            _list = newBuffer;
        }
    }

    void pop_front()
    {
        if (empty())
            return;

        --_size;
        if (empty())
        {
            if (!_preAlloc)
                delete[] _list;
            return;
        }

        bool alloc = (!_preAlloc || _preAlloc < _size + 1);

        T* newBuffer = alloc ? new T[_size] : _list;

        for (unsigned int i = 0; i < _size; ++i)
            newBuffer[i] = _list[i + 1];

        if (alloc)
        {
            delete[] _list;
            _list = newBuffer;
        }
    }

    void reserve(unsigned int size)
    {
        if (size <= _size)
            return;

        _preAlloc = size;

        T* newBuffer = new T[_preAlloc];

        for (unsigned int i = 0; i < _size; ++i)
            newBuffer[i] = _list[i];

        delete[] _list;
        _list = newBuffer;
    }

    typedef T* iterator;

    iterator erase(iterator &itr)
    {
        if (empty())
            return NULL;

        --_size;
        if (empty())
        {
            if (!_preAlloc)
                delete[] _list;
            return NULL;
        }

        bool alloc = (!_preAlloc || _preAlloc < _size + 1);

        T* newBuffer = alloc ? new T[_size] : _list;

        bool sum = false;
        unsigned int pos = 0;
        for (unsigned int i = 0; i < _size; ++i)
        {
            if (_list + i == itr)
            {
                sum = true;
                pos = i;
            }

            if (sum)
                newBuffer[i] = _list[i + 1];
            else
                newBuffer[i] = _list[i];
        }

        if (alloc)
        {
            delete[] _list;
            _list = newBuffer;
        }

        itr = _list + pos;

        return itr;
    }

    inline iterator begin() { return (empty() ? NULL : _list); }
    inline iterator end() { return (empty() ? NULL : _list + _size); }

    void clear()
    {
        if (_list && !_preAlloc)
        {
            delete[] _list;
            _list = NULL;
        }
        _size = 0;
    }

    inline bool empty() { return !_size; }
    inline unsigned int size() { return _size; }
    inline unsigned int capacity() { return (_size > _preAlloc ? _size : _preAlloc); }
private:
    T* _list;
    unsigned int _size;
    unsigned int _preAlloc;
};

#endif
*/
