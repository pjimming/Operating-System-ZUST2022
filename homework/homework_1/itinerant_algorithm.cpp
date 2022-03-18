/*
 * @Author: 潘江明
 * @CreateTime: 2022-2-26
 */

#include <iostream>

int p[] = {0, 4, 7, 3, 2, 1, 5, 6};

int main() {
    int x, k = 1;

    while (k <= 7) {
        x = k;
        do {
            std::cout << x << ' ';
            x = p[x];
        } while (x != k);
        k++;
        std::cout << std::endl;
    }

    return 0;
}
