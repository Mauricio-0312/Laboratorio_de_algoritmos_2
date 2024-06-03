/*
Alumno: Mauricio Fragachan
Carnet: 2010265
*/

#include <iostream>
#include <vector>

using namespace std;

// Function to calculate next power of 2 given a number k
int nextPowerOf2(int k) {
    int n = 1;
    while (n < k) {
        n *= 2;
    }
    return n;
}

//Function to multiply two matrices without using strassen algorithm
vector<vector<uint64_t>> multiplyClassicalWay(const vector<vector<uint64_t>>& A, const vector<vector<uint64_t>>& B) {
    int n = A.size();
    vector<vector<uint64_t>> C(n, vector<uint64_t>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    return C;
}

// Operator to subtract two matrices
vector<vector<uint64_t>> operator-(const vector<vector<uint64_t>>& A, const vector<vector<uint64_t>>& B) {
    int n = A.size();
    vector<vector<uint64_t>> C(n, vector<uint64_t>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

// Operator to add two matrices
vector<vector<uint64_t>> operator+(const vector<vector<uint64_t>>& A, const vector<vector<uint64_t>>& B) {
    int n = A.size();
    vector<vector<uint64_t>> C(n, vector<uint64_t>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

// Function to multiply two matrices using Strassen's algorithm
vector<vector<uint64_t>> strassenMultiply(const vector<vector<uint64_t>>& A, const vector<vector<uint64_t>>& B,int limitForClassicalAlgo) {
    int n = A.size();

    // Base case: if the matrices are 1x1
    if (n == 1) {
        vector<vector<uint64_t>> C(1, vector<uint64_t>(1));
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    // Use the classical algorithm if size of matrices is less than or equal to limitForClassicalAlgo
    if(n <= limitForClassicalAlgo){
        return multiplyClassicalWay(A, B);
    }

    // Splitting the matrices into quadrants
    int mid = n / 2;
    vector<vector<uint64_t>> A11(mid, vector<uint64_t>(mid));
    vector<vector<uint64_t>> A12(mid, vector<uint64_t>(mid));
    vector<vector<uint64_t>> A21(mid, vector<uint64_t>(mid));
    vector<vector<uint64_t>> A22(mid, vector<uint64_t>(mid));
    vector<vector<uint64_t>> B11(mid, vector<uint64_t>(mid));
    vector<vector<uint64_t>> B12(mid, vector<uint64_t>(mid));
    vector<vector<uint64_t>> B21(mid, vector<uint64_t>(mid));
    vector<vector<uint64_t>> B22(mid, vector<uint64_t>(mid));

    for (uint64_t i = 0; i < mid; i++) {
        for (uint64_t j = 0; j < mid; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mid];
            A21[i][j] = A[i + mid][j];
            A22[i][j] = A[i + mid][j + mid];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mid];
            B21[i][j] = B[i + mid][j];
            B22[i][j] = B[i + mid][j + mid];
        }
    }

    // Calculating the seven products required for Strassen's algorithm
    vector<vector<uint64_t>> P1 = strassenMultiply(A11, B12 - B22, limitForClassicalAlgo);
    vector<vector<uint64_t>> P2 = strassenMultiply(A11 + A12, B22, limitForClassicalAlgo);
    vector<vector<uint64_t>> P3 = strassenMultiply(A21 + A22, B11, limitForClassicalAlgo);
    vector<vector<uint64_t>> P4 = strassenMultiply(A22, B21 - B11, limitForClassicalAlgo);
    vector<vector<uint64_t>> P5 = strassenMultiply(A11 + A22, B11 + B22, limitForClassicalAlgo);
    vector<vector<uint64_t>> P6 = strassenMultiply(A12 - A22, B21 + B22, limitForClassicalAlgo);
    vector<vector<uint64_t>> P7 = strassenMultiply(A11 - A21, B11 + B12, limitForClassicalAlgo);

    // Calculating the four quadrants of the resulting matrix
    vector<vector<uint64_t>> C11 = P5 + P4 - P2 + P6;
    vector<vector<uint64_t>> C12 = P1 + P2;
    vector<vector<uint64_t>> C21 = P3 + P4;
    vector<vector<uint64_t>> C22 = P5 + P1 - P3 - P7;

    // Combining the four quadrants into a single matrix
    vector<vector<uint64_t>> C(n, vector<uint64_t>(n));
    for (uint64_t i = 0; i < mid; i++) {
        for (uint64_t j = 0; j < mid; j++) {
            C[i][j] = C11[i][j];
            C[i][j + mid] = C12[i][j];
            C[i + mid][j] = C21[i][j];
            C[i + mid][j + mid] = C22[i][j];
        }
    }

    return C;
}
int main() {
    uint32_t n, i, j, d1, p1, r1, m1, d2, p2, m2, r2;
    vector<vector<uint64_t>> A, B, C;
    vector<uint64_t> V;

    //read n, p1, d1, r1, m1, p2, d2, r2, m2 from input.
    cin >> n >> p1 >> d1 >> r1 >> m1 >> p2 >> d2 >> r2 >> m2;

    // Compute right dimension for strassen. So, if n is not a power of 2, then we compute the next power of 2 after n and
    // resize the matrices to this new size.
    int k = nextPowerOf2(n);
    A.resize(k, vector<uint64_t>(k, 0));
    B.resize(k, vector<uint64_t>(k, 0));
    C.resize(k, vector<uint64_t>(k, 0));
    V.resize(n);

    for (i=0; i<n; ++i)
        for (j=0; j<n; ++j) {
            d1 = d1 * p1 + r1;
            d2 = d2 * p2 + r2;
            A[i][j] = d1 >> (32 - m1);
            B[i][j] = d2 >> (32 - m2);
        }

    // Compute matrix multiplication
    C = strassenMultiply(A, B, 64);
    
    for (i=0; i<n; ++i) {
        V[i] = 0;
        for (j=0; j<n; ++j)
            V[i] ^= C[i][j];
    }

    // Print V[0], V[1], ..., V[n-1], separated by spaces.
    for (i=0; i<n; ++i)
        cout << V[i] << " ";

    return 0;
}