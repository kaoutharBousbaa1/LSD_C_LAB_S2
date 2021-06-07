#include <stdlib.h>
#include <stdio.h>

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
//Push an element into the stack
t_node* push(t_node* head, int data)
{
    t_node* new_node = (t_node*)malloc(sizeof(new_node));
    if(new_node == NULL)
    {
        exit(0);
    }
    new_node->data = data;
    new_node->next = head;
    head = new_node;
    return head;
}
//Pop an element from the satck
t_node* pop(t_node* head, int* element)//I don't understand why we used an int pointer
{
    t_node* temp = head;
    head = head->next;
    *element = head->data;
    free(temp);
    return head;
}
//Display the stack content
void display(t_node* head)
{
    if(head == NULL)
    {
        return NULL;
    }
    t_node* temp = head;
    printf("Stack : ");
    while(temp != NULL)
    {
        printf("%d", temp->data);
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
    int n_elements = 0;
    int element = 0;
    int counter = 0;
    inti_stack(head);
    printf("Enter the the number of elments of the linked stack: ");
    scanf("%d", &n_elements);
    printf("---Push elements into the stack---\n");
    while(counter < n_elements)
    {
        printf("Enter a number to push into the linked stack :");
        scanf("%d", &element);
        head = push(head, element);
        display(head);
        counter++;
    }
    printf("Pop elments from the linked stack");
    while(empty(head) != 0)
    {
        printf("Pop %d from stack :", element);
        head = pop(head, &element);
        display(head);
    }
    return 0;
}
