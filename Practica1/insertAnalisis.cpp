//2.- Copiar codigos en el lenguaje de su preferencia:

//Angelo Aldo Perez Rodriguez

//Algoritmo Insert: https://www.geeksforgeeks.org/insertion-sort/
//Algoritmo guia contador milisegundos : https://gist.github.com/mcleary/b0bf4fa88830ff7c882d

#include <bits/stdc++.h> 

using namespace std;
void insertionSort(int arr[], int n,int& comparaciones,int& asignaciones)  
{  
    int i, key, j;
    for (i = 1; i < n; i++,asignaciones++,comparaciones++) 
    {  
        key = arr[i];  
        asignaciones++;
        j = i - 1;  
        asignaciones++;
        while (j >= 0 && arr[j] > key,comparaciones++) 
        {  
            arr[j + 1] = arr[j];
            asignaciones++;  
            j = j - 1;  
            asignaciones++;
        }  
        arr[j + 1] = key;  
        asignaciones++;
    }  
}  

void Creacion(int n,int* arreglo,int& asignaciones,int& comparaciones){
    srand(time(nullptr));
    int num;
    for (int i =0;i<n;i++,asignaciones++,comparaciones++){
        num = 1+rand()%n;
        asignaciones++;
        arreglo[i] = num;
        asignaciones++;
    }
    cout<<endl;
}

int main()  
{ 
    int comparaciones=0;
    int asignaciones=0;
    int asignaciones_memoria=0;
    int * arreglo = nullptr;
    asignaciones++;
    int n;
    cout<<"Que tamanio de arreglo quieres"<<endl;
    cin>>n;
    asignaciones++;
    arreglo = new int[n];
    asignaciones_memoria++;
    Creacion(n,arreglo,asignaciones,comparaciones);
    insertionSort(arreglo,n,comparaciones,asignaciones);
    
    delete[] arreglo;
    arreglo = nullptr;
    asignaciones++;
    cout<<"asignaciones: "<<8*asignaciones<<","<<" comparaciones: "<<2*comparaciones<<","<<" asignaciones de memoria: "<<asignaciones_memoria*50+asignaciones_memoria*10;
    return 0;
}  