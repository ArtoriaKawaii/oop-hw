//學號:B073040022
//姓名:張浩綸
//#include<bits/stdc++.h>//include all standard libaray
#include<iostream>
#include<vector>
using std::cout;
using std::vector;
using std::cin;
using std::endl;
void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}
class List{
    public:
        List(){}
        virtual void append(int v){
            list.push_back(v);
        }
        virtual void remove(){
            if(!list.empty()){
                vector<int>::iterator iter = list.begin();
                list.erase(iter);
            }
            else
                cout << "The list is empty !" << endl;
        }
        virtual void show(){
            for(vector<int>::iterator iter = list.begin(); iter!=list.end(); ++iter)
                cout << *iter << " ";
            cout << endl;
        }
    protected:
        vector<int> list;
};
class MaxHeap : public List{
    public:
        //list.at(0) is never use in heap
        MaxHeap() : List(){list.push_back(0);}
        void append(int v);
        void remove();
        void show();
    private:
        void adjust();
        void maxHeap(const int root, const int length);
        void heapSort(const int length);
        void inorder(const int root);
};
void MaxHeap::adjust(){
    heapSort(list.size()-1);
}
void MaxHeap::maxHeap(const int root, const int length){
    int left = 2*root;      //get left child
    int right = 2*root + 1; //get right child
    int largest = root;
    if(left <= length && list.at(left) > list.at(root))
        largest = left;
    if(right <= length && list.at(right) > list.at(largest))
        largest = right;
    if(largest != root){
        swap(list.at(largest), list.at(root));
        maxHeap(largest, length);
    }
}
void MaxHeap::heapSort(const int length){
    for (int i = length/2; i >= 1 ; i--) 
        maxHeap(i, length);

    // for (int i = length -1; i >= 1; i--){
    //     swap(list.at(1), list.at(i+1));
    //     maxHeap(1, i);
    // }
}
void MaxHeap::append(int v){
    list.push_back(v);
    adjust();
}
void MaxHeap::remove(){
    if(list.size() > 1){
        swap(list.at(1), list.at(list.size()-1));
        list.pop_back();
        adjust();
    }
    else
        cout << "The list is empty !" << endl;
}
void MaxHeap::show(){
    inorder(1);
}
void MaxHeap::inorder(const int root){
    if(root >= list.size()){//leaf node
        return;
    }
    inorder(root*2);
    cout << list.at(root) << endl;
    inorder(root*2+1);
}
int main(){
    List* max_heap = new MaxHeap();
    while(true){
        int v;
        cin >> v;
        if(v == -1)
            break;
        max_heap->append(v);
    }
    max_heap->remove();
    max_heap->remove();
    max_heap->show();
    return 0;
}