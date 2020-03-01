// Обход графа в ширину (breadth-first search)
// Граф задается в виде списка смежности

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(vector<vector<int>>&, int&, int&);

int main() {
    vector<vector<int>> G {
        {1, 2, 5, 6, 7},
        {0, 7},
        {0, 7},
        {4, 5},
        {3, 5, 6, 7},
        {0, 3, 4},
        {0, 4},
        {0, 1, 2, 4}
    };
    int start, finish; // стартовая и конечная вершины
    cout << "Enter start node => "; cin >> start;
    cout << "Enter finish node => ";  cin >> finish;
    BFS(G, start, finish);
    return 0;
}

void BFS(vector<vector<int>>& myG, int& s, int& fin) {
    size_t n = myG.size(); // число вершин

    queue<int> Q;
    Q.push(s);

    vector<bool> used(n, false);
    used[s] = true;

    vector<int> D(n);   //вектор длин путей

    vector<int> P(n);   //вектор предков для вывода маршрута
    P[s] = -1;

    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (size_t i = 0; i < myG[v].size(); ++i) {
            int to = myG[v][i];
            if (!used[to]) {
                used[to] = true;
                Q.push(to);
                D[to] = D[v] + 1;
                P[to] = v;
            }
        }
    }

    if (!used[fin])
        cout << "Path not exists!";
    else {
        vector<int> path;
        while (fin != -1) {
            path.push_back(fin);
            fin = P[fin];
        }
        auto first = path.crbegin();
        auto last = path.crend();
        cout << "Path: ";
        while (first != last)
            cout << *first++ << " ";
    }
}