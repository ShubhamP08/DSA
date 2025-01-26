#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node *back;

    node(int data,node *next,node *back){
        this->data = data;
        this->next = next;
        this->back = back;
    }

    node(int data){
        this->data = data;
        this->next = nullptr;
        this->back = nullptr;
    }
};

node* arrtodll(vector<int> &arr){
    node* head = new node(arr[0]);
    node* prev = head;
    for(int i=1;i<arr.size();i++){
        node *temp = new node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void traverse(node *head){
    while(head){
        cout<<head->data<<" -> ";
        head = head->next;
    }
    cout<<"NULL";
}

void traverse_reverse(node *head){
    node* temp =head;
    while(temp->next){
        temp = temp->next;
    }
    while(temp){
        cout<<temp->data<<" -> ";
        temp = temp->back;
    }
    cout<<"NULL";
}

int main(){
    vector<int> arr = {1,2,3,4};
    node *head = arrtodll(arr);
    traverse_reverse(head);
}