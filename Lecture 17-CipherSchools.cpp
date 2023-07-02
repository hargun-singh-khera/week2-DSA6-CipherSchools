// Q1

// solution 1: using map
class Node {
public:
    int val;
    Node* next, *random;
};

// Node *copy(Node *head){
//     unordered_map<Node*,Node*> hash;
//     Node *ptr=head;
//     while(ptr!=NULL){
//         Node *copiedNode=new Node(ptr->val);
//         hash[ptr]=copiedNode;
//         ptr=ptr->next;
//     }
//     ptr=head;
//     while(ptr!=NULL){
        
//         Node *copied=hash[ptr];
//         copied->next=hash[ptr->next];
//         copied->random=hash[ptr->random];
//         ptr=ptr->next;
//     }
//     return hash[head];
// }

// solution 2:
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
Node *copy(Node *head){
    if(head==NULL) return head;
    Node *ptr=head,*qtr=NULL;
    while(ptr!=NULL){
        qtr=qtr->next;
        Node *newNode=new Node(ptr->val);
        newNode->next=qtr;
        ptr->next=newNode;
        ptr=qtr;
    }
    ptr=head,qtr=head->next;
    while(ptr!=NULL && qtr!=NULL){
        qtr=ptr->next;
        if(ptr->random!=NULL) {
            qtr->random=ptr->random->next;
        }
        else {
            qtr->next=NULL;
        }
        ptr=qtr->next;
    }
    Node *newHead = head->next;
    ptr=head;
    while(ptr!=NULL && qtr!=NULL){
        qtr=ptr->next;
        ptr->next=qtr->next;
        ptr=qtr;
    }
    return newHead;
}
int main() {
    
}