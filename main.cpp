#include <stdio.h>
#include <iostream>
using namespace std;

class BSTNode{
public:
    int value;
    BSTNode *lSon, *rSon;
    BSTNode(int value, BSTNode *lSon=NULL, BSTNode *rSon=NULL)
    {
        this->value=value;
        this->lSon=lSon;
        this->rSon=rSon;
    }
};

class BSTree{
    BSTNode *root;
    void inorder(BSTNode*);
    void preorder(BSTNode*);
    void postorder(BSTNode*);
    BSTNode *createTree(int);
    void printTree(BSTNode *,int);
    bool find(BSTNode *,int);
    BSTNode* insert(BSTNode *,int);
public:
    BSTree();
    bool isEmpty();
    void inorder();
    void preorder();
    void postorder();
    void create(int);
    void printTree();
    bool find(int);
    void insert(int);
    bool findNoRec(int);
//    void insertNoRec(int);
};

BSTree::BSTree()
{
    root=NULL;
}

bool BSTree::isEmpty()
{
    if(root)
        return false;
    else
        return true;
}

void BSTree::inorder(BSTNode *root)
{
    if(root!=NULL)
    {
        inorder(root->lSon);
        printf("%d ",root->value);
        inorder(root->rSon);
    }
}

void BSTree::inorder()
{
    inorder(root);
}

void BSTree::preorder(BSTNode *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->value);
        preorder(root->lSon);
        preorder(root->rSon);

    }
}
void BSTree::preorder()
{
    preorder(root);
}

void BSTree::postorder(BSTNode *root)
{
    if(root!=NULL)
    {
        preorder(root->lSon);
        preorder(root->rSon);
        printf("%d ",root->value);

    }
}
void BSTree::postorder()
{
    postorder(root);
}

BSTNode* BSTree:: createTree(int n)
{
    if(n==0)
        return NULL;
    else
    {
        BSTNode *tmpL=createTree(n/2);
        int x;
        scanf("%d",&x);
        BSTNode *tmpR=createTree((n-(n/2))-1);
        return new BSTNode(x,tmpL,tmpR);
    }
}

void BSTree::create(int n)
{
    root=createTree(n);
}
/*void BSTree::printTree(BSTNode* root, int wciecie){
    if(root!=NULL){
        wciecie+=5;
        printTree(root->rSon,wciecie);
        cout.width(wciecie);
        cout << root->value << endl;
        printTree(root->lSon,wciecie);
    }
}*/
void BSTree::printTree(BSTNode *root,int wciecie)
{
    if(root!=NULL)
    {
        wciecie+=5;
        printTree(root->rSon,wciecie);
        for(int i=0;i<wciecie;i++)
            printf(" ");

        printf("%d\n",root->value);

        printTree(root->lSon,wciecie);

    }
}
void BSTree::printTree()
{
    printf("struktura drzewa:\n");
    printTree(root,1);
}

bool BSTree::find(BSTNode *root, int n)
{
    if(root!=NULL)
    {
        if(root->value==n)
            return true;
        if(root->value>n)
            return find(root->lSon,n);
        else
            return find(root->rSon,n);
    }
    return 0;
}

bool BSTree::find(int n)
{
    return find(root,n);
}

BSTNode * BSTree::insert(BSTNode *root, int n)
{
    if(root!=NULL)
    {
        if(root->value<n)
        {
            root->rSon=insert(root->rSon,n);
            return root;
        }
        else if(root->value>n)
        {
            root->lSon=insert(root->lSon,n);
            return root;
        }
        else
        {
            return root;
        }
    }
    else
    {
        root=new BSTNode(n);
        return root;
    }

}
void BSTree::insert(int n)
{
    root=insert(root,n);
}

bool BSTree::findNoRec(int n)
{
    BSTNode* tmp=root;
    while(tmp!=NULL)
    {
        if(tmp->value==n)
            return true;
        else if(tmp->value>n)
            tmp=tmp->lSon;
        else
            tmp=tmp->rSon;
    }
    return false;
}


int main()
{
    int n;
    scanf("%d",&n);
    BSTree drzewko;
    drzewko.create(n);
    printf("Inorder:\n");
    drzewko.inorder();
    printf("\nPreorder\n");
    drzewko.preorder();
    printf("\nPostorder\n");
    drzewko.postorder();
    printf("\n");
    drzewko.printTree();
    printf("Podaj co szukać:\n");
    scanf("%d",&n);

    if(drzewko.findNoRec(n))
        printf("\nTAK\n");
    else
    {
        printf("\nNIE\n");
    }
    drzewko.insert(n);

    drzewko.printTree();
    return 0;
}
