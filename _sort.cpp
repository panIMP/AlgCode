#include "_sort.h"
#include "_std.h"
#include <stdio.h>
#include <stdlib.h>


void swap(int* a, int* b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}


int* createArray() {
    static int a[N] = {0,3,4,6,1,5,9,7,8,2};
    return a;
}


void outputArray(int a[], int len) {
    int i;
    for (i = 0; i < len; ++i) {
        printf ("%d ", a[i]);
    }
}


void bubbleSort2(int a[], int len)
{
    int i,j;

    for (i = 0; i < len - 1; ++i)
    {
        for (j = 0; j < len - i - 1; ++j)
        {
            if (a[j] > a[j + 1])
                swap(&a[j], &a[j + 1]);
        }
    }

}


void bubbleSort3(int a[], int len)
{
    int i,j;
    bool undone = true;

    for (i = 0; i < len - 1 && undone; ++i)
    {
        undone = false;

        for (j = 0; j < len-i-1; ++j)
        {
            if (a[j] > a[j+1])
            {
                swap(&a[j], &a[j + 1]);
                undone = true;
            }
        }
    }
}


void bubbSort(int a[], int len) {
    int tmp, i, j;

    for (i = 0; i < len-1; ++i) {
        for (j = 0; j < len-1-i; ++j) {
            if (a[j] > a[j+1]) {
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
}


void selectSort(int a[], int len)
{
    int i,j,min;

    for (i = 0; i < len-1; ++i)
    {
        min = i;

        for (j = i + 1; j < len; ++j)
        {
            if (a[min] > a[j])
            {
                min = j;
            }
        }

        if (min != i)
            swap(&a[i], &a[min]);
    }
}


void insertSort2(int a[], int len)
{
    int i,j,tmp;

    for (i = 1; i < len; ++i)
    {
        tmp = a[i];

        for (j = i; j > 0 && tmp < a[j-1]; --j)
        {
            a[j] = a[j-1];
        }

        a[j] = tmp;
    }
}


void insertSort(int a[], int len) {
    int tmp, i, j;

    for (i = 1; i < len; ++i) {
        tmp = a[i];

        for (j = i; j > 0 && tmp < a[j-1]; --j) {
            a[j] = a[j-1];
        }
        a[j] = tmp;
    }
}


void shellSort2(int a[], int len)
{
    int i,j,tmp,step;

    for (step = len / 10; step > 0; step /= 10)
    {
        for (i = step; i < len; ++i)
        {
            tmp = a[i];

            for (j = i; j >= step && a[j - step] > tmp; j -= step)
            {
                a[j] = a[j - step];
            }

            a[j] = tmp;
        }
    }
}


void shellSort(int a[], int len) {
    int step, tmp, i, j;

    for (step = len / 2; step > 0; step /= 2) {
        for (i = step; i < len; ++i) {
            tmp = a[i];

            for (j = i; j >= step && tmp < a[j-step]; j -= step) {
                a[j] = a[j - step];
            }
            a[j] = tmp;
        }
    }
}


int partition2(int a[], int low, int high)
{
    int val = a[low];

    while (low < high) {
        while (low < high && a[high] >= val)
            high --;
        swap(&a[high], &a[low]);

        while(low < high && a[low] <= val)
            low++;
        swap(&a[low], &a[high]);
    }

    return low;
}


int qsort2(int a[], int low, int high)
{
    int pivot;

    if (low < high)
    {
        pivot = partition2(a, low, high);

        qsort2(a, low, pivot - 1);
        qsort2(a, pivot+1, high);
    }
}



int getMidian(int a[], int left, int right) {
    int center = (left + right) / 2;

    if (a[center] < a[left]) {
        swap(&a[center], &a[left]);
    }

    if (a[right] < a[left]) {
        swap(&a[right], &a[left]);
    }

    if (a[right] < a[center]) {
        swap(&a[right], &a[center]);
    }

    swap(&a[center], &a[right]);
    return a[right];
}


void quickSort (int a[], int left, int right) {
    int pivot = getMidian(a, left, right);
    int i = left;
    int j = right - 1;

    if (j <= i) {
        swap (&a[i], &a[right]);
        return;
    }

    for(;;) {
        while (a[++i] < pivot) {}
        while (pivot < a[--j]) {}

        if (i < j) {
            swap (&a[i], &a[j]);
        }
        else {
            break;
        }
    }

    swap (&a[i], &a[right]);

    if (left < right) {
        quickSort(a, left, i-1);
    }
    if (left < right) {
        quickSort(a, i+1, right);
    }
}


void insertHeap(int a[]) {
    static int cSize = 1;
    int i = cSize;
    int insertValue = a[cSize];

    for (; i > 0 && a[(i-1)/2] > insertValue; i = (i-1)/2) {
        a[i] = a[(i-1) / 2];
    }

    a[i] = insertValue;
    cSize ++;
}


void buildHeap(int a[], int len) {
    int i = 0;
    for (; i < len - 1; ++i) {
        insertHeap(a);
    }
}


void deleteHeap(int a[], int len, int num) {
    int i = 0;
    int tmp = a[num];
    int child;

    for (i = 0; i < len; i = child) {
        child = 2*i + 1;

        if (a[child] < tmp) {
            a[i] = a[child];
            child ++;
        }
        if (a[child] < a[i]) {
            a[i] = a[child];
        }
        else
            break;
    }

    a[i] = tmp;
}

void heapSort(int a[], int len) {
    int i = 0;
    for (; i < len-1; ++i) {
        deleteHeap(a, len, len-i-1);
    }
}



void heapAdjust(int a[], int pos, int len)
{
    int i, tmp;

    tmp = a[pos];

    for (i = pos * 2 + 1; i < len; i = i * 2 + 1)
    {
        if (i < len-1  && a[i] < a[i + 1])
            i++;

        if (tmp > a[i])
            break;

        a[pos] = a[i];
        pos = i;
    }

    a[pos] = tmp;
}


void heapSort2(int a[], int len)
{
    int i;

    for (i = len / 2 - 1; i >= 0; --i)
    {
        heapAdjust(a, i, len);
    }

    for (i = len - 1; i >= 0; --i)
    {
        swap(&a[i], &a[0]);
        heapAdjust(a, 0, i);
    }

}


void merge(int a[], int b[], int aStart, int aMid, int aEnd)
{
    int i,j,k;

    i = aStart;
    j = aMid + 1;
    k = 0;
    while(i <= aMid && j <= aEnd)
    {
        if (a[j] > a[i])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }

    while(i <= aMid)
        b[k++] = a[i++];

    while(j <= aEnd)
        b[k++] = a[j++];

    for (i = 0; i < k; ++i)
        a[i + aStart] = b[i];
}


void mSort(int a[], int b[], int aStart, int aEnd)
{
    if (aStart < aEnd)
    {
        int mid = (aStart + aEnd) / 2;

        mSort(a, b, aStart, mid);
        mSort(a, b, mid + 1, aEnd);
        merge(a, b, aStart, mid, aEnd);
    }
}



void mergeSort(int a[], int len)
{
    if (a == NULL || len <= 1)
        return;

    else
    {
        int* b = (int*)malloc(sizeof(int) * len);
        if (b == NULL)
            return;
        mSort(a, b, 0, len-1);
        free(b);
    }
}


int func(char* str)
{
    if (str == NULL)
        return -1;

    if (*str == '\0')
        return -2;

    return 0;
}


int main()
{
    func(NULL);

    return 0;
}




































