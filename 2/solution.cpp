#include "solution.h"

#include <iostream>

void solution(std::vector<std::vector<double>>& matrix)
{
    std::cout << "消元:" << std::endl;

    for (int row = 0; row < int(matrix.size() - 1); row++)
    {
        for (int column = row + 1; column < int(matrix.size() - 1); column++)
        {
            matrix[std::vector<double>::size_type(column)][std::vector<double>::size_type(row)]
                    /= matrix[std::vector<double>::size_type(row)][std::vector<double>::size_type(row)];

            for (int index = row + 1; index < int(matrix[std::vector<double>::size_type(row)].size()); index++)
            {
                matrix[std::vector<double>::size_type(column)][std::vector<double>::size_type(index)]
                        -= matrix[std::vector<double>::size_type(row)][std::vector<double>::size_type(index)]
                        * matrix[std::vector<double>::size_type(column)][std::vector<double>::size_type(row)];
            }
        }

        for (int i = 0; i < int(matrix.size() - 1); i++)
        {
            for (int j = 0; j < int(matrix[std::vector<double>::size_type(i)].size()); j++)
            {
                std::cout << matrix[std::vector<double>::size_type(i)][std::vector<double>::size_type(j)] << "\t\t\t\t\t";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    std::cout << "回代:" << std::endl;

    int result = int(matrix.size() - 1);
    for (int row = int(matrix.size() - 2); row > -1; row--)
    {
        matrix[std::vector<double>::size_type(row)][std::vector<double>::size_type(result)]
                /= matrix[std::vector<double>::size_type(row)][std::vector<double>::size_type(row)];

        for (int column = row - 1; column > -1; column--)
        {
            matrix[std::vector<double>::size_type(column)][std::vector<double>::size_type(result)] -=
                    matrix[std::vector<double>::size_type(row)][std::vector<double>::size_type(result)] *
                    matrix[std::vector<double>::size_type(column)][std::vector<double>::size_type(row)];
        }

        for (int i = 0; i < int(matrix.size() - 1); i++)
        {
            for (int j = 0; j < int(matrix[std::vector<double>::size_type(i)].size()); j++)
            {
                std::cout << matrix[std::vector<double>::size_type(i)][std::vector<double>::size_type(j)] << "\t\t\t\t\t";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}
