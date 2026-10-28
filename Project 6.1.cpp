#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Сформувати масив
void Create(int* c, const int size, const int Low, const int High) {
    for (int i = 0; i < size; i++) {
        c[i] = Low + rand() % (High - Low + 1);
    }
}

// Вивести масив у вигляді рядка з форматним виведенням
void Print(const int* c, const int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(4) << c[i];
    }
    cout << endl;
}

// Перевірка критерію: елемент задовольняє умові, якщо він НЕ парний і індекс НЕ кратний 13
bool Criterion(int element, int index) {
    return !(element % 2 == 0 || index % 13 == 0);
}

// Обчислити кількість елементів, що задовольняють критерію
int Count(const int* c, const int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (Criterion(c[i], i)) {
            count++;
        }
    }
    return count;
}

// Обчислити суму елементів, що задовольняють критерію
int Sum(const int* c, const int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (Criterion(c[i], i)) {
            sum += c[i];
        }
    }
    return sum;
}

// Замінити нулями елементи, що задовольняють критерію
void Zero(int* c, const int size) {
    for (int i = 0; i < size; i++) {
        if (Criterion(c[i], i)) {
            c[i] = 0;
        }
    }
}

int main() {
    srand(static_cast<unsigned>(time(NULL)));

    const int N = 21;
    int c[N];
    const int Low = 15;
    const int High = 85;

    Create(c, N, Low, High);

    cout << "Initial array:" << endl;
    Print(c, N);

    int count = Count(c, N);
    int sum = Sum(c, N);

    cout << "Count = " << count << endl;
    cout << "Sum   = " << sum << endl;

    Zero(c, N);

    cout << "Modified array:" << endl;
    Print(c, N);

    return 0;
}