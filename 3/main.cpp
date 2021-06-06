#include <stdlib.h>
#include <stdio.h>

static double x_1[11] = { -5.0000, -4.0000, -3.0000, -2.0000, -1.0000, 0, 1.0000, 2.0000, 3.0000, 4.0000, 5.0000 };

static double y_1[11] = { -0.0000, -0.0002, -0.0366, -0.3679, 0, 0.3679, 0.0366, 0.0004, 0.0002 };

static double x_2[21] = { -5.0000, -4.5000, -4.0000, -3.5000, -3.0000, -2.5000, -2.0000, -1.5000, -1.0000, -0.5000, 0,
                      0.5000, 1.0000, 1.5000, 2.0000, 2.5000, 3.0000, 3.5000, 4.0000, 4.5000, 5.0000 };

static double y_2[21] = { -0.0000, -0.0001, -0.0002, -0.0003, -0.0004, -0.0048, -0.0366, -0.1581, -0.3679, -0.3894, 0,
                      0.3894, 0.3679, 0.1581, 0.0366, 0.0048, 0.0004, 0.0003, 0.0002, 0.0001, 0.0000 };

double Lagrange(double arg)
{
    double accu = 0.00;
    for (int i = 0; i < 11; i++)
    {
        double temp = 1.00;
        for (int j = 0; j < 11; j++)
        {
            if (i == j)
            {
                continue;
            }
            else
            {
                temp *= ((arg - x_1[j]) / (x_1[i] - x_1[j]));
            }
        }
        accu += temp * y_1[i];
        temp = 0.00;
    }
    return accu;
}

double S(double arg)
{

}

int main(int argc, char* argv[])
{
    printf("x\t\t\ty\t\t\tLagrange\t\tS(x)\n");
    for (int i = 0; i < 22; i++)
    {
        printf("%lf\t\t%lf\t\t%lf\t\t%lf\n", x_2[i], y_2[i], Lagrange(x_2[i]), Lagrange(x_2[i]));
    }

    return 0;
}
