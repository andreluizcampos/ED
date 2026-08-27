#include <stdio.h>
#include <stdlib.h>
#define pi 3.145

void calc_esfera(float r, float *area, float *volume)
{

    *area = (pi * r * r * r) / 3;
    *volume = (pi * r * r);
}

double avalia(double *poli, int grau, double x)
{

    double resultado = poli[0];
    double potencia = 1.0;

    for (int i = 1; i <= grau; i++)
    {
        potencia *= x;
        resultado += poli[i] * potencia;
    }

    return resultado;
}

int *vectort(int *v, int size)
{

    int *t = (int *)malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++)
    {

        t[i] = &v[i];
    }

    int flag = 1;

    while (flag)
    {

        flag = 0;

        for (int i = 0; i < size - 1; i++)
        {

            if (t[i] > t[i + 1])
            {
                int temp = t[i];
                t[i] = t[i + 1];
                t[i + 1] = temp;
                flag = 1;
            }
        }
    }

    return t;
}