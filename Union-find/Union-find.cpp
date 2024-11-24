#include <iostream>
#include <vector>

class UnionFind {
private:
    std::vector<int> parent; // Родитель каждого элемента
    std::vector<int> rank;   // Ранг дерева для каждого элемента

public:
    // Конструктор: инициализация n элементов
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0); // Изначально все ранги равны 0
        for (int i = 0; i < n; i++) {
            parent[i] = i; // Каждый элемент является своим собственным родителем
        }
    }

    // Поиск с сжатием пути
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Рекурсивное нахождение родителя и сжатие пути
        }
        return parent[x];
    }

    // Метод объединения с использованием рангов
    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            // Присоединяем дерево с меньшим рангом к дереву с большим рангом
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    // Печать родительского массива (для отладки)
    void printParents() {
        for (int i = 0; i < parent.size(); i++) {
            std::cout << "Element: " << i << ", Parent: " << parent[i] << "\n";
        }
    }
};