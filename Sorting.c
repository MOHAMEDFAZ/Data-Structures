#include <stdio.h>

void SelectionSort(int a[], int n);
void InsertionSort(int a[], int n);
void QuickSort(int a[], int low, int high);
int Partition(int a[], int low, int high);
void Swap(int *a, int *b);
void MergeSort(int a[], int low, int high);
void Merge(int a[], int low, int mid, int high);

int main() {
    int ch;
    do {
        printf("\n------------[SORTING]------------");
        printf("\n1. SELECTION_SORT\n2. INSERTION_SORT\n3. QUICK_SORT\n4. MERGE_SORT\n5. EXIT");
        printf("\nENTER YOUR CHOICE [1-5]: ");
        scanf("%d", &ch);
        
        if (ch >= 1 && ch <= 4) {
            int n;
            printf("ENTER THE ARRAY SIZE: ");
            scanf("%d", &n);
            int a[n];
            printf("ENTER ARRAY ELEMENTS:\n");
            
            for (int i = 0; i < n; i++) {
                printf("ELEMENT %d -> ", i + 1);
                scanf("%d", &a[i]);
            }

            printf("\nARRAY BEFORE SORTING: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", a[i]);
            }

            switch (ch) {
                case 1:
                    SelectionSort(a, n);
                    break;
                case 2:
                    InsertionSort(a, n);
                    break;
                case 3:
                    QuickSort(a, 0, n - 1);
                    break;
                case 4:
                    MergeSort(a, 0, n - 1);
                    break;
            }

            printf("\nARRAY AFTER SORTING: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", a[i]);
            }
            printf("\n");
        } else if (ch != 5) {
            printf("ENTER A VALID INPUT!\n");
        }
    } while (ch != 5);

    return 0;
}

void SelectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        Swap(&a[min], &a[i]);
    }
}

void InsertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int a[], int low, int high) {
    int pivot = a[low];
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= high && a[i] <= pivot) {
            i++;
        }
        while (j > low && a[j] > pivot) {
            j--;
        }
        if (i < j) {
            Swap(&a[i], &a[j]);
        }
    }
    Swap(&a[low], &a[j]);
    return j;
}

void QuickSort(int a[], int low, int high) {
    if (low < high) {
        int p = Partition(a, low, high);
        QuickSort(a, low, p - 1);
        QuickSort(a, p + 1, high);
    }
}

void MergeSort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        MergeSort(a, low, mid);
        MergeSort(a, mid + 1, high);
        Merge(a, low, mid, high);
    }
}

void Merge(int a[], int low, int mid, int high) {
    int temp[20];
    int i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = a[i++];
    }

    while (j <= high) {
        temp[k++] = a[j++];
    }

    for (i = low; i <= high; i++) {
        a[i] = temp[i];
    }
}
