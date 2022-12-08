//Bushra Ghanem Alzeghabi 2110066
//Bushra Abdulkhaleg Dajam 2110054
#include <stdio.h>
#include <iostream>
using namespace std;

class BSTnode 
{  
    protected: 
int data;
BSTnode* left;
BSTnode*right;
public:
// CONSTRUCTORS  
    BSTnode() {
        left = right = NULL;
}
    BSTnode(int newData) { 
        data=newData;
        right=left=NULL;
    }
    BSTnode(int newData, BSTnode* let, BSTnode* rit) {  
    this->data = newData;
        this->left = let;  
        this->right = rit;
}
    
// ACCESSORS
int getData(){
        return data;
    }
    BSTnode* getLeft(){
        return left;
    
}
BSTnode* getRight(){
        return right;
}

// MUTATORS  
void setData(int data){
        this->data=data;
}
void setLeft(BSTnode*left){
        this->left=left;
}
void setRight(BSTnode*right){
        this->right=right;
}
};
// Class from which we can create fully functional Tree (using linked lists)

class intBST 
{
    protected:
    BSTnode* root;

public:
// CONSTRUCTOR   
    intBST() {
    root=NULL;
}
    
    bool isEmpty(){
        return root==NULL;
    }
    
     bool recursiveSearch(int value){
            recursiveSearch(root, value);
    }
    
    bool recursiveSearch(BSTnode* p, int value) {
        if(p==NULL){
            return false;
        }else{
            if (value == p->getData()){
                return true;
            }else if (value < p->getData()){
                return recursiveSearch(p->getLeft(),value);
            }else{
                return recursiveSearch(p->getRight(),value);
            }
        }
    }
    

    BSTnode*find(int number){
        find(root, number);
    }
    BSTnode* find(BSTnode* p,int value){
    while(p!=NULL){
        if(p->getData()==value){
            return p;
            
        }else if(p->getData() >value){
            p=p->getLeft();
            
        }else{
            p=p->getRight();
            
        }
        
    }
    return NULL;
        }
    void insert(int data) {  
        root = insert(root, data);
    }
    
    BSTnode* insert(BSTnode* p, int data) {  
        if (p == NULL) {
            p = new BSTnode(data);
        }else{
            if (data < p->getData()) {
                p->setLeft(insert(p->getLeft(),data))  ;
            
            }else {
                p->setRight(insert(p->getRight(),data)) ;
            }
}
        return p;
    }
 
void postorder() {
        postorder(root);
}
    void postorder(BSTnode* p) {
        if (p != NULL) {
            postorder(p->getLeft());
            postorder(p->getRight());
            cout<< p->getData()<< ", "<< endl;
        }
}
 
void desendingorder() {
        desendingorder (root);
}
    void desendingorder (BSTnode *p) {
        if (p != NULL) {
            desendingorder (p->getRight());
            cout<<p->getData()<< ", ";
            desendingorder (p->getLeft());
        }
    }
void asendingorder() {
        asendingorder (root);
}
    void asendingorder (BSTnode *p) {
        if (p != NULL) {
            asendingorder (p->getLeft());
            cout<<p->getData()<< ", ";
            asendingorder (p->getRight());
        }
    }
    
void modifiyallNodes(int value) {
        modifiyallNodes(root, value);
}

void modifiyallNodes(BSTnode* p, int value) {
    if (p != NULL) {
        p->setData(p->getData() + value);
        modifiyallNodes(p->getLeft(), value);
        modifiyallNodes(p->getRight(), value);
    }
}

void greaterThan(int n) {
        greaterThan(root, n);
}

 void greaterThan(BSTnode* p, int n) {
        if (p != NULL) {
            greaterThan(p->getLeft(), n);
            if (p->getData() >= n) {
                cout<<p->getData()<< ", "<<endl;
            }
            greaterThan(p->getRight(), n);
        }
}
 
 int nonLeaves() {
        nonLeaves(root);
}
    int nonLeaves(BSTnode* p) {
        if (p == NULL) {
            return 0;
}
        if (p->getLeft() == NULL && p->getRight() == NULL){
            return 0 ;
        } else {
            return 1+ nonLeaves(p->getLeft()) + nonLeaves(p->getRight());
        }
}
 int SumChildren(int n) {
        return SumChildren(root, n);
    }

    int SumChildren(BSTnode* p, int n) {
        int sum = 0;
        if (p == NULL) {
            return 0;
        } else {
            if (p->getData() == n) {
                if (p->getLeft() != NULL) {
                    sum += p->getLeft()->getData();
                }
                if (p->getRight() != NULL) {
                    sum += p->getRight()->getData();
                }

                //  return sum;
            } else if (n < p->getData()) {
                return SumChildren(p->getLeft(), n);
            } else if (n > p->getData()) {
                return SumChildren(p->getRight(), n);
            }

        }
        return sum;
    }
    
     bool IsFullBST() {
        return IsFullBST(root);
    }

