#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *link;

    node(int data,node *link){
        this->data = data;
        this->link = link;
    }

    node(int data){
        this->data = data;
        this->link = nullptr;
    }
};

node* arrtoll(vector<int> &arr){
    node* head = new node(arr[0]);
    node* mover = head;
    for(int i=1;i<arr.size();i++){
        node *temp = new node(arr[i]);
        mover->link = temp;
        mover = temp;
    }
    return head;
}

void traverse(node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->link;
    }
}

int main(){
    vector<int> arr = {1,2,3,4};
    node *head = arrtoll(arr);
    traverse(head);
}