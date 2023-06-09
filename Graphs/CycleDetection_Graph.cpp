/*Cycle detection in graph*/

/*going through node to node (except the parent node)  and checking if visited again or not! */


#include <bits/stdc++.h> 
using namespace std; 
 
class graph{ 
  int v; 
  list<int> *l; 
   
public: 
   graph(int v){ 
       this->v=v; 
       l = new list<int>[v]; 
   } 
  void addedge(int x,int y, bool dir=true) 
  { 
      l[x].push_back(y); 
      if(!dir) 
      { 
        l[y].push_back(x); 
      } 
  } 
   
  bool cycle_helper(int node, bool* vis, int parent) 
  { 
      vis[node]=true; 
       
      for(auto nbr:l[node]) 
      { 
          //Two cases 
          if(!vis[nbr]){ 
              //go and recurdively visit the nbr 
              bool cycle_mila=cycle_helper(nbr,vis,node); 
              if(cycle_mila)return true; 
          } 
          //nbr is visited but nbr should not be equal to parent 
          else if(nbr!=parent){ 
              return true; 
          } 
      } 
      return 0; 
  } 
   
  bool contains_cycle(){ 
      bool *vis= new bool[v]; 
      for(int i=0;i<v;i++) 
      { 
          vis[i]=false; 
      } 
      return cycle_helper(0,vis,-1); 
  } 
 
}; 
 
int main() 
{ 
    graph g(6); 
    g.addedge(0,1); 
    g.addedge(1,2); 
    g.addedge(2,3); 
  //g.addedge(0,3);      Uncomment to see cycle present
    g.addedge(3,4); 
    g.addedge(4,5); 
     
    if(g.contains_cycle()) 
    { 
        cout<<"cycle present\n"; 
    } 
    else { 
        cout<<"Cycle not present\n"; 
    } 
    return 0; 
}


/*    
     2-------1                                        2------1
     |       |                                        |      |
     |       |                                        |      |
     3       0    =====> No Cycle                     3------0    ====>Cycle Present
     |                                                |
     |                                                |
     4-------5                                        4------5
     
                                HAPPY CODING :)
*/
