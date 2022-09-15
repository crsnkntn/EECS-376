#include <iostream>
#include <chrono>
#include <vector>
#include <string>

int fib (int n) {
    if (n <= 1)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}

int fib_no_memo (int n) {
    auto start = std::chrono::high_resolution_clock::now();
    int f = fib(n);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Not Memoized Fib(" << n << ") =" << f << " took " << duration.count() << " microseconds" << std::endl;

    return static_cast<int>(duration.count());
}

int fib_memoized (int n, std::vector<int>& memo) {
    if (n <= 1)
        return 1;
    if (memo[n] == -1)
        memo[n] = fib_memoized(n - 1, memo) + fib_memoized(n - 2, memo);
    return memo[n];
}

int fib_yes_memo (int n) {
    std::vector<int> memo(n + 1, -1);
    auto start = std::chrono::high_resolution_clock::now();
    int f = fib_memoized(n, memo);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Memoized Fib(" << n << ") =" << f << " took " << duration.count() << " microseconds" << std::endl;

    return static_cast<int>(duration.count());
}

int main (int argc, char** argv) {
    if (argc != 2)
        exit(1);

    int n = std::stoi(argv[1]);

    int fn = fib_no_memo(n);
    int fy = fib_yes_memo(n);
}
