#include <iostream>
using namespace std;

class Matrix {
    int rows, cols;
    int **data;

public:
    Matrix(int r = 0, int c = 0) : rows(r), cols(c) {
        data = new int*[rows];
        for (int i = 0; i < rows; i++) data[i] = new int[cols]{0};
    }

    void Fill() {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++) {
                cout << "Enter value at (" << i + 1 << "," << j + 1 << "): ";
                cin >> data[i][j];
            }
    }

    void ResizeMatrix(int newRows, int newCols) {
        int **newData = new int*[newRows];
        for (int i = 0; i < newRows; i++) {
            newData[i] = new int[newCols];
            for (int j = 0; j < newCols; j++) {
                if (i < rows && j < cols) newData[i][j] = data[i][j];
                else newData[i][j] = -1;
            }
        }
        for (int i = 0; i < rows; i++) delete[] data[i];
        delete[] data;
        data = newData;
        rows = newRows;
        cols = newCols;
    }

    void Transpose() {
        int **newData = new int*[cols];
        for (int i = 0; i < cols; i++) {
            newData[i] = new int[rows];
            for (int j = 0; j < rows; j++) newData[i][j] = data[j][i];
        }
        for (int i = 0; i < rows; i++) delete[] data[i];
        delete[] data;
        data = newData;
        swap(rows, cols);
    }

    void print() {
        cout << "BEFORE:\n";
        for (int i = 0; i < rows; i++) {
            cout << "[ ";
            for (int j = 0; j < cols; j++) cout << data[i][j] << " ";
            cout << "]\n";
        }
        cout << "AFTER:\n";
        for (int i = 0; i < rows; i++) {
            cout << "[ ";
            for (int j = 0; j < cols; j++) {
                int val = data[i][j];
                if ((i + j) % 2 == 1) val += 2;
                cout << val << " ";
            }
            cout << "]\n";
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++) delete[] data[i];
        delete[] data;
    }
};

int main() {
    Matrix m(2, 3);
    m.Fill();

    cout << "\nOriginal Matrix:\n";
    m.print();

    cout << "\nAfter Resizing to 3x4:\n";
    m.ResizeMatrix(3, 4);
    m.print();

    cout << "\nAfter Transpose:\n";
    m.Transpose();
    m.print();
}
