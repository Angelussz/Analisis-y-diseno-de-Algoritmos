//ANGELO ALDO PEREZ RODRIGUEZ
//REFERENCIA: https://www.techiedelight.com/find-maximum-sum-submatrix-present-given-matrix/
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <climits>
using namespace std;    
int submatrizmax(int matriz[][127],int num)
{
	int S[num+1][num+1];

	for (int i = 0; i <= num; i++)
	{
		for (int j = 0; j <= num; j++)
		{
			if (i == 0 || j == 0)
				S[i][j] = 0;
			else
				S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] +
						matriz[i-1][j-1];
		}
	}

	int sumax = INT_MIN;
	int f1, f2, c1, c2;

	for (int i = 0; i < num; i++)
	{
		for (int j = i; j < num; j++)
		{
			for (int m = 0; m < num; m++)
			{
				for (int n = m; n < num; n++)
				{
					
					int suma_submatriz = S[j+1][n+1] - S[j+1][m] -
									S[i][n+1] + S[i][m];

					
					if (suma_submatriz > sumax)
					{
						sumax = suma_submatriz;
						f1 = i;
						f2 = j;
						c1 = m;
						c2 = n;
					}
				}
			}
		}
	}

    cout<<"SUBMATRIZ MAXIMA"<<endl<<endl;
	for(int a=f1;a<=f2-1;a++){
        for (int b=c1; b<c2; b++)
        {
            cout<<matriz[a][b]<<" ";
        }
        cout<<endl;
    }
    return sumax;
}

int main() {
    int f = 0;
    int n=0;
    cin>>f;
    //cout<<f;
    int matriz[127][127];
    for (int i=0;i<f;i++){
        for (int j = 0; j < f; j++)
        {
            cin>>n;
            matriz[i][j] = n;
        }
        
    }
    cout<<"MATRIZ ENTRADA"<<endl<<endl;
    for (int i=0;i<f;i++){
        for (int j = 0; j < f; j++)
        {
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
        
    }

    
    cout<<submatrizmax(matriz,f)<<endl;
    return 0;
}   