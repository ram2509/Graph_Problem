#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;

template<typename T>
class Topology{
   map<T,list<T> > adjList;

   public :
       Topology(){}

       void addEdge(T u,T v,bool bidir){
         adjList[u].push_back(v);
         if(bidir){
            adjList[v].push_back(u);
         }
       }

       void print(){
         for(auto row : adjList){
            T node = row.first;
            cout<<node<<"->";
            for(auto neighbour : adjList[node]){
                cout<<neighbour<<",";
            }
            cout<<endl;
         }
         cout<<endl;
       }

       void bfsTopology(){
         map<T,bool> visited;
         map<T,int> indegree;
         queue<T> q;

         for(auto row : adjList){
           T node = row.first;
           indegree[node]=0;
           visited[node]=false;
         }

         ///count the indegree of each vertex
         for(auto row : adjList){
            T node = row.first;
            for(auto neighbour : adjList[node]){
                indegree[neighbour]++;
            }
         }

         ///push the vertex into queue whose indegree is zero
         for(auto row : adjList){
            T node = row.first;
            if(indegree[node]==0){
                q.push(node);
            }
         }

         while(!q.empty()){
            T i = q.front();
            q.pop();
            cout<<i<<"-->";
            for(T neighbour : adjList[i]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0){
                    q.push(neighbour);
                }
            }
         }
}
};

int main(){
Topology<int> t;
  t.addEdge(0,2,false);
  t.addEdge(1,2,false);
  t.addEdge(1,4,false);
  t.addEdge(2,3,false);
  t.addEdge(3,5,false);
  t.addEdge(4,5,false);
  t.print();
  t.bfsTopology();
  return 0;
}
