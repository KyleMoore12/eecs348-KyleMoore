#include <iostream>
#include <fstream>

int get_input(char file_name[])
{
    std::ifstream my_file(file_name, std::ifstream::in);
    if (!my_file)
        std::cout << "cannot open file" << std::endl;
    my_file.seekg(0, my_file.end);
    int len = my_file.tellg();
    my_file.seekg(0, my_file.beg);
    char data[100];
    char k = 1;
    my_file.read(data, len);
    my_file.close();
    int N = data[0] - '0';
    return 0;
}

int main()
{
    std::cout << "Kyle Moore\nLab #6: Matrix manipulation\n";
    char file_name[50] = "matrix_input.txt";
    int my_array = get_input(file_name);
    return 0;
}