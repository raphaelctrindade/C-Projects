#include <stdio.h>
#include <stdlib.h>


void QuickSort(float *v, int n)
{
	int ultMen, j;
	float aux;

	if(n<=1)
		return; /* Está ordenado */

	ultMen = 0;

	for(j=1;j<n;j++)
		if(v[j]<=v[0])
		{
			ultMen++;
			aux = v[j];
			v[j] = v[ultMen];
			v[ultMen] = aux;
		}

	aux = v[0];
	v[0] = v[ultMen];
	v[ultMen] = aux;

	QuickSort(v, ultMen);
	QuickSort(&v[ultMen+1], n-1-ultMen);

}

int main(void)
{
	float v[10]={5.4,3.4,6.4,1.7,89.6,86.4,56.8,42.3,19.2,10.2};
	int i;

	for(i=0;i<10;i++)
		printf("%.1f\t", v[i]);

	printf("\n\nOrdenando...\n\n\n");
	QuickSort(v, 10);

	for(i=0;i<10;i++)
		printf("%.1f\t", v[i]);

	return 0;

}

