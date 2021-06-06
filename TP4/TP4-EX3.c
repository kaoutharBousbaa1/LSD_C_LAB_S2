#include <stdlib.h>
#include <stdio.h>

struct s_node
{
    int key;
    struct s_node* right;
    struct s_node* left;
};
typedef struct s_node t_node;

//Create a new node
t_node* create_node(int key)
{
    t_node* new_node = (t_node*)malloc(sizeof(t_node));
    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
//Insert a node to a BST
t_node* insert(t_node* binaryS_tree, int key)
{
    if(binaryS_tree == NULL)
        return create_node(key);
    t_node* new_node = create_node(key);
    t_node* temp = binaryS_tree;
    t_node* temp_1 = NULL;
    while(temp != NULL)
    {
        if(temp->key > key)
        {
            temp_1 = temp;
            temp = temp->left;
        }
        if(temp->key < key)
        {
            temp_1 = temp;
            temp = temp->right;
        }
        else
            return NULL;
    }
    if(temp_1->key > key)
        temp_1->left = new_node;
    if(temp_1->key < key)
        temp_1->right = new_node;
    return temp_1;
}
//Count the number of elements in the BST
int n_elem(t_node* binaryS_tree)
{
    int k = 1;
    if(binaryS_tree == NULL)
        return 0;
    k += n_elem(binaryS_tree->left) + n_elem(binaryS_tree->right);
    return k + 1;
}
//Convert the binary search tree to an array
int* convertBST_array(t_node* binaryS_tree, int* array)
{
    t_node* temp = binaryS_tree;
    t_node* temp_1 = NULL;
    array[0] = binaryS_tree->key;
    int i = 1;
    do
    {
        if(temp->right != NULL)
        {
            array[i] = temp->right->key;
            temp_1 = temp;
            temp = temp->right;
            i++;
        }
        else if(temp->left != NULL)
        {
            array[i] = temp->left->key;
            temp_1 = temp;
            temp = temp->left;
            i++;
        }    
    }while(temp != NULL);
    array[i] = temp_1->key; 
    return array;    
}
//Create a balanced binary search tree from the sorted array below
t_node* createBST_from_array(int* array, int s, int e) 
{
    if(s > e)
        return NULL;
    int m = (s+e)/2;
    t_node* balanced_BST = create_node(array[m]);
    balanced_BST->left = createBST_from_array(array, s, m-1);
    balanced_BST->right = createBST_from_array(array, m+1, e);
    return balanced_BST;
}
//Print binary search tree(Parcours préfixe):
void print_BST(t_node* binaryS_tree)
{
    if(binaryS_tree == NULL)
        return;
    printf("%d  ",binaryS_tree->key);
    if(binaryS_tree->left == NULL || binaryS_tree->right == NULL)
        printf("NULL  ");
    print_BST(binaryS_tree->left);
    print_BST(binaryS_tree->right);
}
int main()
{
    t_node* binaryS_tree = NULL;
    binaryS_tree = insert(binaryS_tree, 1);
    binaryS_tree = insert(binaryS_tree, 2);
    binaryS_tree = insert(binaryS_tree, 3);
    print_BST(binaryS_tree);
    printf("\n\n");
    int* array = (int*)malloc(4*sizeof(int));
    array = convertBST_array(binaryS_tree, array);
    t_node* tree = createBST_from_array(array, 1, 4);
    print_BST(tree);
    printf("\n\n");
    return 0;
}
