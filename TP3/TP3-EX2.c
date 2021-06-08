#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct s_node
{
    int data;
    struct s_node *next;
};
typedef struct s_node t_node;

//create a new node
t_node* create(int data)
{
    t_node* new_node = (t_node*)malloc(sizeof(t_node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
//Display the whole linked list
void display_list(t_node* head)
{
    t_node* temp = head;
    while(temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("%d  \n\n", temp->data);
}
//Add a new node at the end of the linked
t_node* append(t_node* head, int data)
{
    t_node* temp = head;
    if(head == NULL)
        return create(data);
    while(temp->next != NULL)
        temp = temp->next;
    t_node* new_node = create(data);
    temp->next = new_node;
    return head;
}
//Sort a linked list using insertion sort 
t_node* sort_list(t_node* head)
{
    t_node* x, *y, *z;
    x = head;
    y = x->next;
    if(head == NULL)
        return NULL;
    while(y != NULL)
    {
        x = head;
        while(x->next != y)
        {
            if(y->data < x->data)
            {
                z->data = x->data;
                x->data = y->data;
                y->data = z->data;
                y = y->next;
            }
            x = x->next;
            if(y->data > x->data)
            {
                y = y->next;
            }
        }   
    }
    return head;
}
//Create a list with random values
t_node* create_random(t_node* head, int k)
{
    for(int i = 0; i<k; i++)
    {
        int l = rand()%k;
        t_node* new_node = create(l);
        head = append(head, l);
    }
    return head;
}
//Count the elements of the linked list
int count(t_node* head)
{
    t_node* temp = head;
    int c = 0;
    while(temp != NULL)
    {
        c++;
        temp = temp->next;
    }
    return c;
}
//Merge the two linked list to one sorted list
t_node* merge_list(t_node* head_1, t_node* head_2)
{
    t_node* res = NULL;
    if(head_1 == NULL)
        return head_2;
    else if(head_2 == NULL)
        return head_1;
    if(head_1->data <= head_2->data)
    {
        res->data = head_1->data;
        res->next = merge_list(head_1->next, head_2);
    }
    if(head_1->data >= head_2->data)
    {
        res->data = head_2->data;
        res->next = merge_list(head_1, head_2->next);
    }
    return res;
}
//Delete a node from the middle of the linked list
t_node* remove_middle(t_node* head, t_node* node)
{
    t_node* temp = head;
    t_node* temp_1 = NULL;
    while(temp != node)
    {
        temp_1 = temp;
        temp = temp->next;
    }
    temp_1->next = temp->next;
    //temp->next = NULL;
    free(temp);
    return head;
}
//Remove duplicated values from the sorted linked list
t_node* remove_duplicated(t_node* head)
{
    t_node* temp = head;
    while(temp != NULL)
    {
        t_node* temp_1 = temp->next;
        if(temp->data == temp->next->data)
        {
            head = remove_middle(head, temp_1);

        }
        temp = temp->next;
    }
    return head;
}
int main()
{
    srand (time(NULL));
    t_node* head_1 = NULL;
    head_1 = create_random(head_1, 5);
    t_node* head_2 = NULL;
    head_2 = create_random(head_2, 10);
    display_list(head_1);
    display_list(head_2);
    head_1 = sort_list(head_1);
    head_2 = sort_list(head_2);
    t_node* head = merge_list(head_1, head_2);
    display_list(head);
    head = remove_duplicated(head);
    display_list(head);
    return 0;
}
