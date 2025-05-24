#include "Graph.h"

int main()
{
    Graph g(6);
    g.addEdge(0, 2, 13); // 1 -> 3
    g.addEdge(0, 3, 15); // 1 -> 4
    g.addEdge(0, 5, 18); // 1 -> 6
    g.addEdge(1, 3, 20); // 2 -> 4
    g.addEdge(1, 4, 21); // 2 -> 5
    g.addEdge(2, 3, 39); // 3 -> 4
    g.addEdge(2, 4, 30); // 3 -> 5
    g.addEdge(3, 5, 31); // 4 -> 6
    g.addEdge(4, 3, 28); // 5 -> 4

    int choice;
        while (true) {
            cout << "\nChoice:\n"
                 << "1. BFS\n"
                 << "2. DFS\n"
                 << "3. Dijkstra's algorithm\n"
                 << "4. Floyd's Algorithm\n"
                 << "5. Distance matrix\n"
                 << "6. Adjacency matrix\n"
                 << "7. Add a vertex\n"
                 << "8. Delete a vertexу\n"
                 << "9. Add an edge\n"
                 << "10. Delete an edge\n"
                 << "11. Change the edge weightа\n"
                 << "0. Exit\n"
                 << "Enter: ";
            cin >> choice;

            if (choice == 0) break;

            int u, v, w;
            switch (choice) {
                case 1:
                    cout << "The initial vertex (1-N): "; cin >> u;
                    g.BFS(u - 1);
                    break;
                case 2:
                    cout << "The initial vertex (1-N): "; cin >> u;
                    g.DFS(u - 1);
                    break;
                case 3:
                    cout << "The initial vertex (1-N): "; cin >> u;
                    g.dijkstra(u - 1);
                    break;
                case 4:
                    g.floydWarshall();
                    break;
                case 5:
                    g.printDistanceMatrix();
                    break;
                case 6:
                    g.printAdjacencyMatrix();
                    break;
                case 7:
                    g.addVertex();
                    break;
                case 8:
                    cout << "Delete a vertex (1-N): "; cin >> u;
                    g.removeVertex(u - 1);
                    break;
                case 9:
                    cout << "An edge from (1-N): "; cin >> u;
                    cout << "Where (1-N): "; cin >> v;
                    cout << "Weight: "; cin >> w;
                    g.addEdge(u - 1, v - 1, w);
                    break;
                case 10:
                    cout << "Remove an edge from (1-N): "; cin >> u;
                    cout << "Where (1-N): "; cin >> v;
                    g.removeEdge(u - 1, v - 1);
                    break;
                case 11:
                    cout << "An edge from (1-N): "; cin >> u;
                    cout << "Where (1-N): "; cin >> v;
                    cout << "New weight: "; cin >> w;
                    g.changeWeight(u - 1, v - 1, w);
                    break;
                default:
                    cout << "Error\n";
            }
        }

        return 0;
    }
