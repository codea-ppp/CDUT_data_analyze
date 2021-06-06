#include "input_the_matrix.h"

#include <iostream>

void matrix_input(std::vector<std::vector<double>>& matrix, FILE* file)
{
    bool must_be_number = false;
    bool is_number = false;

    int sign = 1;
    int temp = 0;

    unsigned long column = 0;
    unsigned long row = 0;

    matrix.resize(column + 1);
    for (char ch; EOF != fscanf(file, "%c", &ch);)
    {
        if ('+' == ch)
        {
            if (must_be_number)
            {
                std::cout << "input fomat invaild" << std::endl;
                std::abort();
            }
            sign = 1;
            must_be_number = true;
            is_number = false;
        }
        else if ('-' == ch)
        {
            if (must_be_number)
            {
                std::cout << "input fomat invaild" << std::endl;
                std::abort();
            }
            sign = -1;
            must_be_number = true;
            is_number = false;
        }
        else if ('0' <= ch && '9' >= ch)
        {
            temp *= 10;
            temp += (ch - 0x30) * sign;
            must_be_number = false;
            is_number = true;
        }
        else if (' ' == ch || '\t' == ch)
        {
            if (must_be_number)
            {
                std::cout << "input fomat invaild" << std::endl;
                std::abort();
            }

            if (is_number)
            {
                matrix[column].resize(row + 1);
                matrix[column][row] = temp;
                row++;
            }

            temp = 0;
            sign = 1;
            is_number = false;
        }
        else if ('\n' == ch)
        {
            if (must_be_number)
            {
                std::cout << "input fomat invaild" << std::endl;
                std::abort();
            }

            sign = 1;
            if (is_number)
            {
                matrix[column].resize(row + 1);
                matrix[column][row] = temp;
            }

            temp = 0;
            row = 0;
            column++;
            matrix.resize(column + 1);
            is_number = false;
        }
        else
        {
            std::cout << "input fomat invaild" << std::endl;
            std::abort();
        }
    }

    for (std::vector<std::vector<double>>::iterator i = matrix.begin(); i != matrix.end(); i++)
    {
        for (std::vector<double>::iterator j = i->begin(); j != i->end(); j++)
        {
            std::cout << *j << ' ';
        }

        std::cout << std::endl;
    }
}
