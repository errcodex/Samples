#ifndef __MySort_h__
#define __MySort_h__
#include "MySort.h"
class MySort{
private:
	typedef unsigned int uint;
	static void swap(int arr[], const uint a, const uint b);
public:
	MySort();
	// ð������
	static bool bubbleSort(int arr[],const uint len);

	// ��������
	static bool insertionSort(int arr[], const uint len);

	// �鲢����
	static bool mergeSort(int arr[], const uint len);

	// ��������
	static bool quickSort(int arr[], const uint len);

	// ��������
	static bool radixSort(int arr[], const uint len);

	// ѡ������
	static bool selectionSort(int arr[], const uint len);

	// ϣ������
	static bool shellSort(int arr[], const uint len);

};
#endif