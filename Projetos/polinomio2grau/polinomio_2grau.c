#include <stdio.h>
#include <math.h>

double calcula_delta(double coef_x2, double coef_x1, double coef_x0)
{
	return pow(coef_x1,2)-4*coef_x2*coef_x0;
}

int raizes_pol_2o_grau (double coef_x2, double coef_x1, double coef_x0, 
	double *raiz1, double *raiz2)
{
	double delta;

	if (coef_x2 == 0)
		if (coef_x1 == 0)
			if (coef_x0 == 0)
				return -1;
			else
				return 0;
		else
		{
			*raiz1 = -coef_x0/coef_x1;
			return 1;
		}
	else 
	{
		delta = calcula_delta(coef_x2, coef_x1, coef_x0);
		if (delta < 0)
			return 0;
		else if (delta == 0)
		{
			*raiz1 = -coef_x1/(2*coef_x2);
			return 1;
		}
		else
		{
			*raiz1 = (-coef_x1 + sqrt(delta))/(2*coef_x2);
			*raiz2 = (-coef_x1 - sqrt(delta))/(2*coef_x2);
			return 2;
		}
	}
}

int main(void)
{
	double c_x2, c_x1, c_x0;
	double raiz1, raiz2;
	int num_raizes;
	printf("Digite os coeficientes de x2, x1 e x0: ");
	scanf ("%lf %lf %lf", &c_x2, &c_x1, &c_x0);

	num_raizes = raizes_pol_2o_grau (c_x2, c_x1, c_x0, &raiz1, &raiz2);

	if (num_raizes == -1)
		printf("O polinomio tem infinitas raizes reais\n");
	else if (num_raizes == 0)
		printf("O polinomio nao tem raizes reais\n");
	else if (num_raizes == 1)
		printf ("O polinomio tem uma unica raiz real: %lf\n", raiz1);
	else
		printf ("O polinomio tem duas raizes reais: %lf e %lf\n", raiz1, raiz2);
	return 0;
}