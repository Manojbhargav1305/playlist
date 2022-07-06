
#include <stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

int search(int arr[], int strt, int end,int value);
struct node* newNode(int data);

struct node* buildTree(int in[], int pre[], int inStrt, int inEnd)
{
	static int preIndex = 0;

	if (inStrt > inEnd)
		return NULL;

	struct node* tNode = newNode(pre[preIndex++]);

	if (inStrt == inEnd)
		return tNode;

	int inIndex = search(in, inStrt, inEnd, tNode->data);

	tNode->left = buildTree(in, pre, inStrt, inIndex - 1);
	tNode->right = buildTree(in, pre, inIndex + 1, inEnd);

	return tNode;
}

int search(int arr[], int strt, int end,int value)
{
	int i;
	for (i = strt; i <= end; i++)
	{
		if (arr[i] == value)
    {
			return i;
    }
    
	}
  return -1;
}

struct node* newNode(int data)
{
	struct node* Node =(struct node*)malloc(sizeof(struct node));
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;

	return (Node);
}

void printInorder(struct node* node)
{
	if (node == NULL)
		return;

	printInorder(node->left);

	printf("%d\n",node->data);

	printInorder(node->right);
}

struct node* minValueNode(struct node* node)
{
    struct node* current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

struct node* deleteNode(struct node* root,int data)
{
    
    if (root == NULL)
        return root;
    if (data< root->data)
        root->left = deleteNode(root->left, data);

    else if (data > root->data)
        root->right = deleteNode(root->right, data);

    else {
        if (root->left == NULL && root->right == NULL)
            return NULL;

        else if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = minValueNode(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main()
{
    int n = 6;
    int* in = (int*)malloc(n*sizeof(int));
    int* pre = (int*)malloc(n*sizeof(int));
    FILE* fp;
    fp=fopen("infile.txt","r");
    if (fp==NULL)
    {
     printf("Input file opening failed.\n");
     return 0;
    }
    char next; int i = 0, j = 0;
    bool test = 0;
    
    
    while (next!=EOF)
        {
        if (next == 'S')
            {
            next=fgetc(fp);
            if(test==0)
                in[i++]=(int)next-48;
            else
                pre[j++]=(int)next-48;
            }
        if (next == ';')
            test =1;
        next=fgetc(fp);
        }
    fclose(fp);

		struct node* root = buildTree(in, pre, 0, n- 1);
        root = deleteNode(root, 3);
        printf("Inorder traversal\n");
        printInorder(root);

    return 0;
}

