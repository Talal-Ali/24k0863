#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include "Graphs.h"
#include "Queue.h"
using namespace std;

class Dijkstra {
    public:
        void shortestPath(Graph& g, const string& srcName) {
        int n = g.getCityCount();
        if (n == 0) return;

        int src = g.findCity(srcName);
        if (src == -1) {
            cout << "Source city not found: " << srcName << "\n";
            return;
        }

        const int INF = numeric_limits<int>::max();
        vector<int> dist(n, INF);
        vector<int> parent(n, -1);
        vector<bool> visited(n, false);

        
        PriorityQueue pq;
        dist[src] = 0;
        pq.pqenqueue(src, 0);

        while (!pq.pqisEmpty()) {
            int u = pq.pqdequeue();      
            if (u < 0 || u >= n) continue;

            if (visited[u]) continue;
            visited[u] = true;

            for (int v = 0; v < n; ++v) {
                int w = g.adj[u][v]; 
                if (w == -1) continue;
                if (visited[v]) continue;
                if (dist[u] == INF) continue;

                int nd = dist[u] + w;
                if (nd < dist[v]) {
                    dist[v] = nd;
                    parent[v] = u;
                    pq.pqenqueue(v, nd);
                }
            }
        }

        printResults(dist, parent, g, src);
    }

    private:
        void printResults(vector<int>& dist, vector<int>& parent, Graph& g, int src) {
            for (int i = 0; i < (int)dist.size(); i++) {
                cout << "\nTo " << g.getCityName(i) << ": ";
                if (dist[i] == INT_MAX) {
                    cout << "No path\n";
                    continue;
                }
                cout << dist[i] << " km via ";
                printPath(i, parent, g);
                cout << "\n";
            }
        }

        void printPath(int v, vector<int>& parent, Graph& g) {
            if (parent[v] == -1) {
                cout << g.getCityName(v);
                return;
            }
            printPath(parent[v], parent, g);
            cout << " -> " << g.getCityName(v);
    }
};