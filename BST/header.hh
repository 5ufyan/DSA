 #include<iostream>
using namespace std;

class IntBinaryTree
{
private:
    struct TreeNode
    {
        int data;
        TreeNode *left;
        TreeNode *right;
    };
    TreeNode *root;

    void destroySubTree(TreeNode *);
    void deleteNode(int, TreeNode *&);
    void makeDeletion(TreeNode *&);
    void displayInOrder(TreeNode *);
    void displayPreOrder(TreeNode *);
    void displayPostOrder(TreeNode *);
   public:
        IntBinaryTree()     // Constructor
        { root = NULL; }
   // ~IntBinaryTree()    // Destructor
       // { destroySubTree(root); }
    void insertNode(int);
    bool searchNode(int);
    void remove(int);
    void showNodesInOrder(void)
        {   displayInOrder(root); }
    void showNodesPreOrder()
        {   displayPreOrder(root); }
    void showNodesPostOrder()
        {   displayPostOrder(root); } 
};


void IntBinaryTree::insertNode(int num)
{
    TreeNode *newNode , *temp;
    newNode = new TreeNode;
    newNode ->data = num;
     newNode->left= newNode->right = NULL;
     if (!root)
     {
         root = newNode;
     }
     else
    {
        temp = root;
     while(temp != NULL)
     {
        if (num < temp->data)
        {
            if (temp->left)
            {
                 temp = temp->left;
            }
            else
            {
                temp->left = newNode;
                break;
            }
           
        }
        else if(num > temp->data)
        {
           if (temp->right)
            {
                 temp = temp->right;
            }
            else
            {
                temp->right = newNode;
                break;
            }
        }
        else
        {
        cout << "Duplicate value found in tree.\n";
          break;
        }

     }
    }
}

void IntBinaryTree::displayInOrder(TreeNode *nodePtr)
{
    if (nodePtr)
    {
       displayInOrder(nodePtr->left);
       cout<<nodePtr->data<<endl;
       displayInOrder(nodePtr->right);
    }
}

void IntBinaryTree::displayPreOrder(TreeNode *nodePtr)
{
   
     if (nodePtr)
    {
         cout<<nodePtr->data<<endl;
       displayPreOrder(nodePtr->left);
       displayPreOrder(nodePtr->right);
    }
}

void IntBinaryTree::displayPostOrder(TreeNode *nodePtr)
{

 if (nodePtr)
    {
        
       displayPostOrder(nodePtr->left);
       displayPostOrder(nodePtr->right);
        cout<<nodePtr->data<<endl;
    }
}

bool IntBinaryTree::searchNode(int num)
{
    TreeNode *temp = root;
    while(temp){
        if (temp->data == num)
        {
           return true;
        }
        else if (temp->data > num){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
   return false;

    
}

void IntBinaryTree::remove(int num)
{
    deleteNode(num , root);
}

void IntBinaryTree::deleteNode(int num, TreeNode *&nodePtr)
{
    if (num < nodePtr->data)
    {
        deleteNode(num , nodePtr->left);
    }
    else if (num > nodePtr->data)
    {
       deleteNode(num , nodePtr->right);

    }
    else
    {
        makeDeletion(nodePtr);
    }

}

void IntBinaryTree::makeDeletion(TreeNode *&nodePtr){
    TreeNode *temp;
    if (nodePtr == NULL)
    {
        cout<<"Node is Already empty \n";

    }
    else if ( nodePtr->right== NULL)
    {
        temp = nodePtr;
        nodePtr = nodePtr->left;
        delete temp;
    }
    else if( nodePtr->left == NULL)
    {
          temp = nodePtr;
        nodePtr = nodePtr->right;
        delete temp;
    }
    else
    {
        temp = nodePtr->right;
        while(temp->left)
        {
            temp = temp->left;
        }
        temp->left = nodePtr->left;
        temp = nodePtr;
        nodePtr = nodePtr->right;
        delete temp;
    }
}