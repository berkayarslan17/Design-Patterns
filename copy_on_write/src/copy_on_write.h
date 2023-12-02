/**
 * @brief Example for understanding copy on write mechanism
 *
 * @file copy_on_write.h
 *
 * @copyright Copyright (C) Borda Technology. All rights reserved.
 */

#ifndef COPY_ON_WRITE_H
#define COPY_ON_WRITE_H

#include <memory>
#include <iostream>
template <class T>
class CowPtr
{
public:
    typedef std::shared_ptr<T> RefPtr;
    inline CowPtr() : mPtr(0) {}
    inline ~CowPtr() {}
    inline explicit CowPtr(T *other) : mPtr(other) { std::cout << "raw ptr ctor has called" << '\n'; }
    inline CowPtr(const CowPtr<T> &other) : mPtr(other.mPtr) { std::cout << "copy ctor has called" << '\n'; }
    inline T &operator*()
    {
        std::cout << "1" << '\n';
        Detach();
        return *mPtr.get();
    }
    inline const T &operator*() const
    {
        std::cout << "2" << '\n';
        return *mPtr.get();
    }
    inline T *operator->()
    {
        std::cout << "3" << '\n';
        Detach();
        return mPtr.get();
    }
    inline const T *operator->() const
    {
        std::cout << "4" << '\n';
        return mPtr.get();
    }
    inline operator T *()
    {
        std::cout << "5" << '\n';
        Detach();
        return mPtr.get();
    }
    inline operator const T *() const
    {
        std::cout << "6" << '\n';
        return mPtr.get();
    }
    inline T *data()
    {
        std::cout << "7" << '\n';
        Detach();
        return mPtr.get();
    }
    inline const T *data() const
    {
        std::cout << "8" << '\n';
        return mPtr.get();
    }
    inline const T *constData() const
    {
        std::cout << "9" << '\n';
        return mPtr.get();
    }
    inline bool operator==(const CowPtr<T> &other) const
    {
        std::cout << "10" << '\n';
        return mPtr.get() == other.mPtr.get();
    }
    inline bool operator!=(const CowPtr<T> &other) const
    {
        std::cout << "11" << '\n';
        return mPtr.get() != other.mPtr.get();
    }
    inline bool operator!() const
    {
        std::cout << "12" << '\n';
        return !mPtr.get();
    }
    inline CowPtr<T> &operator=(const CowPtr<T> &other)
    {
        std::cout << "13" << '\n';
        if (other.mPtr != mPtr)
        {
            mPtr = other.mPtr;
        }
        return *this;
    }
    inline CowPtr &operator=(T *other)
    {
        std::cout << "14" << '\n';
        mPtr = RefPtr(other);
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const CowPtr<T> &obj)
    {
        os << obj.mPtr.get();
        return os;
    }

private:
    inline void Detach()
    {
        T *temp = mPtr.get();
        if (temp && !mPtr.unique())
        {
            mPtr = RefPtr(new T(*temp));
        }
    }

    RefPtr mPtr;
};

#endif // COPY_ON_WRITE_H