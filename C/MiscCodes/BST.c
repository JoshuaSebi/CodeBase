#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};
struct Node *root=NULL,*temp=NULL,*newnode;

struct Node* createNode(int key) //create a new node
{
    newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->key = key;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct Node* findMin(struct Node* node)
{
    while (node->left != NULL)
        node = node->left;
    return node;
}

struct Node* insert(struct Node* node, int key)  //Insertion
{
    if (node == NULL) 
    {
        return createNode(key);
    }
    if (key < node->key) //insert left of node
    {
        node->left = insert(node->left, key);
    } 
    else if (key > node->key) //insert right of node 
    {
        node->right = insert(node->right, key);
    }
    else
    {
        printf("Element already present\n");
    }
    return node;
}

struct Node* Delete(struct Node* root, int value)
{
    // Searching for the node to delete
    if (root == NULL)
        return root;
    else if (value < root->key)
        root->left = Delete(root->left, value);
    else if (value > root->key)
        root->right = Delete(root->right, value);
    
    // Node to be deleted found
    else
    {
        // Case 1: No child (leaf node)
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
            return root;
        }
        // Case 2: One child (right child exists)
        else if (root->left == NULL)
        {
            struct Node* temp = root;
            root = root->right;
            free(temp);
            return root;
        }
        // Case 2: One child (left child exists)
        else if (root->right == NULL)
        {
            struct Node* temp = root;
            root = root->left;
            free(temp);
            return root;
        }
        // Case 3: Two children
        else
        {
            struct Node* temp = findMin(root->right); // Find minimum in the right subtree
            root->key = temp->key;
            root->right = Delete(root->right, temp->key); 
        }
    }
    return root;
}

void preorder(struct Node* node) {
    if (node == NULL)
        return;
    printf("%d ", node->key);  
    preorder(node->left);      
    preorder(node->right);     
}

void inorder(struct Node* node) {
    if (node == NULL)
        return;
    
    inorder(node->left);       
    printf("%d ", node->key);  
    inorder(node->right);      
}

void postorder(struct Node* node) {
    if (node == NULL)
        return;
    
    postorder(node->left);     
    postorder(node->right);    
    printf("%d ", node->key);  
}




int main() {
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display Inorder\n");
        printf("4. Display Preorder\n");
        printf("5. Display Postorder\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Inserted %d\n", value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = Delete(root, value);
                printf("Deleted %d\n", value);
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 5:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 6);

    return 0;
}
