typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} OrderedList;

Node* createNode(int value);
OrderedList* createOrderedList();
void insert(OrderedList* list, int value);
void printList(OrderedList* list);
void freeList(OrderedList* list);
