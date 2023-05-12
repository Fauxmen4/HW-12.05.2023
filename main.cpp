#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 1000;

vector<int> graph[MAXN];
int match[MAXN];
bool used[MAXN];

bool dfs(int v) {
    used[v] = true;
    for (int i = 0; i < graph[v].size(); i++) {
        int u = graph[v][i];
        int w = match[u];
        if (w == -1 || (!used[w] && dfs(w))) {
            match[u] = v;
            return true;
        }
    }
    return false;
}

int kuhn(int n) {
    memset(match, -1, sizeof(match));
    int cnt = 0;
    for (int v = 0; v < n; v++) {
        memset(used, false, sizeof(used));
        if (dfs(v)) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int n, m;
    n = 8;
    m = 15;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int ans = kuhn(n);

    cout << "Matching: ";
    for (int i = 0; i < n; i++) {
        if (match[i] != -1) {
            cout << i << "-" << match[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
