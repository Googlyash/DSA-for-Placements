/*DFS Code*/

#include <bits/stdc++.h>
using namespace std; 
 
template<typename t> 
class graph{ 
  map<t,list<t>> l;
public: 
   
  //Add new Edge in the graph
  void addedge(int x,int y) 
  { 
      l[x].push_back(y); 
      l[y].push_back(x); 
  } 
   
  /*DFS Code Starts here*/ 
  void dfs_helper(t src,map<t,bool>&vis) 
  { 
      cout<<src<<" "; 
      vis[src]=1; 
      for(t nbr:l [src]) 
      { 
          if(!vis[nbr]) 
          { 
              dfs_helper(nbr,vis); 
          } 
      } 
  } 
   
  void dfs(t src) 
  { 
      map<t,bool> vis; 
       
      for(auto p:l) 
      { 
          t node=p.first; 
          vis[node]=0; 
      } 
      dfs_helper(src,vis); 
  } 
/*DFS Code ends here*/ 
  
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
    return 0; 
}
