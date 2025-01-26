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

node *deletehead(node *head){
    head = head->link;
    return head;
}

node *deletetail(node *head){
    node* temp = head;
    while(temp->link->link!=NULL){
        temp = temp->link;
    }
    temp->link = nullptr;
    free(temp);
    return head;
}

node* deleteanypos(node *head, int pos){
    if(head==NULL) return head;
    if(pos==1){
        head = head->link;
        return head;
    }
    int count=0;
    node *temp = head;
    node *prev = nullptr;
    while(temp){
        count+=1;
        if(count==pos){
            prev->link = prev->link->link;
            free(temp);
            break;
        }
        prev = temp;
        temp=temp->link;
    }
    return head;
}

int main(){
    vector<int> arr = {1,2,3,4};
    node *head = arrtoll(arr);
    // head = deletehead(head);
    // head = deletetail(head);
    // head  = deleteanypos(head,3);
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->link;
    }
}