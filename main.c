#include <stdio.h>
#include <stdlib.h>
#define N 250000

int randomInt(int arr[]){
    int i;
    for(i=0; i<N; i++){
        srand(time(NULL)*(i+1));
        arr[i] = rand()%100+1;
    }
}

void printArray(int arr[]){
    int i;
    printf("\nElement Array : \n\t");
    for(i=0; i<N; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int arr[], int order){
    int i, j, key;

    for(i=1; i<N; i++){
        key = arr[i];
        j = i-1;
        if(order == 1){
            while( j >= 0 && arr[j] > key ){
                arr[j+1] = arr[j];
                j = j-1;
            }
        }else{
            while( j >= 0 && arr[j] < key ){
                arr[j+1] = arr[j];
                j = j-1;
            }
        }
        arr[j+1] = key;
    }
    printf("\nHasil insertion sort :");
    printArray(arr);
}

void selectionSort(int arr[], int order){
    int i, j, min, min_id, temp;
    for(i=0; i<N; i++){
        min = arr[i];
        min_id = i;
        j = i + 1;
        while(j < N){
            if(order == 1){
                if(arr[j] < min){
                    min = arr[j];
                    min_id = j;
                }
            }else{
                if(arr[j] > min){
                    min = arr[j];
                    min_id = j;
                }
            }
            j++;
        }
        temp = arr[i];
        arr[i] = arr[min_id];
        arr[min_id] = temp;
    }

    printf("\nHasil Selection Sort :");
    printArray(arr);
}

void bubbleSort(int arr[], int order){
    int i, j, temp;

    for(i=N; i>1; i--){
        for(j=0; j<i-1; j++){
            if(order == 1){
                if(arr[j] > arr[j+1]){
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }else{
                if(arr[j] < arr[j+1]){
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }

    printf("\nHasil Bubble Sort :");
    printArray(arr);
}

void bubbleSortFlag(int arr[], int order)
{
    int i, temp, comps, sorted = 0;
    comps = N - 1;

    while ( !sorted )
    {
        sorted=1;
        for(i=0; i < comps; i++){
            if (order == 1){
                if (arr[i] > arr[i+1]){
                    temp = arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1] = temp;
                    sorted = 0;
                }
            } else {
                if (arr[i] < arr[i+1]){
                    temp = arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1] = temp;
                    sorted = 0;
                }
            }
        }
        comps--;
    }
    printf("\nHasil bubble sort flag :");
    printArray(arr);
}

void shellSort(int arr[], int order){
    for (int gap = N/2; gap > 0; gap /= 2){
        for (int i = gap; i < N; i += 1){
            int temp = arr[i];
            int j;
            if(order == 1){
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap){
                    arr[j] = arr[j - gap];
                }
            }else{
                for (j = i; j >= gap && arr[j - gap] < temp; j -= gap){
                    arr[j] = arr[j - gap];
                }
            }

            arr[j] = temp;
        }
    }
    printf("\nHasil Shell Sort :");
    printArray(arr);
}

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high, int order){
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++){
        if(order == 1){
            if (arr[j] <= pivot){
                i++;
                swap(&arr[i], &arr[j]);
            }
        }else{
            if (arr[j] >= pivot){
                i++;
                swap(&arr[i], &arr[j]);
            }
        }

    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high, int order){
    if (low < high){
        int pi = partition(arr, low, high, order);

        quickSort(arr, low, pi - 1, order);
        quickSort(arr, pi + 1, high, order);
    }

}

void merge(int arr[], int l, int m, int r, int order){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2){
        if(order == 1){
            if (L[i] <= R[j]){
                arr[k] = L[i];
                i++;
            }else{
                arr[k] = R[j];
                j++;
            }
        }else{
            if (L[i] >= R[j]){
                arr[k] = L[i];
                i++;
            }else{
                arr[k] = R[j];
                j++;
            }
        }

        k++;
    }

    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }

}


void mergeSort(int arr[], int l, int r, int order){
    if (l < r){
        int m = l+(r-l)/2;

        mergeSort(arr, l, m, order);
        mergeSort(arr, m+1, r, order);

        merge(arr, l, m, r, order);
    }
}

void cleanStdin(){
    int c;
    while(c != '\n' && c != EOF){ c= getchar(); }
}

int main(){
    int i, pilih, awal[N], order;
    char lagi = 'y';
    printf("1. Insertion Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Bubble Sort\n");
    printf("4. Bubble Sort Flag\n");
    printf("5. Shell Sort\n");
    printf("6. Quick Sort\n");
    printf("7. Merge Sort\n");

    while(lagi == 'y' || lagi == 'Y'){
        printf("Masukan pilihan : ");
        scanf("%d", &pilih);
        printf("Pilih Order : \n1. Ascending\n2. Descending\n");
        printf("Masukan pilihan : ");
        scanf("%d", &order);
        randomInt(awal);
        printArray(awal);

        switch(pilih){
            case 1:
                insertionSort(awal, order);
                break;
            case 2:
                selectionSort(awal, order);
                break;
            case 3:
                bubbleSort(awal, order);
                break;
            case 4:
                bubbleSortFlag(awal, order);
                break;
            case 5:
                shellSort(awal, order);
                break;
            case 6:
                quickSort(awal, 0, N-1, order);
                printf("\nHasil Quick Sort :");
                printArray(awal);
                break;
            case 7:
                mergeSort(awal, 0, N-1, order);
                printf("\nHasil Merge Sort :");
                printArray(awal);
                break;
        }
        printf("Lagi ? ");
        cleanStdin();
        scanf("%c", &lagi);
    }

}
