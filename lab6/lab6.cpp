#include <iostream>
#include <fstream>

const int ARRAY_SIZE = 100;
int get_input(char file_name[])
{
    std::ifstream my_file(file_name, std::ifstream::in);
    if (!my_file)
        std::cout << "cannot open file" << std::endl;
    my_file.seekg(0, my_file.end);
    int len = my_file.tellg();
    my_file.seekg(0, my_file.beg);
    char *data = new char[len + 1];
    my_file.read(data, len);
    my_file.close();
    data[len] = '\n';
    int a[100][100], b[100][100], N, k;
    N = data[0] - '0';
    k = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            while (data[k] == ' ' || data[k] == '\n')
            {
                k++;
            }
            a[i][j] = data[k] - '0';
            k++;
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            while (data[k] == ' ' || data[k] == '\n')
            {
                k++;
            }
            b[i][j] = data[k] - '0';
            k++;
        }
    }
    delete[] data;
}

void print_matrix(int my_matrix[ARRAY_SIZE][ARRAY_SIZE], int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            std::cout << my_matrix[i][j] << '\t';
        std::cout << std::endl;
    }
}

void matrix_sum(int a[ARRAY_SIZE][ARRAY_SIZE], int b[ARRAY_SIZE][ARRAY_SIZE], int N)
{
    int c[ARRAY_SIZE][ARRAY_SIZE];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            c[i][j] = 0;
            c[i][j] = a[i][j] + b[i][j];
        }
    print_matrix(c, N);
}

void matrix_product(int a[ARRAY_SIZE][ARRAY_SIZE], int b[ARRAY_SIZE][ARRAY_SIZE], int N)
{
    int c[ARRAY_SIZE][ARRAY_SIZE];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < N; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }
    print_matrix(c, N);
}

void matrix_difference(int a[ARRAY_SIZE][ARRAY_SIZE], int b[ARRAY_SIZE][ARRAY_SIZE], int N)
{
    int c[ARRAY_SIZE][ARRAY_SIZE];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            c[i][j] = 0;
            c[i][j] = a[i][j] - b[i][j];
        }
    print_matrix(c, N);
}

int main()
{
    std::cout << "Kyle Moore\nLab #6: Matrix manipulation\n";
    char file_name[50] = "matrix_input.txt";
    // int my_array = get_input(file_name);
    int N = 3;
    int a[ARRAY_SIZE][ARRAY_SIZE] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int b[ARRAY_SIZE][ARRAY_SIZE] = {{2, 3, 4}, {5, 6, 7}, {8, 9, 10}};
    std::cout << "Matrix A:\n";
    print_matrix(a, N);
    std::cout << "Matrix B:\n";
    print_matrix(b, N);
    std::cout << "Matrix Sum (A + B):\n";
    matrix_sum(a, b, N);
    std::cout << "Matrix Product(A * B):\n";
    matrix_product(a, b, N);
    std::cout << "Matrix Difference(A - B):\n";
    matrix_difference(a, b, N);
    return 0;
}