     bool IsFullBST(BSTnode* p) {
        if (p == NULL) {
            return false;
        } else {
            // if its is leaf return true
            if (p->getLeft() == NULL && p->getRight() == NULL) {
                return true;
            } // if thave only left child 
            else if (p->getLeft() != NULL && p->getRight() != NULL) {
                return IsFullBST(p->getLeft()) && IsFullBST(p->getRight());
            } else {
                return false;
            }

        }

    }

int divisable7() {
        return divisable7(root);
    }

    int divisable7(BSTnode* p) {
        if (p == NULL) {
            return 0;
        } else if (p->getData() % 7 == 0) {
            return 1 + divisable7(p->getLeft()) + divisable7(p->getRight());
        } else {
            return divisable7(p->getLeft()) + divisable7(p->getRight());
        }
    }
  
};
int main(){   
    int choice;
    int value = 0;
    int element = 0;
    int number;
    cout<<"|---------------------------------------------------------------|"<<endl;
    cout<<"|------------  \t     Binary Search Tree Menu  \t    ------------|"<<endl;
    cout<<"|---------------------------------------------------------------|"<<endl;
    cout<<"|\t1. Insert an item into the tree   \t \t \t|"<<endl;
    cout<<"|\t2. Insert all items into the tree  \t  \t  \t|"<<endl;
    cout<<"|\t3. Print all nodes in ascending order  \t \t \t|"<<endl;
    cout<<"|\t4. Print all nodes in desending order  \t \t \t|"<<endl;
    cout<<"|\t5. Print number of inner nodes of tree \t \t \t|"<<endl;
    cout<<"|\t6. Print number of nodes divisable by 7  \t \t|"<<endl;
    cout<<"|\t7. Print sum of children of some nodes \t \t \t|"<<endl;
    cout<<"|\t8. Determine whether given BST is full BST or not \t|"<<endl;
    cout<<"|\t9. Quit \t\t\t\t \t \t|"<<endl;
    cout<<"|---------------------------------------------------------------|"<<endl;
    cout<<"\n> Please enter your choice: ";
    cin >> value;
    cout << endl;
    // Make a new Tree Linked List called myTree
    intBST *myTree = new intBST();
while(value!=9){

    if (value == 1)
    {
    cout<<"> What is the value do you want to insert in the Tree ";
    cin>>element;
  
    myTree->insert(element); 
    cout << " The element was successfully added to the Tree  \n\n";

    // print postorder traversal of the BST 
    myTree->postorder();    
        
    }
    else if(value==2){
        int d;
        int val;
        cout<<"How many item you want insert : ";
        cin>>d;
        for(int i=0 ; i<d;i++){
            cout<<"\nEnter item :";
            cin>>val;
            cout<<endl;
            if (myTree->recursiveSearch(val)) {
                cout<<"> " << val << " already exists in the tree\n>are not allowed to inserted!!";
            } 
            else {
            myTree->insert(val);
            cout << " The element was successfully added to the Tree  \n";
            }
  
        }
        
    }
    else if(value==3){
        if (myTree->isEmpty()) {
            cout<<"> **(the tree is empty)**"<< endl;
        } 
        else {
            myTree->asendingorder();
        }
    }
    else if(value==4){
        if (myTree->isEmpty()) {
            cout<<">**(the tree is empty)**"<< endl;
        } 
        else {
            myTree->desendingorder();
        }
    }
    else if(value==5){
       if (myTree->isEmpty()) {
            cout<<"> **(the tree is empty)**can not print number of inner nodes of tree";
            cout<<endl;
        } 
        else {
            cout<<"> Number of interior nodes in the tree is: " << myTree->nonLeaves();
            cout<<endl;
        }
    }
    else if(value==6){
        if (myTree->isEmpty()) {
                    cout<<"> **(the tree is empty)**";
                    cout<<endl;
                } else {
                    cout<<"> The number of nodes divisable by 7 are: " << myTree->divisable7();
                    cout<<"     ";
                    cout<<endl;
                }
    }
    else if(value==7){
         if (myTree->isEmpty()) {
                    cout<<endl;
                    cout<<"> **(the tree is empty)**can not print sum of children of some nodes ";
                    cout<<endl;
                } else {
                    cout<<"> Enter the node you want to get sum of its children: ";
                    int n;
                    cin>>n;
                    // if the node is found in BST
                    if (myTree->recursiveSearch(n)) {
                        int sum = myTree->SumChildren(n);
                        // if does not have child
                        if (sum == 0) {
                            cout<<" The node " << n << " dose not have any children !!";
                        } else {
                            cout<<" The sum of children of node " << n << " is: " << sum;
                        }
                        cout<<endl;
                    } // if not found in BST
                    else {
                        cout<<" The node " << n << " does not exist in the BST";
                    }
                }
    }
    else if(value==8){
        if (myTree->isEmpty()) {
            cout<<"> **(the tree is empty)**cannot Determine whether given BST is full BST or not";
            cout<<endl;;
        } 
        else {
            if (myTree->IsFullBST()) {
                cout<<"> The BST is a FULL BST";
            } 
            else {
                cout<<"> The BST is not a FULL BST";
            }
        }
    }
    else{
        cout<<"> wrong input !!"<<endl;
        
    }cout<<"\n\n> Please enter your choice: ";
    cin >> value;
    cout << endl;
}
    return 0;
}
    

