#include <iostream>
#include <fstream>

using namespace std;

const int SIZE = 4; // Global variable for matrix size

class Matrix {

private:
    int data[SIZE][SIZE]; // 2D array for matrix data (using int for simplicity)

public:

    // 1. Read values from stdin into a matrix
    void readFromStdin() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                cin >> data[i][j]; // get matrix values manually
            }
        }
    }

    void readFromFile(const string &filename) {
        ifstream file(filename);
        if (!file) {
            cerr << "Error opening file: " << filename << endl;
            return;
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                file >> data[i][j]; // get matrix values from file
            }
        }
        file.close();
    }

    // 2. Display a matrix
    void display() const {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                cout << data[i][j] << " "; // print matrix value
            }
            cout << endl;
        }
    }

    // 3. Add two matrices (operator overloading for +)
    Matrix operator+(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j]; // add matrix values
            }
        }
        return result;
    }

    // 4. Multiply two matrices (operator overloading for *)
    Matrix operator*(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                result.data[i][j] = 0;
                for (int k = 0; k < SIZE; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j]; // multiply matrix values
                }
            }
        }
        return result;
    }

    // 5. Compute the sum of matrix diagonal elements
    int sumOfDiagonals() const {
        int sum = 0;
        for (int i = 0; i < SIZE; i++) {
            sum += data[i][i];
            sum += data[i][SIZE - i - 1];
        }
        return sum;
    }

    // 6. Swap matrix rows
    void swapRows(int row1, int row2) {
        if (row1 >= 0 && row1 < SIZE && row2 >= 0 && row2 < SIZE) {
            for (int i = 0; i < SIZE; i++) {
                int tempValue = data[row1][i];
                data[row1][i] = data[row2][i];
                data[row2][i] = tempValue;
            }
        }
        else {
            cout << "Invalid row indices." << endl;
        }
    }
};

int main() {
    // Example usage:
    Matrix mat1;
    cout << "Enter values for Matrix 1:" << endl;
    mat1.readFromFile("matrix-data.txt");
    cout << "Matrix 1:" << endl;
    mat1.display();
    Matrix mat2;
    cout << "Enter values for Matrix 2:" << endl;
    mat2.readFromFile("matrix-data2.txt");
    cout << "Matrix 2:" << endl;
    mat2.display();
    Matrix sum = mat1 + mat2;
    cout << "Sum of matrices:" << endl;
    sum.display();
    Matrix product = mat1 * mat2;
    cout << "Product of matrices:" << endl;
    product.display();
    cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;
    mat1.swapRows(0, 2);
    cout << "Matrix 1 after swapping rows:" << endl;
    mat1.display();
    return 0;
}