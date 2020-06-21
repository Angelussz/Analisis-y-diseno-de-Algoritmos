//ANGELO ALDO PEREZ RODRIGUEZ
//Referencia : https://www.geeksforgeeks.org/quick-sort/
#include <iostream>
#include<stdlib.h>
#include <fstream>
using namespace std;
//int contador=0;
void Aleatorio(unsigned long& n,unsigned long* arreglo){
    for (int i =0;i<n;i++){
        int num = 1+(rand()%n);
        arreglo[i] = num;    
    }
      
}
void print(unsigned long& n, unsigned long* arreglo){
    for(int i=0;i<n;i++){
        cout<<arreglo[i]<<" ";
    }
    cout<<endl;
}

void swap(unsigned long* a, unsigned long* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  

int partition (unsigned long* arr, int low, int high,unsigned long& comp)  
{  
    int pivot = arr[high]; 
    int i = (low - 1); 
  
    for (int j = low; j <= high - 1; j++)  
    {  
        
        if (arr[j] < pivot)  
        {  
            i++; 
            swap(&arr[i], &arr[j]);  
            comp++;
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    comp++;
    return (i + 1);  
}  
void quickSort(unsigned long* arr, int low, int high,unsigned long& comp)  
{  
    if (low < high)  
    {  
        
        int pi = partition(arr, low, high,comp);  
        quickSort(arr, low, pi - 1,comp);  
        quickSort(arr, pi + 1, high,comp);  
    }  
}  

int main(){
    srand(time(nullptr));
    unsigned long n;
    unsigned long *arreglo = nullptr;
    
    ofstream datosquick;
    datosquick.open("lectura2.txt");
    cout<<"Que tamanio de arreglo quieres"<<endl;
    cin>>n;
    arreglo = new unsigned long[n];
    for (int i = 0; i < 200; i++)
    {
        //contador = 0;
        unsigned long comp= 0;
        Aleatorio(n,arreglo);
        quickSort(arreglo,0,n-1,comp);
        //print(n,arreglo);
        datosquick<<comp<<endl;
    }
    //quicksort(arreglo,0,n-1);
    datosquick.close();
    delete[] arreglo;
    
    return 0;
}