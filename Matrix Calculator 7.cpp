#include <iostream>
using namespace std;

class Matrix {
private:
    int row, col;
    int a[3][3];

public:
    Matrix() {
        row = col = 0;
    }

    void input() {
        cout << "Enter rows and columns (max 3): ";
        cin >> row >> col;

        cout << "Enter matrix elements:\n";
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                cin >> a[i][j];
            }
        }
    }

    void display() {
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                cout << a[i][j] << "\t";
            }
            cout << endl;
        }
    }

    Matrix operator+(Matrix m) {
        Matrix temp;
        temp.row = row;
        temp.col = col;

        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                temp.a[i][j] = a[i][j] + m.a[i][j];

        return temp;
    }

    Matrix operator-(Matrix m) {
        Matrix temp;
        temp.row = row;
        temp.col = col;

        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                temp.a[i][j] = a[i][j] - m.a[i][j];

        return temp;
    }

    Matrix operator*(Matrix m) {
        Matrix temp;
        temp.row = row;
        temp.col = m.col;

        for(int i=0;i<temp.row;i++) {
            for(int j=0;j<temp.col;j++) {
                temp.a[i][j] = 0;
                for(int k=0;k<col;k++) {
                    temp.a[i][j] += a[i][k] * m.a[k][j];
                }
            }
        }

        return temp;
    }

    void transpose() {
        cout << "Transpose Matrix:\n";
        for(int i=0;i<col;i++) {
            for(int j=0;j<row;j++) {
                cout << a[j][i] << "\t";
            }
            cout << endl;
        }
    }

    void checkSymmetric() {
        if(row != col) {
            cout << "Not Symmetric Matrix\n";
            return;
        }

        bool flag = true;

        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(a[i][j] != a[j][i]) {
                    flag = false;
                    break;
                }
            }
        }

        if(flag)
            cout << "Matrix is Symmetric\n";
        else
            cout << "Matrix is Not Symmetric\n";
    }

    void determinant() {
        if(row != col) {
            cout << "Determinant not possible.\n";
            return;
        }

        if(row == 1) {
            cout << "Determinant = " << a[0][0] << endl;
        }

        else if(row == 2) {
            int det = a[0][0]*a[1][1] - a[0][1]*a[1][0];
            cout << "Determinant = " << det << endl;
        }

        else if(row == 3) {
            int det =
            a[0][0]*(a[1][1]*a[2][2]-a[1][2]*a[2][1])
          - a[0][1]*(a[1][0]*a[2][2]-a[1][2]*a[2][0])
          + a[0][2]*(a[1][0]*a[2][1]-a[1][1]*a[2][0]);

            cout << "Determinant = " << det << endl;
        }

        else {
            cout << "Only up to 3x3 supported.\n";
        }
    }
};

int main() {
    Matrix A, B, C;

    cout << "Enter First Matrix\n";
    A.input();

    cout << "\nEnter Second Matrix\n";
    B.input();

    cout << "\nMatrix Addition\n";
    C = A + B;
    C.display();

    cout << "\nMatrix Subtraction\n";
    C = A - B;
    C.display();

    cout << "\nMatrix Multiplication\n";
    C = A * B;
    C.display();

    cout << "\n";
    A.transpose();

    cout << "\n";
    A.checkSymmetric();

    cout << "\n";
    A.determinant();

    return 0;
}
