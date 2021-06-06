#include <stdio.h>
#include <stdlib.h>

struct s_node
{
    char data;
    struct s_node *next;
};
typedef struct s_node t_node;

//create a new node
t_node* create(char data)
{
    t_node* new_node = (t_node*)malloc(sizeof(t_node));
    if(new_node = NULL)
    {
        printf("Error creating a new node");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
//Add a node at the end of the linked list
t_node* addnode(t_node* head, char data)
{
    t_node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    t_node* new_node = create(data);
    temp->next = new_node;
    return temp;
}
//Convert a string to a linked list
t_node* stringTo_list(char string[], t_node* headlist)
{
    if(*string == ' ')
        return NULL;
    headlist = create(string[0]);
    t_node* temp = headlist;
    int i = 1;
    do
    {
        headlist = addnode(string[i]);
        i++;
    } while(i < string.size());
    return headlist;
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
//Optimal palindrome function
int palindrome_check_opt(char string)
{
    int k = sizeof(string);
    int h = 0;
    if(sizeof(string == 1))
        return 0;
    for(int i = 0; i < k/2; i++)
    {
        if(string[h+i] != string[k-i])
            return 1;
    }
    return 0;
}
int main(int argc, char* argv[])
{
    if(argc < 2)
        printf("No argument passed through the command line.\n"); 
    else
    {
        printf("The string argument is: %s\n", argv[1]); 
        int k = palindrome_check_opt(argv[1]);
    }
    return 0;
}