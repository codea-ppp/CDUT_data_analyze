#include <iostream>
#include <vector>

#include <input_the_matrix.h>
#include <solution.h>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Need and only need a parament of the input file" << std::endl;
        return 0;
    }

    FILE* file = fopen(argv[1], "r");
    if (!file)
    {
        std::cout << "can not open the file: " << argv[1] << std::endl;
        return 0;
    }

    std::vector<std::vector<double>> matrix;
    matrix_input(matrix, file);

    solution(matrix);

    return 0;
}
