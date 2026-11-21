typedef struct Node {
    int val;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
    int size;
} Queue;

typedef struct {
    Queue *q1;
    Queue *q2;
} MyStack;

Queue* createQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}

void enqueue(Queue *q, int x) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->val = x;
    node->next = NULL;

    if (q->rear)
        q->rear->next = node;
    else
        q->front = node;

    q->rear = node;
    q->size++;
}

int dequeue(Queue *q) {
    Node *temp = q->front;
    int val = temp->val;

    q->front = temp->next;
    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    q->size--;

    return val;
}

int frontQueue(Queue *q) {
    return q->front->val;
}

bool emptyQueue(Queue *q) {
    return q->size == 0;
}

MyStack* myStackCreate() {
    MyStack *obj = (MyStack *)malloc(sizeof(MyStack));
    obj->q1 = createQueue();
    obj->q2 = createQueue();
    return obj;
}

void myStackPush(MyStack* obj, int x) {
    enqueue(obj->q2, x);

    while (!emptyQueue(obj->q1)) {
        enqueue(obj->q2, dequeue(obj->q1));
    }

    Queue *temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;
}

int myStackPop(MyStack* obj) {
    return dequeue(obj->q1);
}

int myStackTop(MyStack* obj) {
    return frontQueue(obj->q1);
}

bool myStackEmpty(MyStack* obj) {
    return emptyQueue(obj->q1);
}

void myStackFree(MyStack* obj) {
    while (!emptyQueue(obj->q1))
        dequeue(obj->q1);

    while (!emptyQueue(obj->q2))
        dequeue(obj->q2);

    free(obj->q1);
    free(obj->q2);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
