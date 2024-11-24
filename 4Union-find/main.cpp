#include <iostream>
#include <vector>
#include "4Union-find.cpp"


int main() {
    int n = 6; // Количество элементов
    UnionFind uf(n);

    // Примеры операций
    uf.unionSets(1, 2);
    uf.unionSets(2, 3);
    uf.unionSets(4, 5);

    std::cout << "Are 1 and 3 connected? " << (uf.connected(1, 3) ? "Yes" : "No") << std::endl;
    std:: cout << "Are 3 and 4 connected? " << (uf.connected(3, 4) ? "Yes" : "No") << std::endl;

    uf.unionSets(1, 4);
    std::cout << "Are 3 and 4 connected after union? " << (uf.connected(3, 4) ? "Yes" : "No") << std::endl;

    return 0;
}
