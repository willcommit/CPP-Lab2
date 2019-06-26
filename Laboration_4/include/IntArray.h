//
// Created by wille on 2019-02-15.
//

#ifndef DT019G_INTARRAY_H
#define DT019G_INTARRAY_H

#include <iostream>
#include <ctime>
#include <random>

class IntArray
{
    private:
        int *arr;
        size_t maxSize;
        size_t size;
    public:
        //constructors
        IntArray();
        IntArray(int pNum);
        IntArray(const IntArray &a);
        ~IntArray();

        //get/set
        size_t getMaxSize() const { return maxSize; }
        size_t getSize() const { return size; }
        int getValue (int idx) const;
        bool addValue (int value);

        //overload = operator
        const IntArray &operator= (const IntArray &a);

        //swap function
        void swap (int &a, int &b);
        //arrayfiller
        void arrayFiller();
        //sorting algorithms
        void bubbleSort ();
        void selectionSort();
};


#endif //DT019G_INTARRAY_H
