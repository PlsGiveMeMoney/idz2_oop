#include <iostream>

int* create_array(int size) {

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10;
    }
    return arr;
}

int* delete_some(int* arr, int a, int k, int size) {

    --a;
    int* tmp = new int[size - k];

    for (int i = 0; i < a; i++) {
        tmp[i] = arr[i];
    }
    for (int i = a + k; i < size; i++) {
        tmp[i - k] = arr[i];
    }
    delete[] arr;
    return tmp;
}

int* add_some(int* arr, int a, int k, int size) {

    --a;
    int* tmp = new int[size + k];

    for (int i = 0; i < a; i++) {
        tmp[i] = arr[i];
    }
    for (int i = a; i < a + k; i++) {
        tmp[i] = rand() % 10;
    }

    for (int i = a; i < size; i++) {
        tmp[i + k] = arr[i];
    }
    delete[] arr;

    size += k;
    return tmp;
}

void print_array(int* arr, int size) {
    std::cout << "massiv: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int main()
{
    int size, a, k;
    std::cout << "razmer massiva:";
    std::cin >> size;

    int* arr = create_array(size);

    print_array(arr, size);
    std::cout << "s kakogo elementa udalit':";
    std::cin >> a;
    std::cout << "skol'ko elementov udalit':";
    std::cin >> k;
    arr = delete_some(arr, a, k, size);
    size = size - k;

    print_array(arr, size);
    std::cout << "s kakogo elementa dobavit':";
    std::cin >> a;
    std::cout << "skol'ko elementov dobavit':";
    std::cin >> k;
    size = size + k;
    arr = add_some(arr, a, k, size);

    print_array(arr, size);

    delete[] arr;
    return 0;
}

