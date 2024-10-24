#include <iostream>

int main() {
    int i = {1};
    int j = {60};

    for(int k = 0;k <= 12;k++) {
        std:: cout << "I=" << i << " J=" << j << std::endl;
        i = i + 3;
        j = j - 5;
    }
    return 0;
}