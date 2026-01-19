#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
} *head = NULL;

void insertAtLast(int item) {
    Node* newNode = new Node();
    newNode->data = item;
    newNode->next = NULL;
    
    if(head == NULL) {
        head = newNode;
        return;
    }
    
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return;
}

void insertAtFirst(int item) {
    Node* newNode = new Node;
    newNode->data = item;
    newNode->next = NULL;
    
    if(!head) {
        head = newNode;
        return;
    }
    
    newNode->next = head;
    head = newNode;
    return;
}

void insertAtMid(int item, int pos) {
    int i = 1;
    Node* newNode = new Node;
    newNode->data = item;
    newNode->next = NULL;
    
    if(!head) {
        head = newNode;
        return;
    }
    if(pos==1) {
        insertAtFirst(item);
        return;
    }
    
    Node* temp = head;
    while(i<pos-1) {
        temp = temp->next;
        i++;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
    return;
}

void deleteNode(int item) {
    if(!head) {
        return;
    }
    if(head->data == item) {
        head = head->next;
        return;
    }
    Node* temp = head;
    while(temp && temp->next && temp->next->data != item) {
        temp = temp->next;
    }
    if(!temp || !temp->next) {
        cout<<"No Element Found"<<endl;
        return;
    }
    if(!temp->next->next) {
        temp->next = NULL;
        return;
    }
    temp->next = temp->next->next;
    return;
}

void display() {
    Node* temp = head;
    while(temp!=NULL) {
        cout<<temp->data;
        if(temp->next) {
            cout<<"->";
        }
        temp = temp->next;
    }
}

int main() {
    int item;
    cout<<"Enter item at end: ";
    cin>>item;
    insertAtLast(item);
    display();
    cout<<endl<<"Enter item at start: ";
    cin>>item;
    insertAtFirst(item);
    display();
    int pos;
    cout<<endl<<"Enter item at mid and pos: "<<endl;
    cin>>item>>pos;
    insertAtMid(item, pos);
    display();
    cout<<endl<<"Enter item to delete: ";
    cin>>item;
    deleteNode(item);
    display();
    return 0;
}