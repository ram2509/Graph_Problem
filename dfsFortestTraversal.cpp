#include<iostream>
#include<map>
#include<list>
using namespace std;

template<typename T>
class Graph{
   map<T,list<T> > adjList;

   public :

       Graph(){ };

       void addEdge(T u,T v,bool bidir){
         adjList[v].push_back(v);
         if(bidir){
            adjList[v].push_back(u);
         }
       }

       void print(){
         for(auto row : adjList){
            T node = row.first;
            cout<<node<<"-->";
            for(auto element : adjList[node]){
                cout<<element<<",";
            }
            cout<<endl;
         }
       }

       void dfsHelper(T node,map<T,bool>&visited){
          visited[node]=true;
          cout<<node<<"-->";
          for(auto neighbour : adjList[node]){
              if(!visited[node]){
                dfsHelper(neighbour,visited);
              }
          }
       }

       void dfs(T src){
         map<T,bool> visited;
         dfsHelper(src,visited);

         int component=1;
         for(auto i : adjList){
            T node = i.first;
            if(!visited[node]){
                dfsHelper(node,visited);
                component++;
            }
         }
       }
};

int main(){
  Graph<string> g;
  g.addEdge("A","J",true);
  g.addEdge("A","D",true);
  g.addEdge("D","C",true);
  g.addEdge("D","B",true);
  g.addEdge("J","M",true);
  g.addEdge("M","B",true);
  g.addEdge("M","K",true);
  g.addEdge("E","F",true);
  g.print();
  g.dfs("A");
  return 0;
}
