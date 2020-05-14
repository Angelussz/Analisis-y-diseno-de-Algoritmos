// ALumno: Angelo Aldo Perez Rodriguez
// ANALISIS Y DISEÑO DE ALGORITMOS
#include <iostream>
#include<stdlib.h>
using namespace std;

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
void insertionSort(int& n, int* arreglo2)  
{  
    int temp;
    for(long i = 1; i < n;i++)
    {
        temp = arreglo2[i];
        long j;
        for(j = i-1; j >= 0 && arreglo2[j] > temp;j--)
        {
            arreglo2[j+1] = arreglo2[j];
        }
        arreglo2[j+1] = temp;
    } 
}  

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
    insertionSort(n,arreglo);
    t2 = clock();
    t3 = clock();
    mergeSort(arreglo2,0,n-1);
    t4 = clock();
    double time = (double(t2-t1)/CLOCKS_PER_SEC);
    double time2 = (double(t4-t3)/CLOCKS_PER_SEC);
    cout << "Tiempo real Insert: " << time*1000 << endl;
    cout << "Tiempo real Merge: " << time2*1000 << endl;
    print(n,arreglo);
    cout<<endl;
    print(n,arreglo2);
    return 0;
    delete[] arreglo;
    delete[] arreglo2;
}