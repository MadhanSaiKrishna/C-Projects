#define MAX_SIZE 1000

typedef struct db
{
    int id;
    char name[1000];
    char position[1000];
    int salary;
}db;

typedef struct Node
{
    db data;
    struct Node* next;
}Node;


Node* add(Node* list);
void display(Node* list);
void input(Node* list);