#pragma once
#pragma warning
#include <iostream>


using namespace std;


class Node {
public:
    int key;       //to make unique which don't repitative ,object has to be unique
    int data;
    Node* next;

    Node() {

        key = 0;
        data = 0;
        next = NULL;
    }
    Node(int k, int d) {
        key = k;
        data = d;
        next = NULL;
    }
};

class SinlglyLinkedList {
public:
    Node* head;

    void SinglyLinkedList() {
        head = NULL;
    }

    void SinglyLinkedList(Node* n) {
        head = n;
    }



//Check a perticular node that exist or not in the list by usnig key value

Node* nodeExists(int k) {
    Node* temp = NULL;
    Node* ptr = head;
    while (ptr != NULL) {
        if (ptr->key == k) {
            temp = ptr;
        }
        ptr = ptr->next;
    }
    return temp;
}

//Append a new node in the list

    // 2. Append a node to the list
void appendNode(Node* n) {
    if (nodeExists(n->key) != NULL) {
        cout << "Node Already exists with key value : " << n->key << ". Append another node with different Key value" << endl;
    }
    else {
        if (head == NULL) {
            head = n;
            cout << "Node Appended" << endl;
        }
        else {
            Node* ptr = head;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = n;
            cout << "Node Appended" << endl;
        }
    }

}





// 3. Prepend Node - Attach a node at the start
void prependNode(Node* n) {
    if (nodeExists(n->key) != NULL) {
        cout << "Node Already exists with key value : " << n->key << ". Append another node with different Key value" << endl;
    }
    else {
        n->next = head;
        head = n;
        cout << "Node Prepended" << endl;
    }
}

// 4. Insert a Node after a particular node in the list
void insertNodeAfter(int k, Node* n) {
    Node* ptr = nodeExists(k);
    if (ptr == NULL) {
        cout << "No node exists with key value: " << k << endl;
    }
    else {
        if (nodeExists(n->key) != NULL) {
            cout << "Node Already exists with key value : " << n->key << ". Append another node with different Key value" << endl;
        }
        else {
            n->next = ptr->next;
            ptr->next = n;
            cout << "Node Inserted" << endl;
        }
    }
}

// 5. Delete node by unique key
void deleteNodeByKey(int k) {
    if (head == NULL) {
        cout << "Singly Linked List already Empty. Cant delete" << endl;
    }
    else if (head != NULL) {
        if (head->key == k) {
            head = head->next;
            cout << "Node UNLINKED with keys value : " << k << endl;
        }
        else {
            Node* temp = NULL;
            Node* prevptr = head;
            Node* currentptr = head->next;
            while (currentptr != NULL) {
                if (currentptr->key == k) {
                    temp = currentptr;
                    currentptr = NULL;
                }
                else {
                    prevptr = prevptr->next;
                    currentptr = currentptr->next;
                }
            }
            if (temp != NULL) {
                prevptr->next = temp->next;
                cout << "Node UNLINKED with keys value : " << k << endl;
            }
            else {
                cout << "Node Doesn't exist with key value : " << k << endl;
            }
        }
    }

}
// 6th update node
void updateNodeByKey(int k, int d) {

    Node* ptr = nodeExists(k);
    if (ptr != NULL) {
        ptr->data = d;
        cout << "Node Data Updated Successfully" << endl;
    }
    else {
        cout << "Node Doesn't exist with key value : " << k << endl;
    }

}

// 7th printing
void printList() {
    if (head == NULL) {
        cout << "No Nodes in Singly Linked List";
    }
    else {
        cout << endl << "Singly Linked List Values : ";
        Node* temp = head;

        while (temp != NULL) {
            cout << "(" << temp->key << "," << temp->data << ") --> ";
            temp = temp->next;
        }
    }

}




};

