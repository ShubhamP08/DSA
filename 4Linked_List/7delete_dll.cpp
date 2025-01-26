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

node *deletehead(node *head){
    head = head->next;
    head->back = nullptr;
    return head;
}

node *deletetail(node *head){
    node* tail = head;
    while(tail->next!=NULL){
        tail = tail->next;
    }
    node *newtail = tail->back;
    tail->back = nullptr;
    newtail->next = nullptr;
    delete tail;
    return head;
}

node *deleteanypos(node* head, int k){
    if(head==NULL||head->next==NULL){
        if(k==1) return NULL;
    }
    int counter = 0;
    node *knode = head;
    while(knode!=NULL){
        counter+=1;
        if(counter==k) break;
        knode = knode->next;
    }
    node *prev = knode->back;
    node *front = knode->next;
    if(prev==NULL && front ==NULL) return NULL;
    else if(prev==NULL){
        return deletehead(head);
    }
    else if(front==NULL){
        return deletetail(head);
    }
    prev->next = front;
    front->back = prev;
    knode->next = knode->back = NULL;
    delete knode;
    return head;
}

void deleteanynode(node *temp){
    if (temp == NULL) return;
    node *prev = temp->back;
    node *front = temp->next;
    if(front==NULL){
        prev->next = NULL;
        temp->back = NULL;
        free(temp);
    }
    prev->next = front;
    front->back = prev;
    temp->next = temp->back = NULL;
    free(temp);
}

int main(){
    vector<int> arr = {1,2,3,4};
    node *head = arrtodll(arr);
    // head = deletehead(head);
    // head = deletetail(head);
    // head = deleteanypos(head,4);
    // deleteanynode(head->next->next);
    traverse(head);
}