struct st_stack;
typedef struct st_stack{
    int pointer;
    int size;
    char *data;
    void (*push)(char item, struct st_stack *stack);
    int (*pop)(struct st_stack *stack);
    int (*peek)(struct st_stack *stack);
}st_stack;

typedef struct st_stack s_stack;
void fun_push(char item, struct st_stack *stack)
{
    if(stack->data == (void*)0)
    {
        stack->size++;
        stack->data = (char*)malloc(sizeof(char));
    }
    else if(stack->pointer>=stack->size)
    {
        stack->size *= 2;
        stack->data = (char*)realloc(stack->data,sizeof(char)*stack->size);
    }
    else
    {
        /* Do Nothing */
    }
    stack->data[stack->pointer++] = item;
}

int fun_pop(struct st_stack *stack)
{
    int ret_val = -1;
    if(stack->pointer == 0)
    {
        ret_val = -1;
    }
    else
    {
        ret_val = stack->data[--stack->pointer];
    }
    return ret_val;
}

int fun_peek(struct st_stack *stack)
{
    int ret_val = -1;
    if(stack->pointer == 0)
    {
        ret_val = -1;
    }
    else
    {
        ret_val = stack->data[stack->pointer-1];
    }
    return ret_val;
}
bool is_match(char a, char b)
{
    bool ret_val = false;
    if(((a=='(')&&(b==')'))\
    ||((a=='[')&&(b==']'))\
    ||((a=='{')&&(b=='}')))
    {
        ret_val = true;
    }
    return ret_val;
}
/* Running Code from here */
bool isValid(char* s) {
    struct st_stack *stack0 = (struct st_stack*)malloc(sizeof(struct st_stack));
    stack0->push = &fun_push;
    stack0->peek = &fun_peek;
    stack0->pop = &fun_pop;
    stack0->data = (void*)0;
    stack0->pointer = stack0->size = 0;
    int i=0;
    bool ret_value = false;
    while(s[i]!='\0')
    {
        if((s[i] == '(') || (s[i] == '[')||(s[i] == '{'))
        {
            stack0->push(s[i],stack0);
        }
        else
        {
            if((stack0->peek(stack0)!=-1)\
            &&(is_match((int)(stack0->pop(stack0)),s[i])))
            {
                ret_value = true;
            }
            else
            {
                ret_value = false;
                break;
            }
        }
        i++;
    }
    if(stack0->pointer != 0)
    {
        ret_value = false;
    }
    return ret_value;
}
