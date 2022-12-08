#include <iostream>

int** create_matrix(int** matr, int n, int m) {
    matr = new int* [n];
    for (int i = 0; i < n; i++)
    {
        matr[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            matr[i][j] = rand() % 100;
        }
    }

    return matr;
}


void print_matrix(int** matr, int n, int m) {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << matr[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void find_special(int** matr, int n, int m) {
    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = 1; j < m - 1; j++)
            if (matr[i][j] < matr[i][j - 1] && matr[i][j] > matr[i][j + 1]) count++;
    std::cout << "\n 'Special': " << count << "\n";
}

int main()
{
    int n, m;
    std::cout << "Enter n: ";
    std::cin >> n;
    std::cout << "Enter m: ";
    std::cin >> m;
    int** matr = new int* [n];
    matr = create_matrix(matr, n, m);
    print_matrix(matr, n, m);
    find_special(matr, n, m);
    delete[]matr;
    return 0;
}
