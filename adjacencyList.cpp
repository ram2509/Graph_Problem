#include<iostream>
<<<<<<< HEAD
#include<map>
#include<list>
#include<queue>
using namespace std;

template<typename T>
class Graph{
  map<T,list<T> > adjList;
  //map<T,int> distance ;
  public :
      Graph(){ };

      void addEdge(T u, T v, bool bidir){
       adjList[u].push_back(v);
       if(bidir){
        adjList[v].push_back(u);
       }
      }

      void printList(){
       for(auto row : adjList){
           T node = row.first;
           //distance.first=node;
           //distance.second=0;
           cout<<node<<"-->";
           for(auto neighbour : row.second){
                 cout<<neighbour<<",";
           }
           cout<<endl;
       }
       cout<<endl;
      }

      void bfs(T src){
        //int cnt=1;
        map<T,bool> visited;
        queue<T> q;
        q.push(src);
        visited[src]=true;
        while(!q.empty()){
            T node = q.front();
            cout<<node<<"-->";
            q.pop();
            for(T neighbour : adjList[node]){
                if(!visited[neighbour]){
                    visited[neighbour]=true;
                    q.push(neighbour);
                    //distance[neighbour]=1+distance[node];
                }
            }
        }
        cout<<endl;
        //cout<<cnt<<endl;
        //cout<<"Shortest Distance"<<distance[dest];
      }
};

int main(){
  /**Graph<string> g;
  g.addEdge("A","S",true);
  g.addEdge("S","D",true);
  g.addEdge("A","J",true);
  g.addEdge("A","D",true);
  g.addEdge("J","B",true);
  g.addEdge("D","B",true);
  g.addEdge("D","L",true);**/
  Graph<int> g;
  g.addEdge(0,1,true);
  g.addEdge(0,4,true);
  g.addEdge(1,2,true);
  g.addEdge(2,4,true);
  g.addEdge(2,3,true);
  g.addEdge(3,5,true);
  g.printList();
  cout<<"BFS traversal of Graph is"<<endl;
  g.bfs(0);
=======
#include<list>
using namespace std;

class AdjacencyList{
   int V;
   list<int> *adjList;

   public :
       AdjacencyList(int v){
         V = v;
         adjList = new list<int>[V];
       }

       void addEdge(int u,int v,bool bidir=true){
        adjList[u].push_back(v);
        if(bidir){
            adjList[v].push_back(u);
        }
       }

       void printAdjList(){
        ///iterative over all element array
        for(int i=0;i<V;i++){
            cout<<i<<"->";
            for(int vertex:adjList[i]){
                cout<<vertex<<",";
            }
            cout<<endl;
        }
       }
};

int main(){
  AdjacencyList a(5);
  a.addEdge(0,1);
  a.addEdge(0,4);
  a.addEdge(1,4);
  a.addEdge(1,3);
  a.addEdge(1,2);
  a.addEdge(2,3);
  a.addEdge(3,4);
  a.printAdjList();
>>>>>>> 0331590432498543fd3659e2a26642c3f1b1a714
  return 0;
}
