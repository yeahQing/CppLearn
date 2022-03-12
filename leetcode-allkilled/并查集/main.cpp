#include <iostream>

using namespace std;

/**
 *
 * @name find_root
 * @param x
 * @param parent
 */
int find_root(int x, int parent[])
{
    int x_root = x;
    while (parent[x_root] != -1)
    {
        x_root = parent[x_root]; // 如果当前的节点不是父节点, 那么当前节点就变为它的父节点
    }

    return x_root;
}

/**
 *
 * @name union_verticles
 * @param x
 * @param y
 * @param parent
 *
 */
int union_verticles(int x, int y, int parent[], int rank[])
{
    int x_root = find_root(x, parent); // 找到x节点的父节点
    int y_root = find_root(y, parent); // 找到y节点的父节点

    // 如果父节点相同，则表示图中有环
    if (x_root == y_root)
    {
        return 0;
    }
    else
    {
        if (rank[y_root] > rank[x_root])
        {
            parent[x_root] = y_root;
        }
        else if (rank[y_root] < rank[x_root])
        {
            parent[y_root] = x_root;
        }
        else
        {
            rank[y_root]++; // 让y成为新的根，拔高他的高度
            // 将x_root的父节点变为y_root
            parent[x_root] = y_root;
        }
    }
    return 1;
}

/**
 * 
 * @name initializa_parent
 * @param parent
 * @param size
 * 
*/
void initialize_parent(int parent[], int size)
{
    for (int i = 0; i < size; i++)
        parent[i] = -1;
}


int main()
{
    int maxn;
    int n; 
    int parent[n] = {0};
    int rank[n]   = {0}; // 树的高度
    cin >> n >> maxn;
    initialize_parent(parent, n);
    int edges[maxn][2];

    for (int i = 0; i < maxn; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
        int x = edges[i][0]; int y = edges[i][1];
        if (!union_verticles(x, y, parent, rank))
        {
            printf("Cycle detected!\n");
            exit(0);
        }
    }

    printf("No Cycle found!\n");

    return 0;
}