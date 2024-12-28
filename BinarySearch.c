#include <stdio.h>
int main()
{
    int n; // size of array
    printf("ENTER THE ARRAY SIZE: ");
    scanf("%d", &n);
    int a[n];
    printf("ENTER ARRAY ELEMENTS: \n");

    for (int i = 0; i < n; i++)
    {
        printf("INSERTED -> ");
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("\nARRAY ELEMENT AT INDEX [%d] IS %d", i, a[i]);
    }
    int temp;
    // sorting the array
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("\n\nTHE SORTED ARRAY IS: ");
    for (int i = 0; i < n; i++)
    {
        printf("\nARRAY ELEMENT AT INDEX [%d] IS %d", i, a[i]);
    }
    int e;
    printf("\nENTER THE ELEMENT TO SEARCH FOR: ");
    scanf("%d", &e);
    int low = 0, high = n - 1, flag = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] == e)
        {
            printf("ELEMENT %d FOUND AT INDEX %d", e, mid);
            flag = 1;
            break;
        }
        if (e < a[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    if (flag == 0)
    {
        printf("ELEMENT %d NOT FOUND!", e);
    }
    return 0;
}
