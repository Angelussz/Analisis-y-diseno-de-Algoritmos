/*
3] Utilizando los algoritmos de ordenación:
1. Realizar un análisis de la cantidad de comparaciones
2. Realizar un análisis de la cantidad de asignaciones
3. Realizar un análisis de la cantidad de asignación de memoria
6. Imprimir su valor:
x2 comparaciones
x8 asignaciones
x200 creacion de un objeto
x50 + n x 10 separa memoria para un arreglo o lista de tamanho 'n'
*/
//Angelo Aldo Perez Rodriguez

//Algoritmo Insert: https://www.geeksforgeeks.org/insertion-sort/
//Algoritmo guia contador milisegundos : https://gist.github.com/mcleary/b0bf4fa88830ff7c882d

#include <bits/stdc++.h> 

using namespace std;
////////


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
void swap(int *xp, int *yp,int& asignaciones,int& comparaciones)  
{  
    int temp = *xp;  
    asignaciones++;
    *xp = *yp;  
    asignaciones++;
    *yp = temp;  
    asignaciones++;
}  

void bubbleSort(int arr[], int n,int& asignaciones,int& comparaciones)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++,asignaciones++,comparaciones++){
        for (j = 0; j < n-i-1; j++,asignaciones++,comparaciones++){
            if (arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1],asignaciones,comparaciones);
                comparaciones++;
            }
       
        }
    }      
comparaciones++;//1 comparacion mas del if
      
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
    bubbleSort(arreglo, n,asignaciones,comparaciones);
    delete[] arreglo;
    arreglo = nullptr; 
    asignaciones++; 
    cout<<"asignaciones: "<<8*asignaciones<<","<<" comparaciones: "<<2*comparaciones<<","<<" asignaciones de memoria: "<<asignaciones_memoria*50+asignaciones_memoria*10;
    return 0;  
}  