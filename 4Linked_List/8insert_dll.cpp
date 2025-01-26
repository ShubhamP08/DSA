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

node *inserthead(node *head,int val){
    node *newhead = new node(val,head,nullptr);
    head->back = newhead;
    return newhead;
}

node *inserttail(node *head,int val){
    node* tail = head;
    while(tail->next!=NULL){
        tail = tail->next;
    }
    node *newtail = new node(val,nullptr,tail);
    tail->next = newtail;
    free(tail);
    return head;
}

node *insertanypos(node* head,int val,int k){
    if(k==1) return inserthead(head,val);
    node *temp = head;
    int counter = 0;
    while(temp!=NULL){
        counter+=1;
        if(counter==k) break;
        temp=temp->next;
    }
    node *prev = temp->back;
    node *newnode = new node(val,temp,prev);
    prev->next=newnode;
    temp->back=newnode;
    return head;
}

void insertnode(node *temp,int val){
    node *prev = temp->back;
    node *newnode = new node(val,temp,prev);
    prev->next = newnode;
    temp->back = newnode;
}

int main(){
    vector<int> arr = {2,3,4,5};
    node *head = arrtodll(arr);
    head = inserthead(head,1);
    head = inserttail(head,6);
    head = insertanypos(head,10,6);
    insertnode(head->next->next->next,8);
    traverse(head);
}