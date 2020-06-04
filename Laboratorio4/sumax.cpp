//ANGELO PEREZ RODRIGUEZ
//Referencias: https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
//https://www.youtube.com/watch?v=ohHWQf1HDfU
#include<cmath>
#include<iostream>
#include<climits>
using namespace std;
int max2(int n1, int n2, int n3)
{
	int auxiliar = max(n1,n2);
	return max(auxiliar, n3);
}
int rutmaxDivideconqui(int camino[],int inic,int fin){
	if ( inic == fin){
	
		return max(0,camino[inic]);
	}
	int m;
	m = (inic+fin)/2;
	int sumaxi,sumaxd,max2izq,suma=0;
	max2izq = suma = camino[m];
	sumaxi = rutmaxDivideconqui(camino,inic,m);
	sumaxd = rutmaxDivideconqui(camino,m+1,fin);
	
	for (int i = m-1; i >= inic ; i--)
	{
		suma = suma + camino[i];
		max2izq = max(max2izq, suma);
	}
	int max2der;
	max2der = suma = camino[m+1];
	for (int j = m+2; j <= fin; j++)
	{
		suma = suma + camino[j];
		max2der = max(max2der, suma);
	}
	int maxid;
	maxid=max2izq+max2der;
	return max2(sumaxi,maxid,sumaxd);

}
void rutmaxLineal(int camino[],int tamaho){
    int ans = camino[0],sum=0;
	int ca1=1;
	for (int i = 1; i < tamaho; i++)
	{
		ans=max(ans,camino[i]);
	}
	if (ans < 0)
	{
		cout<<"La ruta es desfavorable"<<endl;
		
	}
	ans = 0;
	for(int i =0;i<tamaho;i++){
		if (sum + camino[i] > 0)
		{
			sum+=camino[i];

		}
		else
		{
			sum =0;
			
		}
		if(sum>ans){
			ans=max(ans,sum);
			ca1 = i+1;
		
		}
		
		
	}
	cout << "La mejor parte de la ruta es:"<<ans<<" en las calles"<<ca1 <<"y"<<ca1+1<<endl;
	
	
    
}

int main(){
    int tam;
	cout<<"ingrese tamaño"<<endl;
	cin>>tam;
	int ruta[tam];
	for (int i = 0; i < tam; ++i)
	{
		cin>>ruta[i];
	}
	cout<<"Lineal"<<endl;
	rutmaxLineal(ruta, tam);
	cout<<endl;
	cout<<"Divide y conquista";
	cout<<endl;
	cout<<rutmaxDivideconqui(ruta,0,tam-1)<<endl;
	return 0;
}