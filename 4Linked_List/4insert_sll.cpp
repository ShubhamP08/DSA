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

node* inserthead(node *head,int val){
    return new node(val,head);   //node n = new node(val,head); return n
}

node* inserttail(node* head,int val){
    node *temp = head;
    while(temp->link){
        temp = temp->link;
    }
    temp->link = new node(val);
    return head;
}

node* insertatk(node* head,int val,int k){
    if(head==NULL){
        if(k==1)
            return new node(val);
        else return head;
    }
    if(k==1){
        return new node(val,head);
    }
    int counter = 0;
    node *temp = head;
    while(temp->link!=NULL){
        counter+=1;
        if(counter == k-1){
            node *n = new node(val);
            n->link = temp->link;
            temp->link = n;
            break;
        }
        temp = temp->link;
    }
    return head;
}

node *insertbeforex(node *head,int val,int x){
    if(head==NULL){
        return NULL;
    }
    if(head->data == x){
        return new node(val,head);
    }
    node *temp = head;
    bool flag = false;
    while(temp->link!=NULL){
        if(temp->link->data==x){
            node *n = new node(val);
            n->link = temp->link;
            temp->link = n;
            flag=1;
            break;
        }
        temp = temp->link;
    }
    if(flag==0) cout<<"Value not Found"<<endl;
    return head;
}

int main(){
    vector<int> arr = {1,2,3,4};
    node *head = arrtoll(arr);
    // head = inserttail(head,10);
    // head = inserthead(head,8);
    // head = insertatk(head,9,1);
    // head = insertbeforex(head,8,4);
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->link;
    }
}