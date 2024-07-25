typedef struct Node {
    char area[100];
    int censo2000;
    int censo1990;
    struct Node *next2000;
    struct Node *next1990;
} Node;

typedef struct {
    Node *head2000;
    Node *head1990;
} Header;

void readFile(const char *filename, Header *header);
void insertOrdered(Header *header, Node *newNode);
void printList(Node *head, int year);
