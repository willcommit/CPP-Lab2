//
// Created by wille on 2019-02-15.
//

#include "IntArray.h"

IntArray::IntArray(): maxSize(0), size(0)
{
    arr = nullptr;
}

IntArray::IntArray (int pMaxSize): maxSize(pMaxSize), size(0)
{
    arr = new int[maxSize];
}

IntArray:: ~IntArray()
{
    delete [] arr;
    arr = NULL;
}

int IntArray::getValue(int idx) const
{
    return arr[idx];
}

bool IntArray::addValue(int value)
{
    bool valueAdded = false;
    if(size < maxSize)
    {
        arr[size] = value;
        size++;
        valueAdded = true;
    }
    return valueAdded;
}

IntArray::IntArray (const IntArray &a): maxSize(a.maxSize), size(a.size)
{
    arr = new int[a.maxSize];
    for (int i=0; i<a.size; i++)
        arr[i] = a.arr[i];
}

const IntArray &IntArray::operator=(const IntArray &a)
{
    if(this != &a)
    {
        delete []arr;
        arr
                = new int[a.maxSize];
        maxSize = a.maxSize;
        size
                = a.size;
        for (int i=0; i < a.size; i++)
            arr[i] = a.arr[i];
    }
    return *this;
}

void IntArray::swap (int &a, int &b)
{
    int tmp = a;
    a=b;
    b=tmp;
}

void IntArray::arrayFiller()
{
    std::default_random_engine generator(static_cast<unsigned>(time(0)));
    std::uniform_int_distribution<int> random(0,size-1);

    for (int i = 0; i < size; ++i) {
        arr[i] = random(generator);
    }
}

void IntArray::bubbleSort ()
{
    bool sorted = false;
    for (int i = 0; i < size-1 && !sorted; i++) {
        sorted = true;
        for (int j = 0; j < size-1; j++) {
            if(arr[j] > arr[i+1]){
                swap(arr[i],arr[i+1]);
                sorted = false;
            }
        }
    }
}


void IntArray::selectionSort()
{
    int smallIdx = 0;
    for (int i = 0; i < size-1; i++) {
        smallIdx = i;
        for (int j = i+1; j < size; j++)
            if(arr[j] < arr[smallIdx])
                smallIdx = j;

        if(smallIdx != i)
            swap(arr[i], arr[smallIdx]);
    }
}