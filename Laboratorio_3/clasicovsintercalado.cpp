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

void merge_internet(int arr[], int l, int m, int r) 
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
void mergeSort_internet(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
  
        mergeSort_internet(arr, l, m); 
        mergeSort_internet(arr, m+1, r); 
  
        merge_internet(arr, l, m, r); 
    } 
}

//Intercalado
void intercalar(int arr[], int ini, int p, int fin)
{   
    int auxiliar[fin];
    
    for (int i = ini; i <= p; ++i)
    {
        auxiliar[i] = arr[i];
    }

    for (int j = p+1; j<=fin; ++j)
    {
        auxiliar[fin+p+1-j] = arr[j];
        
    }

   
    int i = ini;
    int j = fin;

    for (int k = ini; k <= fin; ++k)
    {
        if (auxiliar[i] <= auxiliar[j])
        {
            arr[k] = auxiliar[i];
            i = i+1;
        }

        else
        {
            arr[k] = auxiliar[j];
            j = j-1;
        }
    }

}

void mergeSort_intercalado(int arr[], int ini, int fin)
{
    int p;
    if (ini < fin)
    {
        
        p = (ini+fin)/2;
        
        mergeSort_intercalado(arr, ini, p);
        mergeSort_intercalado(arr, p+1, fin);
        intercalar(arr, ini, p, fin);
    }

    

    //else return;
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
    mergeSort_internet(arreglo,0,n-1);
    t2 = clock();
    t3 = clock();
    mergeSort_intercalado(arreglo2,0,n-1);
    t4 = clock();
    double time = (double(t2-t1)/CLOCKS_PER_SEC);
    double time2 = (double(t4-t3)/CLOCKS_PER_SEC);
    cout << "Tiempo real MergeClasico: " << time*1000 << endl;
    cout << "Tiempo real MergeIntercalado: " << time2*1000 << endl;
    /*print(n,arreglo);
    cout<<endl;
    print(n,arreglo2);*/    
    return 0;
    delete[] arreglo;
    delete[] arreglo2;
}