/*Prim's Algorithm*/
// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;
// const int n1 = 1e9 + 7;
// #define ll long long
// vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
// {
//     // vector<pair<pair<int, int> edge list along with weight
//    //create adjacency list
//    //list of node and weights corresponding to a node
//    unordered_map<int , list<pair<int, int >>> adj;
// //    g.size()  - row size
//    for(int i =0; i< g.size(); i++){
//        //first node
//        int u = g[i].first.first ;
//        int v = g[i].first.second;
//        int w = g[i].second;
//        adj[u].push_back(make_pair(v,w));
//        adj[v].push_back(make_pair(u, w));
//    }
//    vector<int> key(n+1);
//    //vector to represent if the particular node is in mst or not
//    vector<bool>mst(n+1);
//    vector<int> parent(n+1);
//    //initializing the vectors
//    for(int i=0; i< n+1; i++){
//        key[i] = INT_MAX;
//        parent[i] = -1;
//        mst[i] = false;

//    }
//    //algo
//    //marking the source node as 0
//    key[1] = 0;
//    parent[1] = -1;
//    for(int i=0; i< n ;i++){
//        //track minimum
//         int mini = INT_MAX;
//         int u;
//         for(int v =1; v<=n ; v++){
//             //if not in mst and key/weight is less than mini
//             if(mst[v]==false && key[v] < mini){
//                 u =v;
//                 mini = key[v];
//             }
//         }
//         mst[u]  =true;
//         //check its adjacent nodes
//         for(auto it: adj[u]){
//             int v = it.first;
//             int w = it.second;
//             if (mst[v] == false && w < key[v]){
//                 parent[v] = u;
//                 key[v] = w;
//             }
//         }
//    }
//    vector<pair<pair<int, int>, int>>result;
// //    1 based mapping
// for(int i =2; i<=n; i++){
//     result.push_back({{parent[i], i}, key[i]});
// }
// return result;
// }

// int main()
// {
//     // cout<<calculatePrimsMST();
//     return 0;
// }
// A C++ program for Prim's Minimum
// Spanning Tree (MST) algorithm. The program is
// for adjacency matrix representation of the graph

#include <bits/stdc++.h>
using namespace std;
#define V 5

int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void printMST(int parent[], int graph[V][V])
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \t"
             << graph[i][parent[i]] << " \n";
}
void primMST(int graph[V][V])
{
    int parent[V];

    int key[V];

    bool mstSet[V];

    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;

    parent[0] = -1;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet);

        mstSet[u] = true;

        for (int v = 0; v < V; v++)

            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    printMST(parent, graph);
}

int main()
{
    int graph[V][V] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0}};

    // Print the solution
    primMST(graph);

    return 0;
}
