#include <bits/stdc++.h>

using namespace std;

class Node{

    int number; //The name of the node
    Node* link;
    /*Except above, you can add any other field you like in class “Node”. */
    int children_number;
    public:
        Node(){children_number = 0;number = 0; link = nullptr;}
        Node(int i){number = i;children_number = 0;link = nullptr;}    

        int getnumber(){return number;}
        int getChildren_number(){return children_number;}
        Node* getlink(){return link;}

        void setnumber(int i){number = i;}
        void setlink(Node* target){link = target;}
        void setlinkElement(int index,int num){link[index].number = num;}
        void setChildren_number(int num){children_number = num;}

};

bool findcycle(vector<Node>& all,int index,int linkIndex,int times){
    if(times > all.size()){
        return true;
    }
    else if(all[index].getChildren_number() == 0){
        return false;
    }
    else if(linkIndex > all[index].getChildren_number()-1){
        return false;
    }
    else if((all[index].getlink()[linkIndex]).getnumber() == index)
        return true;
    else{
        if(findcycle(all,(all[index].getlink()[linkIndex]).getnumber(),0,times+1))
            return true;
        else
            return findcycle(all,index,linkIndex+1,times+1);    
    }
}



int main(){
    int node_number;
    cin >> node_number;
    if(node_number <0){
        cout<< "Wrong Input"<<endl;
        return 0;
    }

    vector<Node> all;
    all.clear();

    for(int i = 0;i<node_number;i++){
        Node obj(i);
        all.push_back(obj);
    }

    for(int i = 0;i<node_number;i++){
        int children_number;
        cin >> children_number;
        if(children_number < 0){
            cout<< "Wrong Input"<<endl;
            return 0;
        }else if(children_number == 0){
            all[i].setlink(nullptr);
            all[i].setChildren_number(0);
            continue;
        }

        Node* childen = new Node[children_number];
        all[i].setlink(childen);
        all[i].setChildren_number(children_number);
        for(int j = 0;j<children_number;j++){
            int child;
            cin >> child;
            if(child < 0||child > node_number){
                cout<< "Wrong Input"<<endl;
                return 0;
            }
            all[i].setlinkElement(j,child);
        }
    }
    bool find = false;
    for(int i = 0;i<node_number;i++){
        find = findcycle(all,i,0,0);
        if(find)break;
    }

    if(find){
        cout <<"There is at least one cycle in the graph."<<endl;
    }else{
        cout <<"There isn't any cycle in the graph."<<endl;
    }
    return 0;

}
