#ifndef linearList_
#define linearList_
#include <iostream>

template <typename T>
class linearList {  // ADT 线性表
   public:
    virtual ~linearList(){};
    virtual bool empty() const = 0;
    virtual int size() const = 0;
    virtual T& get(int theIndex) const = 0;
    virtual int indexOf(const T& theElement, int theIndex) const = 0;
    virtual void erase(int theIndex) = 0;
    virtual void insert(int theIndex, const T& theElement) = 0;
    virtual void output(std::ostream& out) const = 0;
    virtual void clear() = 0;
    virtual void push_back(const T& theElement) = 0;
    virtual void pop_back() = 0;
};
#endif