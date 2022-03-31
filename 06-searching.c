#include <stdio.h>
#include <stdlib.h>
// quick sort
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
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



int binarySearch(int arr[], int start, int end, int value)
{
    if (end > start)
    {
        int mid = (start + end - 1) / 2;

        if (arr[mid] == value)
        {
            return mid;
        }
        else if (arr[mid] > value)
        {
            return binarySearch(arr, start, mid - 1, value);
        }
        else
        {
            return binarySearch(arr, mid + 1, end, value);
        }
    }
    return -1;
}
void main()
{
    int seed;
    printf("\nPlease enter seed-");
    scanf("%d",&seed);
    srand(seed);
    // int choice = 0;
    // switch (choice)
    // {
    // case 1:
        float perc, avg;
        int i = 0, j = 0, totalSearch = 0, found = 0, x[100], y[100];
        printf("\nGenerating Array...\nArray:-");
        for (i = 0; i < 100; i++)
        {
            x[i] = (rand() % 200 + 1);
            printf("%d\t", x[i]);
        }
        quickSort(x,0,99);
        printf("\nSearching...");
        for (i = 0; i < 100; i++)
        {
            totalSearch++;
            //		if(i==0){
            y[i] = 0;
            //		}else{
            //			y[i]=y[i-1];
            //		}
            int val = (rand() % 200 + 1);
            printf("\n%d Searching Number:	%d	", i, val);
            if (seed>50)
            {
            
                int index=binarySearch(x,0,99,val);
                if(index>-1){
                    printf("Found at %d position...", index);
                    found++;
                }
            }
            else
            {

                for (j = 0; j < 100; j++)
                {
                    y[i]++;
                    if (val == x[j])
                    {
                        found++;
                        printf("Found after %d searches ...", y[i]);
                        break;
                    }
                }
            }
        }
        int sum = 0;
        for (i = 0; i < 100; i++)
        {
            sum += y[i];
        }
        perc = (float)found / totalSearch * 100;
        avg = (float)sum / 100;
        printf("\nThe number of searches completed-%d\nThe number of successful searches-%d\nThe percentage of successful searches-%lf\nThe average number of tests per search-%lf", totalSearch, found, perc, avg);
        // break;

    // case 2:
    //     // float perc, avg;
    //     // int i = 0, j = 0, totalSearch = 0, found = 0, x[100], y[100];
    //     // printf("\nGenerating Array...\nArray:-");
    //     // for (i = 0; i < 100; i++)
    //     // {
    //     //     x[i] = (rand() % 200 + 1);
    //     //     printf("%d\t", x[i]);
    //     // }

    // default:
    //     break;
    // }
}