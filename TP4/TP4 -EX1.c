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

struct s_node_tree 
{
    int key;
    struct s_node_tree* right;
    struct s_node_tree* left;
};
typedef struct s_node_tree t_node_tree;
//Check if the queue is empty or not
int empty(queue queue)
{
    if(queue.head == NULL && queue.tail == NULL)
        return 1;
    return 0;
}
//Put on an element into the queue
queue* add_node_queue(queue* queue, int data)
{
    t_node* new_node = (t_node*)malloc(sizeof(t_node));
    new_node->data = data;
    new_node->next = NULL;
    if(empty(*queue) == 0)
    {
        printf("TEST\n");
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
//Put out an elemnt from the queue (the first one) and return its value
int remove_node_queue(queue* queue)
{
    if(queue->head != NULL)
    {
        int value = 0;
        value = queue->head->data;
        t_node* temp = queue->head;
        queue->head = temp->next;
        free(temp);
        return value;
    }
    else    
        exit(EXIT_FAILURE); 
}
//Max function
int max(int x, int y)
{
    if(x >= y)
        return x;
    else    
        return y;
}
//Create a binary tree
t_node_tree* create_tree(int key, t_node_tree* left_tree, t_node_tree* right_tree)
{
    t_node_tree* binary_tree = (t_node_tree*)malloc(sizeof(t_node_tree));
    binary_tree->key = key;
    binary_tree->left = left_tree;
    binary_tree->right = right_tree;
    return binary_tree;
}
//Calculate the depth of the tree recursively
int depth_recursive(t_node_tree* binary_tree)
{
    if(binary_tree == NULL)
        return 0;
    else
    {
        int depth_right = depth_recursive(binary_tree->right);
        int depth_left = depth_recursive(binary_tree->left);
        if(depth_right > depth_left)
            return depth_right + 1;
        else    
            return depth_left + 1;
    }
}
//Calculate the depth of the tree using the breadth-first-search (BFS) 
int depth_iterative(t_node_tree* binary_tree)
{
    int depth = 0;
    if(binary_tree != NULL)
    {
        queue* queue = NULL;
        t_node_tree* temp = binary_tree;
        add_node_queue(queue, temp->key); 
        while(queue != NULL)
        {
            temp->key = remove_node_queue(queue);
            if(temp->left != NULL)
                add_node_queue(queue, temp->left->key);
                depth++;
            if(temp->right != NULL)
                add_node_queue(queue, temp->right->key);
                depth++;
                if(temp->left != NULL && temp->right != NULL)
                    depth--;
        }
    }
    return depth;
}
//Calculating thed diameter of the tree
int diameter_recursive(t_node_tree* binary_tree)
{
    if(binary_tree == NULL)
        return 0;
    int depth_right = depth_recursive(binary_tree->right);
    int depth_left = depth_recursive(binary_tree->left);
    int diameter_right = diameter_recursive(binary_tree->right);
    int diameter_left = diameter_recursive(binary_tree->left);
    return max(depth_right + depth_left + 1, max(diameter_right, diameter_left));
}
//Calculate the sum of the leaves values (recursive)
int leaf_sum(t_node_tree* binary_tree, int sum)
{
    if(binary_tree == NULL)
        return 0;
    if(binary_tree->left == NULL && binary_tree->right == NULL)
    {
        sum = binary_tree->key;
        return sum;
    }
    int left_leafsum = leaf_sum(binary_tree->left, sum);
    int right_leafsum = leaf_sum(binary_tree->right, sum);
    return left_leafsum + right_leafsum;
}

/*int leaf_sum(t_node_tree* binary_tree)
{
    int sum = 0;
    if(binary_tree == NULL)
        return 0;
    queue* tmp_q = NULL;
    t_node_tree* temp = binary_tree;
    tmp_q = add_node_queue(tmp_q, temp->key);
    while(tmp_q != NULL)
    {
        temp->key = remove_node_queue(tmp_q);
        if(temp->left != NULL)
            tmp_q = add_node_queue(tmp_q, temp->left->key);
        else
            sum += temp->left->key;
        if(temp->right != NULL)
            tmp_q = add_node_queue(tmp_q, temp->right->key);
        else
            sum += temp->right->key;
    }
    return sum;
}*/
//menu
void menu()
{
    printf("---Binary Tree Demonstration ---\n\n");
    printf("0.Menu\n");
    printf("1.The depth/high of the tree\n");
    printf("2.The diameter of the tree\n");
    printf("3.The sum of leaves values\n");
    printf("4.Quit\n\n");
}
int main()
{
    int choice = 0;
    int k = 0;
    t_node_tree* left_binary_tree = NULL;
    t_node_tree* right_binary_tree = NULL;
    left_binary_tree = create_tree(1,NULL,NULL);
    right_binary_tree = create_tree(2, NULL, NULL);
    t_node_tree* binary_tree = create_tree(3, left_binary_tree, right_binary_tree);
    while(1)
    {
        printf("Enter a command(0-4) and 4 to quit: ");
        scanf("%d", &choice);
        if(choice == 4)
            break;
        switch(choice)
        {
            case 0:
                menu();
                break;
            case 1:
                k = depth_recursive(binary_tree);
                printf("the depth of the tree is: %d \n", k);
                break;
            case 2:
                k = diameter_recursive(binary_tree);
                printf("The diameter of the tree is %d\n", k);
                break;
            case 3:
                k = leaf_sum(binary_tree, k);
                printf("The sum of leaves values is %d\n", k);
                break;
            default:
                break;
        }
    }
    return 0;
}
