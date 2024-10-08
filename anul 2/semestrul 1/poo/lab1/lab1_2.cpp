#include <stdio.h>
#include<algorithm>
#include <iostream>

using namespace std;

class Sorter{
private:void QuickSort(int v[], int st, int dr) {
  if (st < dr) {
    int m = (st + dr) / 2;
    int aux = v[st];
    v[st] = v[m];
    v[m] = aux;
    int i = st, j = dr, d = 0;
    while (i < j) {
      if (v[i] < v[j]) {
        aux = v[i];
        v[i] = v[j];
        v[j] = aux;
        d = 1 - d;
      }
      i += d;
      j -= 1 - d;
    }
    QuickSort(v, st, i - 1);
    QuickSort(v, i + 1, dr);
  }
}
public:
    void sortingAlg(int arr[], int n)
    {
       QuickSort(arr,0,n-1);
    }
    
    void printArray(int arr[], int n)
    {
        int i;
        for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
        printf("\n");
    }

};

  int main()
{
    int arr[5] = { 40, 8, 11, 2, 99 };
    int n = 5;
    Sorter sorting;
    sorting.sortingAlg(arr, n);
    sorting.printArray(arr, n);
  
    return 0;
}