#include <stdio.h>
#include <stdlib.h>

typedef struct S_element T_element;
struct S_element
{
    int x;
    T_element *next_node;
};
typedef struct S_list T_list;
struct T_list
{
    T_element *first_node;
};

T_list *create_node()
{
    T_list *list = malloc(sizeof(*list));
    T_element *element = malloc(sizeof(*element));

    if (list == NULL || element == NULL)
    {
        exit(1);
    }

    element->x = 0;
    element->next_node = NULL;
    list->first_node = element;

    return list;
}
void add_node(T_list *list, int number)
{
    T_element *new_node = malloc(sizeof(*new_node));
    if (list == NULL || new_node == NULL)
    {
        exit(1);
    }
    new_node->x = number;
    if(list->next_node == NULL)
    {
        list->next_node = new_node;
    }
    new_node->next_node == NULL;
}
void remove_node(T_list *list, int number)
{
    if (list == NULL)
    {
        exit(1);
    }
    T_element *remove_node = list->next_node;
    list->next_node = list->remove_node->next_node;
    free(remove_node);
}
void print_list(T_list *list)
{
    if (list == NULL)
    {
        exit(1);
    }

    T_element *y = list->first_node;

    while (y != NULL)
    {
        printf("%d -> ", y->x);
        y = x->next_node;
    }
    printf("NULL\n");
}
T_list array_to_list(char array[])
{
    int n = len(array);
    T_list *list = malloc(sizeof(*list));
    T_element *element = malloc(sizeof(*element));
    for(int i = 0; i<n-1; i++)
    {
        element->x = array[i];
        element->next_node = array+i;
        list->first_node = element;
    }
    element->x = array[n-1];
    element->next_node = NULL;
    
    return list;
}
int main(int argc, char* argv[])
{

    return 0;
}