//學號:B073040022
//姓名:張浩綸
#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
class Node{
    public:
        int number;//node name
        Node* link;//next node
        Node():number(0), link(nullptr){}
        Node(int number):number(number), link(nullptr){}
};
class Graph{
    public:
        int nodeNum;
        vector<int>* list = new vector<int>[nodeNum];//adjacency list
        Graph(int nodeNum):nodeNum(nodeNum){}
        void addChild(int p, int c);
        bool isCyclic(int v, bool* visited, bool *recStack);
        bool hasCycle();
};
void Graph::addChild(int p, int c){
    list[p].push_back(c);
}
bool Graph::isCyclic(int v, bool* visited, bool *recStack){ 
    if(visited[v] == false){ 
        // Mark the current node as visited and part of recursion stack 
        visited[v] = true; 
        recStack[v] = true; 
  
        // Recur for all the vertices adjacent to this vertex 
        vector<int>::iterator i; 
        for(i = list[v].begin(); i != list[v].end(); ++i){ 
            if (!visited[*i] && isCyclic(*i, visited, recStack) ) 
                return true; 
            else if (recStack[*i]) 
                return true; 
        } 
    } 
    recStack[v] = false;  // remove the vertex from recursion stack 
    return false; 
} 
  
// Returns true if the graph contains a cycle, else false. 
bool Graph::hasCycle(){ 
    // Mark all the vertices as not visited and not part of recursion
    // stack
    bool *visited = new bool[nodeNum];
    bool *recStack = new bool[nodeNum];
    for(int i = 0; i < nodeNum; i++){
        visited[i] = false;
        recStack[i] = false;
    }
    // Call the recursive helper function to detect cycle in different
    // DFS trees
    for(int i = 0; i < nodeNum; i++)
        if (isCyclic(i, visited, recStack))
            return true;
    return false;
}
int main(){
    int nodeNum;
    cin >> nodeNum;
    if(nodeNum < 0){
        cout << "Wrong Input\n";
        return 0;
    }
    else if(nodeNum == 0){
        cout << "There isn’t any cycle in the graph.\n";
        return 0;
    }
    Graph g(nodeNum);
    for(int i = 0; i < nodeNum; i++){//all node
        int childNum;
        cin >> childNum;
        if(childNum < 0 || childNum > nodeNum){
            cout << "Wrong Input\n";
            return 0;
        }
        else if(childNum == 0);
        else{
            for(int j = 0; j < childNum; j++){//add all children
                int child;
                cin >> child;
                g.addChild(i, child);
            }
        }
    }
    //start judge
    if(g.hasCycle())
        cout << "There is at least one cycle in the graph.\n";
    else
        cout << "There isn’t any cycle in the graph.\n";
    return 0;
}
