#include "Person.h"
#include "Sorter.h"
#include "IComparable.h"
#include "ISerializable.h"

void Sorter::BubbleSort(IComparable** pItems, unsigned itemCount) //Bubble Sort works by repeatedly swapping the adjacent elements if they are in wrong order
{
    IComparable* p;  // temporary variable
    for (int i = 0; i < itemCount; i++){
        for (int j = 0; j < i; j++){  // i will hold the next element , so i will always be +1 than 
            if (*pItems[i] > *pItems[j]) {// creating descending order and using > operator overloading
            {\
                p = pItems[i];
                pItems[i] = pItems[j];
                pItems[j] = p;
            }
        }
    }
}

