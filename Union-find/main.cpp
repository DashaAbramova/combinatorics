#include <iostream>
#include "Union-find.cpp"

int main() {
    int n = 10; // Количество элементов
    UnionFind uf(n);

    // Пример объединений
    uf.unionSets(1, 2);
    uf.unionSets(2, 3);
    uf.unionSets(4, 5);
    uf.unionSets(6, 7);
    uf.unionSets(3, 7); // Объединение двух больших компонент

    // Проверка принадлежности элементов к одному множеству
    std::cout << "Find(1): " << uf.find(1) << "\n";
    std::cout << "Find(7): " << uf.find(7) << "\n";

    // Проверка объединения 1 и 7
    if (uf.find(1) == uf.find(7)) {
        std::cout << "1 и 7 принадлежат одному множеству.\n";
    } else {
        std::cout << "1 и 7 принадлежат разным множествам.\n";
    }

    // Печать родительского массива
    std::cout << "Родительский массив:\n";
    uf.printParents();

    return 0;
}