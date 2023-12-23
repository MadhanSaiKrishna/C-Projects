#define MAX_SIZE 1000

typedef struct db
{
    int id;
    char* name;
    char* position;
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
void freeList(Node* list);
void searchbyId(int num,Node* list);
void updateSalary(int id, int salary,Node* list);