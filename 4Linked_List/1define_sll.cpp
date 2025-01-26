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

int main(){
    vector<int> v1 = {1,2,3,4,5};
    node *head = new node(v1[1],nullptr);
    node *n1 = new node(v1[4],nullptr);
    node *n2 = new node(v1[2],nullptr);
    node *n3 = new node(v1[0],nullptr);
    node *n4 = new node(v1[3],nullptr);

    head->link = n1;
    n1->link = n2;
    n2->link = n3;
    n3->link = n4;

    cout<<head->link->data;
}