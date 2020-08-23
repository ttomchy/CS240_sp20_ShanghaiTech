#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

class Graph {
    private:
        int link[40001];
    public:
        vector<int> graph[40001];
        int numOfNodes;
        int nodeId[201][201];
        bool obstacle[201][201];
        int visited[40001];
        Graph();
        bool find(int u);
        void addEdge(int u, int v);
        void addEdges(int x, int y);

};

Graph :: Graph() {
    memset(obstacle, 0, sizeof(obstacle));
    memset(link, 0, sizeof(link));
}

bool Graph :: find(int u) {
    bool flag = 0;
    for(int i = 0; i < graph[u].size(); i++) {
        int tmp = graph[u][i];
        if(!visited[tmp]) {
            visited[tmp] = 1;
            if(!link[tmp] || find(link[tmp])) {
                link[tmp] = u;
                flag = 1;
                break;
            }
        }
    }
    return flag;
}

void Graph :: addEdge(int u, int v) {
    graph[u].push_back(v);
}

void Graph :: addEdges(int x, int y) {
    if (x + 1 >= 1 && y + 2 >= 1 && x + 1 <= numOfNodes && y + 2 <= numOfNodes && !obstacle[x + 1][y + 2] ) {
        addEdge(nodeId[x][y], nodeId[x + 1][y + 2]);
    }
    if (x + 1 >= 1 && y - 2 >= 1 && x + 1 <= numOfNodes && y - 2 <= numOfNodes && !obstacle[x + 1][y - 2] ) {
        addEdge(nodeId[x][y], nodeId[x + 1][y - 2]);
    }
    if (x - 1 >= 1 && y + 2 >= 1 && x - 1 <= numOfNodes && y + 2 <= numOfNodes && !obstacle[x - 1][y + 2] ) {
        addEdge(nodeId[x][y], nodeId[x - 1][y + 2]);
    }
    if (x - 1 >= 1 && y - 2 >= 1 && x - 1 <= numOfNodes && y - 2 <= numOfNodes && !obstacle[x - 1][y - 2] ) {
        addEdge(nodeId[x][y], nodeId[x - 1][y - 2]);
    }
    if (x + 2 >= 1 && y + 1 >= 1 && x + 2 <= numOfNodes && y + 1 <= numOfNodes && !obstacle[x + 2][y + 1] ) {
        addEdge(nodeId[x][y], nodeId[x + 2][y + 1]);
    }
    if (x + 2 >= 1 && y - 1 >= 1 && x + 2 <= numOfNodes && y - 1 <= numOfNodes && !obstacle[x + 2][y - 1] ) {
        addEdge(nodeId[x][y], nodeId[x + 2][y - 1]);
    }
    if (x - 2 >= 1 && y + 1 >= 1 && x - 2 <= numOfNodes && y + 1 <= numOfNodes && !obstacle[x - 2][y + 1] ) {
        addEdge(nodeId[x][y], nodeId[x - 2][y + 1]);
    }
    if (x - 2 >= 1 && y - 1 >= 1 && x - 2 <= numOfNodes && y - 1 <= numOfNodes && !obstacle[x - 2][y - 1] ) {
        addEdge(nodeId[x][y], nodeId[x - 2][y - 1]);
    }
}

int main() {
    int numOfObstacles;
    Graph knight;
    cin >> knight.numOfNodes >> numOfObstacles;
    int x, y;
    for (int i = 0; i < numOfObstacles; i++) {
        cin >> x >> y;
        knight.obstacle[x][y] = 1;
    }
    int num = 1;
    for (int i = 1; i < knight.numOfNodes + 1; i++) {
        for (int j = 1; j < knight.numOfNodes + 1; j++) {
            knight.nodeId[i][j] = num;
            num++;
        }
    }
    int odd = knight.numOfNodes % 2;
    if (odd == 1) {
            for (int i = 1; i < knight.numOfNodes + 1; i++) {
                for (int j = 1; j < knight.numOfNodes + 1; j++) {
                    if (!knight.obstacle[i][j] && knight.nodeId[i][j] % 2 != 0) {
                        knight.addEdges(i, j);
                    }
                }
            }
    }
    else {
        for (int i = 1; i < knight.numOfNodes + 1; i++) {
            for (int j = 1; j < knight.numOfNodes + 1; j++) {
                if (i % 2 == 1) {
                    if (!knight.obstacle[i][j] && knight.nodeId[i][j] % 2 != 0) {
                        knight.addEdges(i, j);
                    }
                }
                else {
                    if (!knight.obstacle[i][j] && knight.nodeId[i][j] % 2 == 0) {
                        knight.addEdges(i, j);
                    } 
                }
            }
        }      
    }
    int ans = 0;
    for(int i = 1; i < knight.numOfNodes * knight.numOfNodes + 1; i++) {
        memset(knight.visited, 0, sizeof(knight.visited));
        int flag = knight.find(i);
        if(flag) {
            ans++;
        }
    }
    ans = knight.numOfNodes * knight.numOfNodes - numOfObstacles - ans;
    cout << ans;
    return 0;
}