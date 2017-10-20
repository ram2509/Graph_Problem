///cycle detection in directed graph using DFS

#include<iostream>
#include<list>
#include<map>
using namespace std;

template<typename T>
class Graph{
  map<T,list<T>> adjList;
  public :
      Graph(){}

      void addEdge(T u, T v, bool bidir){
         adjList[u].push_back(v);
         if(bidir){
            adjList[v].push_back(u);
         }
      }

      bool dfsCycleDetection(T node,map<T,bool>&visited,map<T,bool>&inStack){
         visited[node]=true;
         inStack[node]=true;
         for(auto neighbour : adjList[node]){
            if((!visited[neighbour] && dfsCycleDetection(neighbour,visited,inStack))|| inStack[neighbour]){
                return true;
            }
         }
         inStack[node]=false;
         return false;

      }

      bool dfs(){
         map<T,bool>visited;
         map<T,bool>inStack;
         for(auto row : adjList){
            T node = row.first;
            if(!visited[node]){
                bool cyclePresent = dfsCycleDetection(node,visited,inStack);
                cout<<cyclePresent;
                return cyclePresent;
            }
         }
      }
};
int main(){
   Graph<int> g;
   g.addEdge(0,1,false);
   g.addEdge(1,2,false);
   g.addEdge(2,1,false);
  /* g.addEdge(1,5,false);
   g.addEdge(2,4,false);
   g.addEdge(4,5,false);
   g.addEdge(2,3,false);
   g.addEdge(3,0,false);*/
   g.dfs();
   //cout<<"Is Cycle present in the graph";
   //if(g.dfs()){
     // cout<<"Haa hai";
   //}
   //else{
    //cout<<"Nhi hai";
   //}
  return 0;
}
