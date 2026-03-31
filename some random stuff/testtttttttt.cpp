#include <iostream>
using namespace std;

struct node {

    int data;
    node* next;

};

class LinkedList {

    private:
        node* head;

    public:
        LinkedList() {
            head = nullptr;
        }
    
        void insert_at_front(int new_number) {

            node* new_box = new node();
            new_box-> data = new_number;
        }
};