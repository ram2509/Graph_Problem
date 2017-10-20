///cycle detection in graph using DFS
#include<iostream>
#include<map>
#include<list>
using namespace std;

template<typename T>
class Graph{
  map<T,list<T> > adjList;

  public :
      Graph() { };

      void addEdge(T u,T v,bool bidir){
       adjList[u].push_back(v);
       if(bidir){
        adjList[v].push_back(u);
       }
      }

      bool dfsCycleHelper(T node,map<T,bool>&visited,map<T,T>&parent){
         visited[node]=true;
         for(T neighbour : adjList[node]){
            if(!visited[neighbour]){
                parent[neighbour]=node;
                bool cycle=dfsCycleHelper(neighbour,visited,parent);
            }
            else if(parent[node]!=neighbour){
                return true;
            }
         }
         return false;
      }

      bool dfs(){
        map<T,bool> visited;
        map<T,T> parent;
        for(auto row : adjList){
            T node = row.first;
          if(!visited[node]){
            bool cycleResult = dfsCycleHelper(node,visited,parent);
            cout<<cycleResult;
      }
}
}
};


int main(){
   Graph<int> g;
   g.addEdge(0,1,true);
   g.dfs();
   return 0;
}


