/*BFS Code*/ 
 
#include <bits/stdc++.h>
using namespace std; 
 
template<typename t> 
class graph{ 
  map<t,list<t>> l;
public: 
   
  void addedge(int x,int y) 
  { 
      l[x].push_back(y); 
      l[y].push_back(x); 
  } 
   
/*BFS Code Starts here*/ 
  void bfs(t src){ 
      queue<t> q; 
      map<t,bool>vis; 
       
      q.push(src); 
      vis[src]=1; 
       
      while(!q.empty()) 
      { 
          t node=q.front(); 
          q.pop(); 
          cout<<node<<" "; 
          for(int nbr:l[node]) 
          { 
              if(!vis[nbr]) 
              { 
                  q.push(nbr); 
                  vis[nbr]=1; 
              } 
          } 
      } 
  } 
  /*BFS Code ends here*/ 
 
}; 
 
int main() 
{ 
    graph<int> g; 
    g.addedge(0,1); 
    g.addedge(1,2); 
    g.addedge(0,3); 
    g.addedge(2,3); 
    g.addedge(3,4); 
    g.addedge(4,5); 
     
    g.dfs(0); 
    cout<<"\n"; 
    g.bfs(0); 
    return 0; 
}
