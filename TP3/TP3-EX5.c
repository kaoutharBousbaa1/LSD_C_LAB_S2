#include <stdio.h>
#include <stdlib.h>

struct s_node
{
    int data;
    struct s_node* next;
    struct s_node* previous;
};
typedef struct s_node t_node;

struct queue
{
    t_node* head;
    t_node* tail;
};
typedef struct queue queue;

//Check if the queue is empty or not
int empty(queue queue)
{
    if(queue.head == NULL && queue.tail == NULL)
        return 1;
    return 0;
}

//Add a new node the queue
queue* add_node_queue(queue* queue, int data)
{
    t_node* new_node = (t_node*)malloc(sizeof(t_node));
    new_node->data = data;
    new_node->next = NULL;
    if(empty(*queue) == 0)
    {
        queue->tail->next = new_node;
        queue->tail = new_node;
        return queue;
    }
    else
    {
        queue->head = queue->tail = new_node;
        return queue;
    } 
}

//Get the last element of the queue
int get_last_element(queue* queue)
{
    return queue->tail->data;
}

int readchar(){return getchar();}

//Tasks interval function
int tasks_interval(int n)
{
    queue* queue = NULL;
    int res = 0;
    char string = readchar();
    queue = add_node_queue(queue, string);
    while(1)
    {
        char string = readchar();
        if(string == '\n')
            break;
        else
        {
            int k = get_last_element(queue);
            if(k == string)
                res += n;
            else
                res += 1;
            queue = add_node_queue(queue, string);
        }
    }
    return res;
}
int main()
{
    int res = tasks_interval(2);
    printf("Output: %d\n\n\n", res);
    return 0;
}
