#include "_sort.h"
#include "_std.h"
#include <stdio.h>

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






































