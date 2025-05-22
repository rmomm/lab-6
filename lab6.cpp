#include "lab1.h"
#include <iostream>
#include <vector>
#include <cmath> 
using namespace std;


vector<pair<int, int>> primeFactorization(int n) {
    vector<pair<int, int>> factors;
    for (int p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            int count = 0;
            while (n % p == 0) {
                n /= p;
                count++;
            }
            factors.push_back({ p, count });
        }
    }
    if (n > 1) {
        factors.push_back({ n, 1 });
    }
    return factors;
}


int eulerFunc(int n) {
    if (n <= 0) {
        return 0;
    }
    auto factors = primeFactorization(n);
    int result = 1;
    for (auto factor : factors) {
        int p = factor.first;
        int a = factor.second;
        result *= (pow(p, a) - pow(p, a - 1));
    }
    return result;
}