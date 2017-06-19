typedef struct Node Node;

extern Node* newNode (int);
extern Node* insertAtBeg(Node*, Node*);
extern Node* deleteAtBeg(Node*);
extern Node* insertAtEnd(Node*, Node*);
extern Node* deleteAtEnd(Node*);
extern void traverse (Node*);
