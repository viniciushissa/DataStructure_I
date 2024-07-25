typedef struct Node {
    void *data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    int (*compare)(void *, void *); 
} OrderedList;

Node *createNode(void *data);
void insert(OrderedList *list, void *data);
int compareInt(void *a, void *b);
void printList(OrderedList *list);
