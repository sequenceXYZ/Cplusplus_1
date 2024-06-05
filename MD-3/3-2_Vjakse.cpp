#include <iostream>
#include <algorithm>

using namespace std;

// Definejam attela izmerus
const int N = 6;
const int M = 9;

// DFS funkcija, lai atrastu figuras laukumu
int dfs(int grid[N][M], bool visited[N][M], int x, int y) {
    // Parbauda, vai koordinatas ir derigas un vai rutinja nav tuksa vai ir jau apmekleta
    if (x < 0 || y < 0 || x >= N || y >= M || grid[x][y] == 0 || visited[x][y]) {
        return 0;
    }

    visited[x][y] = true; // Atzime ka apmekletu
    int area = 1; // Sakuma laukums ir 1 (jo si rutina pieder figurai)

    // Iespējamie virzieni (uz augsu, uz leju, pa kreisi, pa labi)
    area += dfs(grid, visited, x + 1, y);
    area += dfs(grid, visited, x - 1, y);
    area += dfs(grid, visited, x, y + 1);
    area += dfs(grid, visited, x, y - 1);

    return area; // Atgriez laukumu
}

int main() {
    // Piemera rezgis no attela
    int grid[N][M] = {
        {1, 1, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 0, 0, 1, 1, 1, 0, 0},
        {0, 1, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 1, 1, 0, 0},
        {0, 0, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0}
    };

    // Izveido apmekletu rutiņu rezgii un to inicializa ka "neapmeklets"
    bool visited[N][M] = { false };

    int maxArea = 0; // Sākotnēji lielākais laukums ir 0

    // apmekle visas rutinas
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            // Ja rutina ir nokrasota un nav apmeklata, sāk DFS funkciju
            if (grid[i][j] == 1 && !visited[i][j]) {
                maxArea = max(maxArea, dfs(grid, visited, i, j)); // Atjaunina lielako laukumu
            }
        }
    }

    // Izdruka lielako figuru
    cout << "Lielakas figuras laukums ir: " << maxArea << endl;

    return 0;
}

// https://stackoverflow.com/questions/10670301/find-the-maximum-possible-area
// https://stackoverflow.com/questions/15705490/find-largest-area-in-2d-array-in-c
