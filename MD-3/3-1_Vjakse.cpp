#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void rotate90(int* source, int* dest, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            *(dest + j * N + (N - 1 - i)) = *(source + i * N + j);
        }
    }
}

void printArray(int* array, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << *(array + i * N + j) << " ";
        }
        cout << endl;
    }
}

int main() {
    srand(time(0)); // Inicialize nejauso skaitlu generatoru

    const int N = 3; // N var pieskirt jebkuru velamo izmeru
    int array[N][N];
    int rotatedArray[N][N];

    // Aizpilda masivu ar nejausiem skaitliem no 10 lidz 99
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            array[i][j] = rand() % 90 + 10; // Ģenere skaitli no 10 lidz 99
        }
    }

    // Izvada sakotnejo masivu uz ekrana
    cout << "Sakotnejais masivs:" << endl;
    printArray((int*)array, N);

    // Sagroza masivu par 90 gradiem
    rotate90((int*)array, (int*)rotatedArray, N);

    // Izvada sagrozito masivu uz ekrāna
    cout << "Masivs sagrozits par 90 grādiem:" << endl;
    printArray((int*)rotatedArray, N);

    return 0;
}
