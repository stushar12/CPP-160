#include <bits/stdc++.h>
using namespace std;
# define N 1000
vector<int> gr[N];
int n = 36;


void Add_edge(int x, int y)
{
	gr[x].push_back(y);
}


map<int,int> bfs(int source,int parent[])
{	
    parent[source]=source;
    map<int,int> distance;
    for(int i=0;i<=n;i++)
    {
        distance[i]=-1;
    }
    distance[source]=0;

    queue<int> q;
    q.push(source);

    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(int x: gr[node])
        {
            if(distance[x]==-1)
            {
                q.push(x);
                parent[x]=node;
                distance[x]=distance[node]+1;
            }

        }
    }
return distance;
}

int main()
{
int parent[n]={0};
map<int,int> distance;
int board[50]={0};

board[2]=13;
board[5]=2;
board[9]=18;
board[18]=11;
board[17]=-13;
board[20]=-14;
board[24]=-8;
board[25]=10;
board[32]=-2;
board[34]=-22;


//Add edge
for(int i=0;i<=36;i++)
{
    for(int dice=1;dice<=6;dice++)
    {
        int j=i+dice;
        j=j+board[j];

        if(j<=36)
        Add_edge(i,j);
    }   
}
Add_edge(36,36);

int source=0;
int destination=36;
distance=bfs(source,parent);

cout<<"Distance between source  "<<source<<" and destination "<<destination <<" is : "<<distance[destination]<<endl;
cout<<"Path is: ";
int temp=destination;
while(temp!=source) 
{   
    cout<<temp<<"<--";
    temp=parent[temp];
}
cout<<source;

}
