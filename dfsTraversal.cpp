#include<iostream>
#include<map>
#include<list>
using namespace std;

template<typename T>
class Graph{
  map<T, list<T> > adjList;

  public :
      Graph() { };

      void addEdge(T u,T v,bool bidir){
       adjList[u].push_back(v);
       if(bidir){
         adjList[v].push_back(u);
       }
      }

      void dfsHelper(T node, map<T,bool>&visited){
         visited[node]=true;
         cout<<node<<"-->";
         for(auto neighbour : adjList[node]){
          if(!visited[neighbour]){
             dfsHelper(neighbour,visited);
          }
       }
      }

      void dfs(T src){
       map<T,bool> visited;
       dfsHelper(src,visited);
      }
};

int main(){
  Graph<string> g;
  g.addEdge("A","S",true);
  g.addEdge("S","D",true);
  g.addEdge("A","J",true);
  g.addEdge("A","D",true);
  g.addEdge("J","B",true);
  g.addEdge("D","B",true);
  g.addEdge("D","L",true);
  g.dfs("A");
  return 0;
}
