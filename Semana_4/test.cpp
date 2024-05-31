#include <iostream>



int main() {
    uint32_t n, i, j, d1, p1, r1, m1, d2, p2, m2, A[n][n], B[n][n], r2;
    uint64_t C[n][n], V[n];

    //read n, p1, d1, r1, m1, p2, d2, r2, m2 from input.
    std::cin >> n >> p1 >> d1 >> r1 >> m1 >> p2 >> d2 >> r2 >> m2;

    for (i=0; i<n; ++i)
        for (j=0; j<n; ++j) {
            d1 = d1 * p1 + r1;
            d2 = d2 * p2 + r2;
            A[i][j] = d1 >> (32 - m1);
            B[i][j] = d2 >> (32 - m2);
        }

    //here you need to calculate C=A*B
    for (i=0; i<n; ++i)
        for (j=0; j<n; ++j) {
            C[i][j] = 0;
            for (int k=0; k<n; ++k)
                C[i][j] += (uint64_t)A[i][k] * B[k][j];
        }
    
    for (i=0; i<n; ++i) {
        V[i] = 0;
        for (j=0; j<n; ++j)
            V[i] ^= C[i][j];
    }

    //here you need to output V[0], V[1], ..., V[n-1], separated by spaces.
    for (i=0; i<n; ++i)
        std::cout << V[i] << " ";

    return 0;
}