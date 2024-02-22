#include<iostream>
using namespace std;
int miniDist(int distance[], bool Tset[]) // finding minimum distance
{
int minimum=INT_MAX,ind;
for(int k=0;k<9;k++)
{
if(Tset[k]==false && distance[k]<=minimum)
{
minimum=distance[k];
ind=k;
}
}
return ind;
}
void DijkstraAlgo(int graph[9][9],int src) // adjacency matrix
{
int distance[9]; 
bool Tset[9];
for(int k = 0; k<9; k++)
{
distance[k] = INT_MAX;
Tset[k] = false;
}
distance[src] = 0;
for(int k = 0; k<9; k++)
{
int m=miniDist(distance,Tset);
Tset[m]=true;
for(int k = 0; k<9; k++)
{
if(!Tset[k] && graph[m][k] && distance[m]!=INT_MAX &&
distance[m]+graph[m][k]<distance[k])
distance[k]=distance[m]+graph[m][k];
}
}
cout<<"Vertex\t\tDistance from source vertex"<<endl;
for(int k = 0; k<9; k++)
{
//char str=65+k;
cout<<k<<"\t\t\t"<<distance[k]<<endl;
}
}
int main()
{
int graph[9][9]={       { 0, 4, 0, 0, 0, 0, 0, 8, 0  },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2  },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0,0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6  },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0  }     };

             DijkstraAlgo(graph,0);
return 0;
}