#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct s_node
{
    int data;
    struct s_node* next;
};
typedef struct s_node t_node;
void initi_stack(t_node* head)
{
    head = NULL;
}

int readchar(){return getchar();}

//Push an element into the stack
t_node* push(t_node* head, int data)
{
    t_node* new_node = (t_node*)malloc(sizeof(new_node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
    return head;
}
//Pop an element from the satck
int pop(t_node* head)
{
    if(head == NULL)
        return INT_MIN;
    t_node* temp = head;
    head = head->next;
    int element = head->data;
    free(temp);
    return element;
}
//Return the top element in the stack
int peek_stack(t_node* head)
{
    if(head == NULL)
        return INT_MIN;
    int element = head->data;
    return element;
}
//Display the stack content
void display(t_node* head)
{
    if(head == NULL)
    {
        return;
    }
    t_node* temp = head;
    printf("Stack : ");
    while(temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
//return 1 if the stack is empty
int empty(t_node* head)
{
    return  head == NULL ? 1 : 0;
}
int main()
{
    t_node* head = NULL;
    int res = 0;
    while(1)
    {
        char string = readchar();
        if(string > '0')
            head = push(head, string);
        if(string == '+')
        {
            int arg1 = pop(head);
            int arg2 = pop(head);
            res = arg1 + arg2;
            head = push(head, res);

        }
        if(string == '*')
        {
            int arg1 = pop(head);
            int arg2 = pop(head);
            res = arg2 * arg1;
            head = push(head, res);
        }
        if(string == '-')
        {
            int arg1 = pop(head);
            int arg2 = pop(head);
            res = arg2 - arg1;
            head = push(head, res);
        }
        if(string == '/')
        {
            int arg1 = pop(head);
            int arg2 = pop(head);
            res = arg2 / arg1;
            head = push(head, res);
        }
        if(string == '%')
        {
            int arg1 = pop(head);
            int arg2 = pop(head);
            res = arg2 % arg1;
            head = push(head, res);
        }
        if(string == '\n')
            break;
    }
    res = peek_stack(head);
    printf("The result is %d\n\n", res);

    return 0;
}
