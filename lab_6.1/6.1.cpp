#include <iostream>
#include <iomanip>
#include <random>

using namespace std;

void generateArray(int arr[], int size, int min_value, int max_value) {
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(min_value, max_value);

    for (int i = 0; i < size; i++) {
        arr[i] = distribution(generator);
    }
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(4) << arr[i];
    }
    cout << endl;
}

void countAndSumElements(const int arr[], int size, int& count, int& sum) {
    count = 0;
    sum = 0;

    // Рахуємо кількість та суму елементів, що не є парними з індексами, кратними 13
    for (int i = 0; i < size; i++) {
        if (!(arr[i] % 2 == 0 && i % 13 == 0)) {
            count++;
            sum += arr[i];
        }
    }
}

void replaceSpecificElements(int arr[], int size) {
    // Замінюємо нулями парні елементи на індексах, кратних 13
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0 && i % 13 == 0) {
            arr[i] = 0;
        }
    }
}

int main() {
    const int SIZE = 25;
    const int MIN_VALUE = 15;
    const int MAX_VALUE = 94;

    int array[SIZE];
    int count, sum;

    // Генеруємо масив
    generateArray(array, SIZE, MIN_VALUE, MAX_VALUE);

    // Виводимо початковий масив
    cout << "Initial array:" << endl;
    printArray(array, SIZE);

    // Рахуємо кількість і суму елементів за критерієм
    countAndSumElements(array, SIZE, count, sum);
    cout << "\nNumber of elements criterion: " << count << endl;
    cout << "Sum: " << sum << endl;

    // Замінюємо елементи, що відповідають критерію
    replaceSpecificElements(array, SIZE);

    // Виводимо змінений масив
    cout << "Modified array:" << endl;
    printArray(array, SIZE);

    return 0;
}
