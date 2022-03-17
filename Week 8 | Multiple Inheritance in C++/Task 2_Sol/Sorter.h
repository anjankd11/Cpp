#ifndef SORTER_H
#define SORTER_H

#include "IComparable.h"

class Sorter
{
public:
	static void BubbleSort(IComparable** pItems, unsigned itemCount);
	//static void QuickSort(IComparable** pItems, unsigned itemCount);
	// Other sorting algorithms can be implemented here...

};

#endif /* SORTER_H */
