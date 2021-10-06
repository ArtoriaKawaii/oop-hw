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
        int childNum;
        Node* link;//next node
        Node():number(0), childNum(0), link(nullptr){}
        Node(int number):number(number), childNum(0), link(nullptr){}
        void addChild(vector<Node*>& graph, int child);
};
void addChild(vector<Node*>& graph,int parent, int child){
    //add child to the back of adjacency list
    Node* newNode = new Node(child);
    Node* pisition = graph.at(parent);
    while(pisition->link != nullptr)
        pisition = pisition->link;
    pisition->link = newNode;
}
bool findCycle(const vector<Node*>& graph, int start, Node* link, int pathNodeNums){
    //the total vertex numbers of a path > total vertex numbers -> at least one cycle
    if(pathNodeNums > graph.size())
        return true;
    //no child -> no cycle
    if(graph[start]->childNum == 0){
        return false;
    }
    //link is the link points to current vertex
    else if(link == nullptr){
        return false;
    }
    //the current vertex in the linked list is the target
    else if(link->number == start)
        return true;
    else{
        //change to next linked list
        if(findCycle(graph, start, graph[link->number]->link, pathNodeNums+1))
            return true;
        //a cycle in a linked list
        else
            return findCycle(graph, start, link->link, pathNodeNums+1);
    }
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
    vector<Node*> graph;
    for(int i = 0; i < nodeNum; i++){//all node
        graph.push_back(new Node(i));
        int childNum;
        cin >> childNum;
        if(childNum < 0 || childNum > nodeNum){
            cout << "Wrong Input\n";
            return 0;
        }
        else if(childNum == 0);
        else{
            graph.at(i)->childNum = childNum;
            for(int j = 0; j < childNum; j++){//add all children
                int child;
                cin >> child;
                if(child >= nodeNum || child < 0){
                    cout << "Wrong Input\n";
                    return 0;
                }
                addChild(graph, i, child);
            }
        }
    }
    //start find
    bool findFlag = false;
    for(int i = 0; i < nodeNum; i++){
        findFlag = findCycle(graph, i, graph[i]->link, 0);
        if(findFlag)//at least one cycle
            break;
    }

    if(findFlag)
        cout << "There is at least one cycle in the graph." << endl;
    else
        cout << "There isn't any cycle in the graph." << endl;
    return 0;
}
