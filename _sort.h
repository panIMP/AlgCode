#ifndef _SORT_H
#define _SORT_H


int* createArray();

void outputArray(int a[], int len);

void bubbleSort(int a[], int len);

void insertSort(int a[], int len);

void shellSort(int a[], int len);

int getMidian(int a[], int left, int right);

void quickSort (int a[], int left, int right);

void insertHeap(int a[]);

void buildHeap(int a[], int len);

void heapSort(int a[], int len);

#endif // _SORT_H
