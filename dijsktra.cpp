#include <iostream>
#include <limits>
using namespace std;

const int infinite = numeric_limits<int>::max();
int minind(int dis[],bool visited[],int tot) 
{
    int minimum = infinite, mind = -1;
    for (int i = 0; i < tot; i++) 
    {
        if (visited[i]==false && dis[i] < minimum) 
        {
            minimum = dis[i];
            mind = i;
        }
    }
    return mind;
}

int mindis(int graph[100][100],int start,int end,int tot) 
{
    int dist[100];
    bool visited[100];
    for (int i = 0; i < tot; i++) 
    {
        dist[i] = infinite;
        visited[i] = false;
    }
    dist[start] = 0;  
    for (int i = 0; i < tot-1; i++) 
    {
        int curr = minind(dist,visited,tot);
        visited[curr] = true;
        for (int adj = 0; adj < tot; adj++) 
        {
            if(visited[adj]==false && graph[curr][adj]!=0 && dist[curr] != infinite)
            {
                if(dist[curr] + graph[curr][adj] < dist[adj]) 
                {
                    dist[adj] = dist[curr] + graph[curr][adj];
                }
            }
        }
    }
    return dist[end];
}



int main() 
{
    int start,end,tot;
    cout << "Total Nodes: ";
    cin >> tot;
    int graph[100][100];
    for (int i = 0; i < tot; i++) 
    {
        for (int j = 0; j < tot; j++) 
        {
            cin >> graph[i][j];
        }
    }
    cout << "Staring Node: ";
    cin >> start;
    cout << "Ending Node: ";
    cin >> end;
    cout<<mindis(graph,start,end,tot);
    return 0;
}
