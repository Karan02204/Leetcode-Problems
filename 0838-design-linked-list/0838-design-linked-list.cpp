class Node{
public:
    int val;
    Node* next;
    Node(int x){
        val = x;
        next = NULL;
    }
};

class MyLinkedList {
private:
    Node* head;
    int size;
public:
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }
    
    int get(int index) {
        if(index < 0 || index >= size){
            return -1;
        }
        Node* temp = head;
        while(index > 0){
            temp = temp->next;
            index--;
        }

        return temp->val;
    }
    
    void addAtHead(int val) {
        Node* node = new Node(val);
        node->next = head;
        head = node;
        size++;
    }
    
    void addAtTail(int val) {
        Node* node = new Node(val);
        if(head==NULL){
            head = node;
            size++;
            return;
        }
        Node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }

        temp->next = node;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > size) return;
        if (index <= 0) return addAtHead(val);
        if (index == size) return addAtTail(val);
        Node* node = new Node(val);
        Node* temp = head;
        while(index-1 > 0){
            temp = temp->next;
            index--;
        }

        node->next = temp->next;
        temp->next = node;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        if(index == 0){
            head = head->next;
        }else{
            Node* temp = head;
            for(int i=0;i<index-1;i++){
                temp = temp->next;
            }

            temp->next = temp->next->next;
        }
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */