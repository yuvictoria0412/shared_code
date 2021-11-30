// 107033212 游諠澐

#include <iostream>
#define ll long long

ll p[2][2] = {{1, 1}, {1, 0}};
ll n;

void matrix_mul(ll a[2][2], ll b[2][2]) {
    // matrix multiplication

    ll res[2][2];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                if (res[i][j] / 2 + (a[i][k] / 2 * b[k][j]) <= n / 2) { // avoid overflow
                    res[i][j] += a[i][k] * b[k][j];
                }
                else {
                    a[0][0] = -1;
                    return;
                }
            }
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            a[i][j] = res[i][j];
        }
    }
}

ll find_f1(ll n) {
    ll res[2][2] = {{1, 0}, {0, 1}};
    ll f1 = 0;
    ll min_f1 = n - 1;

    while (1) {
        matrix_mul(res, p);
        if (res[0][0] != -1) { 
            if (n < res[0][1] + res[0][0]) {
                return min_f1;
            }
            if ((n - res[0][1]) % res[0][0] == 0) { // ensure f1 is integer
                f1 = (n - res[0][1]) / res[0][0];
                if (f1 < min_f1) {
                    min_f1 = f1;
                }
            }
            else continue;
        }
        else return min_f1; // overflow
    }
}

int main() {
    while (std::cin >> n) {
        if (n == 0)
            std::cout << 0 << std::endl;
        else
            std::cout << find_f1(n) << std::endl;
    }
    return 0;
}