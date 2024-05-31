#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

using type = uint64_t;
using Matrix = uint64_t * *;

// Returns a new NxN matrix
Matrix createMatrix(int N) {
	Matrix newMatrix = new type *[N];
	for (unsigned int i = 0; i < N; i++) {
		newMatrix[i] = new type[N];
	}
	return newMatrix;
}


/***** Matrix Operations *******/


// Add two matrices
Matrix add(Matrix A, Matrix B, int N) {

	Matrix C = createMatrix(N);

	for (unsigned int i = 0; i < N; i++)
		for (unsigned int j = 0; j < N; j++)
			C[i][j] = A[i][j] + B[i][j];

	return C;
}

// Subtract two matrices
Matrix subtract(Matrix A, Matrix B, int N) {
	Matrix C = createMatrix(N);

	for (unsigned int i = 0; i < N; i++)
		for (unsigned int j = 0; j < N; j++)
			C[i][j] = A[i][j] - B[i][j];

	return C;
}

// Linear Matrix Multiplication
Matrix sq_matrix_multiply(Matrix A, Matrix B, int N) {

	Matrix C = createMatrix(N);

	type sum = 0;									

	for (unsigned int i = 0; i < N; i++) {						
		for (unsigned int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				sum += A[i][k] * B[k][j];				
			}
			C[i][j] = sum;							
			sum = 0;							
		}
	}
	return C;
}


// Strassen's Algorithm
Matrix strassen(Matrix A, Matrix B, int N) {

	// Base case
	if (N == 1) {
		return sq_matrix_multiply(A, B, N);
	}

	// Create a new matrix to hold the result
	Matrix C = createMatrix(N);

	int K = N / 2;

	// New sub-matrices
	Matrix A11 = createMatrix(K);
	Matrix A12 = createMatrix(K);
	Matrix A21 = createMatrix(K);
	Matrix A22 = createMatrix(K);
	Matrix B11 = createMatrix(K);
	Matrix B12 = createMatrix(K);
	Matrix B21 = createMatrix(K);
	Matrix B22 = createMatrix(K);


	// Populate the values accordingly
	for (unsigned int i = 0; i < K; i++) {
		for (unsigned j = 0; j < K; j++) {
			A11[i][j] = A[i][j];
			A12[i][j] = A[i][K + j];		// Bug solved: I had a type: A22 instead of A12
			A21[i][j] = A[K + i][j];
			A22[i][j] = A[K + i][K + j];
			B11[i][j] = B[i][j];
			B12[i][j] = B[i][K + j];		// Bug solved: I had a type: B22 instead of B12
			B21[i][j] = B[K + i][j];
			B22[i][j] = B[K + i][K + j];
		}
	}

	// S
	Matrix S1 = subtract(B12, B22, K);
	Matrix S2 = add(A11, A12, K);
	Matrix S3 = add(A21, A22, K);
	Matrix S4 = subtract(B21, B11, K);
	Matrix S5 = add(A11, A22, K);
	Matrix S6 = add(B11, B22, K);
	Matrix S7 = subtract(A12, A22, K);
	Matrix S8 = add(B21, B22, K);
	Matrix S9 = subtract(A21, A11, K);
	Matrix S10 = add(B11, B12, K);

	// P
	Matrix P3 = strassen(A11, S1, K);
	Matrix P5 = strassen(S2, B22, K);
	Matrix P2 = strassen(S3, B11, K);
	Matrix P4 = strassen(A22, S4, K);
	Matrix P1 = strassen(S5, S6, K);
	Matrix P7 = strassen(S7, S8, K);
	Matrix P6 = strassen(S9, S10, K);

	// C_i	
	Matrix C11 = subtract(add(add(P1, P4, K), P7, K), P5, K);				// P5 + P4 - P2 + P6
	Matrix C12 = add(P3, P5, K);								// P1 + P2
	Matrix C21 = add(P2, P4, K);								// P3 + P4
	Matrix C22 = subtract(add(add(P1, P3, K), P6, K), P2, K);				// P1 + P5 - P3 - P7

																				// C
	for (unsigned int i = 0; i < K; i++) {
		for (unsigned int j = 0; j < K; j++) {

			C[i][j] = C11[i][j];

			C[i][j + K] = C12[i][j];

			C[K + i][j] = C21[i][j];

			C[K + i][K + j] = C22[i][j];
		}
	}

	// Return the result
	return C;
}

int main(int argc, char const *argv[])
{
    
    uint32_t n, i, j, k, d1, p1, r1, m1, d2, p2, r2, m2;
    cin >> n >> p1 >> d1 >> r1 >> m1 >> p2 >> d2 >> r2 >> m2;
    uint32_t A[n][n], B[n][n];
    uint64_t C[n][n] = {0};
    uint64_t V[n] = {0};
    // Matrix A = createMatrix(n);
    // Matrix B = createMatrix(n);
    
    // Matrix C = createMatrix(n);
    // long long V[n];

    for (i=0; i<n; ++i)
        for (j=0; j<n; ++j) {
            d1 = d1 * p1 + r1;
            d2 = d2 * p2 + r2;
            A[i][j] = d1 >> (32 - m1);
            B[i][j] = d2 >> (32 - m2);
        }

    // C = strassen(A, B, n);
   
    // for (i=0; i<n; ++i) {
    //     V[i] = 0;
    //     for (j=0; j<n; ++j)
    //         V[i] ^= C[i][j];
    // }
    
    // for (size_t i = 0; i < n; i++)
    // {
    //     cout << V[i] << " ";
    // }
    // cout << endl;									

	// for (i = 0; i < n; i++) {
    //     for (j = 0; j < n; j++) {
            

    //         for (k = 0; k < n; k++) {
    //             C[i][k] += uint64_t(A[i][j]) * uint64_t(B[j][k]);
    //         }

    //         // cout << C[i][j] << "\t";
    //     }

    //     // cout << endl;
    // }

    // C = sq_matrix_multiply(A, B, n);
    for (i=0; i<n; ++i) {
        
        for (j=0; j<n; ++j)
            V[i] ^= C[i][j];
    }

    for (i = 0; i < n; i++)
    {
        cout << V[i] << " ";
    }


    return 0;
}
