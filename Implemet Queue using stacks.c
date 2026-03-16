typedef struct {
    int top;
    int size;
    int* arr;
    int pushcount;
    int popcount;
} MyStack;

void push(MyStack* s, int val){
    if(s->top != s->size-1){
        s->top++;
        int temp = s->size-s->top-1;
        s->arr[temp] = val;
        s->pushcount++;
    }
}

int pop(MyStack* s){
    if(s->top != -1){
        s->popcount++;
        int val = s->arr[s->size-s->popcount];
        return val;
    }
    return -1;
}

int peek(MyStack* s){
    if(s->top != -1){
        int val = s->arr[s->size-s->popcount-1];
        return val;
    }
    return -1;
}

typedef struct {
    MyStack* st;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
    q->st = (MyStack*)malloc(sizeof(MyStack));
    q->st->top = -1;
    q->st->size = 50;
    q->st->arr = (int*)malloc(sizeof(int)*q->st->size);
    q->st->pushcount = 0;
    q->st->popcount = 0;
    return q;
}

void myQueuePush(MyQueue* obj, int x) {
  push(obj->st, x);
}

int myQueuePop(MyQueue* obj) {
  return pop(obj->st);
}

int myQueuePeek(MyQueue* obj) {
  return peek(obj->st);
}

bool myQueueEmpty(MyQueue* obj) {
    if(obj->st->pushcount == obj->st->popcount) return true;
    return false;
}

void myQueueFree(MyQueue* obj) {
    free(obj->st->arr);
    free(obj->st);
    free(obj);
}
