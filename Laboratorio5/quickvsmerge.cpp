//ANGELO ALDO PEREZ RODRIGUEZ
//Referencias:
//https://www.geeksforgeeks.org/c-qsort-vs-c-sort/
//http://www.cplusplus.com/reference/cstdlib/qsort/
#include <iostream>
#include<stdlib.h>
using namespace std;
//QuickSort por libreria
//Se necesita esta funcion compare para el qsort()
int compare(const void * a, const void * b) 
{ 
    return ( *(int*)a - *(int*)b ); 
} 

//MergeSort
void Aleatorio(int& n,int* arreglo,int* arreglo2){
    srand(time(nullptr));
    int num;
    for (int i =0;i<n;i++){
        num = 1+rand()%n;
        arreglo[i] = num;
        arreglo2[i] = num;
        
    }
    cout<<endl;   
}
//MergeSort 
void merge(int arr[], int l, int m, int r) 
{ 
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
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
  
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 
void print(int& n, int* arreglo){
    for(int i=0;i<n;i++){
        cout<<arreglo[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    int *arreglo = nullptr;
    int *arreglo2 = nullptr;
    unsigned t1,t2,t3,t4;
    cout<<"Que tamanio de arreglo quieres"<<endl;
    cin>>n;
    arreglo = new int[n];
    arreglo2 = new int[n];
    Aleatorio(n,arreglo,arreglo2);
    t1 = clock();
    mergeSort(arreglo,0,n-1);
    t2 = clock();
    t3 = clock();
    qsort(arreglo2,n,sizeof(int),compare);
    t4 = clock();
    double time = (double(t2-t1)/CLOCKS_PER_SEC);
    double time2 = (double(t4-t3)/CLOCKS_PER_SEC);
    cout << "Tiempo real Merge Intercalado: " << time*1000 << endl;
    cout << "Tiempo real QuickSort: " << time2*1000 << endl;
    //print(n,arreglo);
    cout<<endl;
    //print(n,arreglo2);
    return 0;
    delete[] arreglo;
    delete[] arreglo2;
}
