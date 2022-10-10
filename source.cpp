#include <iostream>
#include <ctime>
using namespace std;

int main() {
    srand(time(NULL));
    int x, y;
    cin >> x;
    y = x;
    int **matrix;
    matrix = new int*[x];
    for (int i = 0; i < x; i++) {
        matrix[i] = new int[y];
    }

    for (int i = 0; i<x; i++) {
        for (int j = 0; j<y; j++) {
            matrix[i][j] = rand()%100-50;
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "---" << "\n"; // для удобства

    for (int i = 0; i<x; i++) {
        for (int j = 0; j<x; j++) {
            if (matrix[i][j] < 0) {
                matrix[i][j] = -1;
            } else if (matrix[i][j] > 0) {
                matrix[i][j] = 1;
            }

            cout << matrix[i][j] << " ";
        }
        cout << "\n";
        delete [] matrix[i];
    }
    delete [] matrix;
    return 0;
}
