/******************************************************************************
lab 4
Bushra Ghanem Alzeghabi 2110066
Bushra Abdullhaleg Dajam 2110054


*******************************************************************************/

#include <iostream>

using namespace std;


struct node{

    public:
    int data;
    node* next;
};

class LinkedList{
    node* head;
    public:
    void fillLL(){
        int number;
        cout << "How many values do you want to insert: ";
        cin >> number;
        node* temp = nullptr;
        for(int i=0; i<number; ++i)
        {
            head = new node;
            cout << "Value" << i + 1 << ": ";
            cin >> head->data;
            head->next = temp;
            temp = head;
            cout << head->data <<" was successfully inserted into the list.\n";
        }
    };
    
    void printNodes() {
        node* helpPtr = head;
        while (helpPtr != NULL)
        {
            cout << helpPtr->data << ", ";
            helpPtr = helpPtr->next;
        }
    };
    
    int countNodes() {
    node* helpPtr = head;
    int count = 0;
        while (helpPtr != NULL) {
        count++;
        helpPtr = helpPtr->next;
    }
    return count;
    };
    
    void printEvenNodes() {
    node* helpPtr = head;
    while (helpPtr != NULL) {
    if (helpPtr->data % 2 == 0) {
    cout << helpPtr->data << ", ";
    }
    helpPtr = helpPtr->next;
    }
    };
    
    //task 1
    void swapFirstLast() {
        node *temp = head;
        
        //if list has only one node or list is empty
        if(head == NULL || head->next == NULL){
            cout<<"List has only one node or empty"<<endl;
        }
        int v = head->data;
        while(temp!=NULL){
            if(temp->next == NULL){
                head->data = temp->data ;
                temp->data = v;
            }
            temp = temp->next;
        }
    };
    
    //task 2
    
    void countEvenOddNodes (){
        int evenNodes = 0;
        int oddNodes = 0;
        
        
        //if the list is empty
        if(head == NULL){
            cout<<"ERROR. The list is empty"<<endl;
            return; 
        }
        
        node *temp=head;
        while(temp!=NULL){
            if(temp->data %2 == 0)
                evenNodes++;
            else
                oddNodes++;
            temp = temp->next;
        }
        cout<<"\nNumber of even nodes in the list is " <<  evenNodes;
        cout<<"\nNumber of odd nodes in the list is "<<oddNodes;
    };
    
    //task 3
    
    void addNodeAfter (int num){
        node *temp=head;
        
        //if node is not foun in list
        if(temp == NULL){
            cout<<"Node is not present in list or empty"<<endl;
        }
        while(temp!=NULL){
            if(temp->data == num){
                node *newNode = new node();
                newNode->data = num*2;
                newNode->next = temp->next;
                temp->next = newNode;
            }
            temp = temp->next;
        }
    };
    
    //task 4
    void deleteNodeAfter(int num){
        
        if(head == NULL){
        cout<<"List is empty\n";
        return;
        }
        
        node *temp=head;

        while(temp->next != NULL){
            
            if(temp->data == num){
            temp->next = temp->next->next;
            temp->next == NULL;
            return;
            }
            temp = temp->next;
        }
        cout<<"Node with data "<<num<<" not found\n";
        }
    };
    

    
    



int main()
{
    LinkedList list;
    list.fillLL();
    cout << "\nPrinting All Nodes:\n";
    list.printNodes();

    cout << "\n\ncountNodes()";
    cout <<"\nNumbers of nodes in the linked list is: "<<list.countNodes()<<"\n\n";

    cout << "\nprintEvenNodes()\nPrinting Even Nodes.\n";
    list.printEvenNodes();
    cout << "\n\nTask 1: swapFirstLast()\n";
    list.swapFirstLast();
    list.printNodes();
    cout << "\n\nTask 2: countEvenOddNodes()\n";
    list.countEvenOddNodes();

    cout << "\n\nTask 3: addNodeAfter()\n";
    cout<<"Enter the node data after which you want to add a new node: ";
    int num;
    cin >> num;
    list.addNodeAfter(num);
    cout << "\n";
    list.printNodes();

    cout << "\n\nTask 4: deleteNodeAfter()\nEnter the node data after which you want to delete a node: ";

    cin >> num;
    list.deleteNodeAfter(num);
    cout << "\n";
    list.printNodes();


    return 0;
}
