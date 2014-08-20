int BinarySearch(int* a, int len, int key)
{
    int low, high, mid;

    low = 0;
    high = len - 1;

    while (low <= high) {
        mid = (low + high) / 2;

        if (a[mid] == key)
            return mid;

        else if (a[mid] > key)
        {
            high = mid - 1;
        }

        else if (a[mid] < key)
        {
            low = mid + 1;
        }
    }

    return 0;
}


int insertSearch(int* a, int len, int key)
{
    int low, high, pos;

    low = 0;
    high = len - 1;

    while (low <= high) {
        pos = low + (double)(high - low) * (double)(key - a[low]) / (double)(a[high] - a[low]);

        if (a[pos] == key)
            return pos;
        else if (a[pos] > key)
            high = pos - 1;
        else if (a[pos] < key)
            low = pos + 1;
    }

    return 0;
}
























































