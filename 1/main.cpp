#include <iostream>
#include <cmath>

static double global_seed = 0.00;

double compute_once(double seed)
{
    return (std::sin(seed) - 1) / (std::pow(seed, 2) - 12);
}

double compute_once_Newton(double seed)
{
    return seed - (std::pow(seed, 3) - std::sin(seed) - 12 * seed + 1) / (2 * std::pow(seed, 2) - std::cos(seed) - 12);
}

double iteration_P(double (*f)(double), double seed)
{
    for (double temp = (*f)(seed); global_seed - temp < -10E-6 || global_seed - temp > 10E-6; )
    {
        std::cout << temp << std::endl;

        global_seed = temp;

        temp = (*f)(global_seed);
    }

    return global_seed;
}

double iteration(double (*f)(double), double seed)
{
    global_seed = seed;

    return (*f)(seed);
}

int main(int argc, char* argv[])
{
    double sign = -1.00;

    double temp = 0.00;

    double (*iteration_function)(double);

    iteration_function = &compute_once_Newton;

    for (int i = -100; i < 100; i++)
    {
        temp = iteration_function(i);

        if (temp * sign <= 0)
        {
            std::cout << "The Seed is " << i << std::endl;

            (*iteration_function)(i);

            std::cout << std::endl;
        }

        temp > 0 ? sign = 1.00 : sign = -1.00;
    }
}
