#include <stdio.h>
#include<stdbool.h>  
#include<time.h>
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
// selection sort
int selectionSort(int *arr, int size)
{
    int count = 0;
    printf("\nSelection Sort Applied\n");
    for (int i = 0; i < size; i++)
    {
        count++;
        for (int j = i + 1; j < size; j++)
        {
            count++;
            if (arr[i] > arr[j])
            {
                count++;
                swap(&arr[i], &arr[j]);
                count++;
            }
        }
        count++;
    }
    count++;
    return count;
}

// quick sort
int calcPivot(int *arr, int start, int end)
{
    int pivot = arr[end];
    int i = start - 1;
    for (int j = start; j < (end - 1); j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[j], &arr[i]);
        }
    }
    swap(&arr[i + 1], &arr[end]);
    return (i + 1);
}
int quickSort(int *arr, int start, int end)
{
    if (start < end)
    {
        int pivot = calcPivot(arr, start, end);
        quickSort(arr, start, pivot - 1);
        quickSort(arr, pivot + 1, end);
    }
}
// bubble sort
int bubbleSort(int *arr, int n)
{
    int count=0;
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++)
    {
        count++;
        swapped = false;
        count++;
        for (j = 0; j < n - i - 1; j++)
        {
            count++;
            if (arr[j] > arr[j + 1])
            {
                count++;
                swap(&arr[j], &arr[j + 1]);
                count++;
                swapped = true;
            }
        }
        count++;
        count++;
        if (swapped == false)
            break;
    }
    count++;
    return count;
}
// insertion sort
int insertionSort(int *arr, int size)
{
    int count = 0;
    printf("\nInsertion Sort Applied\n");
    int i, element, j;
    for (int i = 1; i < size; i++)
    {
        count++;
        element = arr[i];
        count++;
        j = i - 1;
        count++;
        while (j >= 0 && arr[j] > element)
        {
            count++;
            arr[j + 1] = arr[j];
            count++;
            j--;
        }
        count++;
        arr[j + 1] = element;
        count++;
    }
    count++;
    return count;
}
void display(int *arr, int size)
{
    printf("\nArray: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}
void main()
{
    time_t t;  
    time(&t);

    int array[10] = {1,2,3,4,5,7,6,8,9,0};
    display(array, 10);
    // printf("\n\n\n\n\nTime Before: %s",ctime(&t));
    int count2 = selectionSort(array, 10);
    printf("\nCount: %d\n", count2);
    // printf("\nTime After: %s",ctime(&t));

    int array1[10] = {1,2,3,4,5,7,6,8,9,0};
    printf("\n\n\n\n\nQuick Sort\n");
    // printf("Time Before: %s",ctime(&t));
    int count1 = quickSort(array1, 0, 9);
    // printf("\nTime After: %s",ctime(&t));
    printf("\nCount: %d\n", count1);

    int array2[10] = {1,2,3,4,5,7,6,8,9,0};
    printf("\n\n\n\n\n\n");
    // printf("\n\n\n\n\n\n\n\nTime Before: %s",ctime(&t));
    int count = insertionSort(array2, 10);
    // printf("\nTime After: %s",ctime(&t));
    printf("\nCount: %d\n", count);
    // display(array2, 10);

    int array3[10] = {1,2,3,4,5,7,6,8,9,0};
    printf("\n\n\n\n\n\n\nBubble Sort:\n");
    // printf("Time Before: %s",ctime(&t));
    int count3 = bubbleSort(array3, 10);
    // printf("\nTime After: %s",ctime(&t));
    printf("\nCount: %d\n", count3);
    display(array3, 10);
}