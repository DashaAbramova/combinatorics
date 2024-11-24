#include <iostream>
#include <vector>

// Класс для реализации Union-Find
class UnionFind {
private:
    std::vector<int> parent; // Хранит родителя каждого элемента
    std::vector<int> rank;   // Хранит ранг (высоту) дерева для баланса

public:
    // Конструктор: инициализация элементов
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i; // Изначально каждый элемент является своим собственным родителем
        }
    }

    // Метод Find с сжатием путей
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Рекурсивное обновление родителя
        }
        return parent[x];
    }

    // Метод Union с ранговой эвристикой
    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    // Метод для проверки, принадлежат ли два элемента одному множеству
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

