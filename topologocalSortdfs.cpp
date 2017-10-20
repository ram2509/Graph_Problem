#include<iostream>
#include<map>
#include<list>
using namespace std;

template<typename T>
class Topology{
   map<T,list<T> > adjList;

   public :

       Topology(){ }

       void addEdge(T u,T v,bool bidir){
         adjList[u].push_back(v);
         if(bidir){
            adjList[v].push_back(u);
         }
       }

       void dfstopologicalHelper(T node,map<T,bool>&visited,list<T>&ordering){
         visited[node]=true;
         for(auto neighbour:adjList[node]){
            if(!visited[neighbour]){
                dfstopologicalHelper(neighbour,visited,ordering);
            }
         }
         cout<<node<<"-->";
         ordering.push_front(node);
       }

       void dfstopological(){
        map<T,bool> visited;
        list<T> ordering;
        for(auto row : adjList){
            T node = row.first;
            if(!visited[node]){
                dfstopologicalHelper(node,visited,ordering);
            }
        }
        cout<<endl;
        while(!ordering.empty()){
          T i = ordering.front();
          cout<<i<<"-->";
        }
       }
};

int main(){
  Topology<int> t;
  t.addEdge(1,2,false);
  t.addEdge(1,3,false);
  t.addEdge(2,4,false);
  t.addEdge(3,4,false);
  t.dfstopological();
  return 0;
}
