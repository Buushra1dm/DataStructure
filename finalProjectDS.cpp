//Bushra Ghanem Alzeghabi 2110066
//Bushra Abdulkhaleg Dajam 2110054
//This our project datastructure
#include<iostream>
#include<conio.h>
#include<string>
using namespace std;

class node {

public:

	string name;
	int id;
	string phoneno;
	string addr;
	float invoice;
	node* next = NULL;
	node(string n_name, int n_id, string n_phoneno, string n_addr, float n_invoice) {
		name = n_name;
		id = n_id;
		phoneno = n_phoneno;
		addr = n_addr;
		invoice = n_invoice;
	}

};
node* head = NULL;

bool CheckRecord(int n_id) {
	int id = n_id;
	node* ptr;
	ptr = head;
	while (ptr != NULL) {
		if (ptr->id == id) {
			return true;
		}
		ptr = ptr->next;
	}
	return false;
}
void CreateRecord() {

	string n_name;
	int n_id;
	string n_phoneno;
	string n_addr;
	float n_invoice;

	while (1) {
		cout << endl << "please enter name : ";
		cin >> n_name;
		cout << endl << "please enter ID : ";
		cin >> n_id;
		cout << endl << "please enter phone# ";
		cin >> n_phoneno;
		cout << endl << "please enter address(no spaces in address) : ";
		cin >> n_addr;
		cout << endl << "please enter total invoice : ";
		cin >> n_invoice;
		if (CheckRecord(n_id) == false) {

			node* newnode = new node(n_name, n_id, n_phoneno, n_addr, n_invoice);
			if (head == NULL) {
				head = newnode;
				return;
			}
			node* temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = newnode;
			return;
			/*newnode->next = head;
			head = newnode;*/
		}
		else {
			cout << "Record Already exists with ID of " << n_id << " please try another ID !!" << endl;
		}
	}

}
void DeleteRecord() {

	int n_id;
	cout <<"**(The record..Invoice with SR 10 will be deleted only)** \nplease enter ID to delete: ";
	cin >> n_id;
	//Delete invoices less than 10 SR only
	if (CheckRecord(n_id) == true) {


		//if node is the head
		if (head->id == n_id && head->invoice < 10) {
			node* temp = head;
			head = head->next;
			free(temp);
			cout<<"Deleted successfully !!"<<endl;
			
		}
		
		else {
			node* temp = head;
			node* prev = head;
			//if (current->next != NULL) current = current->next;
			while (temp->next != NULL) {
				if (temp->next->id == n_id && temp->next->invoice < 10) {
					prev = temp->next;
					temp->next=prev->next;
					free(prev);
					cout<<"Deleted successfully !!"<<endl;
					break;
				}
			    prev = temp;
				temp = temp->next;
			}
				
		}
		
    
	}
	else{
	    cout<<" Invalid ID Unable to delete \ncan not delete because can not find The ID !!"<<endl;
	}

}
void ShowRecord() {

	int n_id;
	cout << endl << "please enter ID to show the record : ";
	cin >> n_id;

	int id = n_id;
	node* ptr;
	ptr = head;
	if (CheckRecord(n_id) == true) {
		while (ptr != NULL) {
			if (ptr->id == id) {
				cout << "ID: " << ptr->id << endl;
				cout << "NAME: " << ptr->name << endl;
				cout << "phone#: " << ptr->phoneno << endl;
				cout << "address: " << ptr->addr << endl;
				cout << "invoice: " << ptr->invoice << endl;
			}
			ptr = ptr->next;
		}
	}
	else {
		cout << "Record with ID " << n_id << " does not exist !!" << endl;
	}

}

void SmartSearchRecord() {
	int n_id;
	cout << endl << "please enter ID for smart record search : ";
	cin >> n_id;
	if (CheckRecord(n_id) == true) {
		int id = n_id;
		node* ptr;
		ptr = head;
		while (ptr != NULL) {
			if (ptr->id == id) {
				cout << "ID: " << ptr->id << endl;
				cout << "NAME: " << ptr->name << endl;
				cout << "phone#: " << ptr->phoneno << endl;
				cout << "address: " << ptr->addr << endl;
				cout << "invoice: " << ptr->invoice << " SR" << endl;
			}
			ptr = ptr->next;
		}
	}
	else{
	   cout << "ID " << n_id << " does not exist !!" << endl;
	}
}
void printall() {
	node* ptr;
	ptr = head;
	while (ptr != NULL) {
		cout << "ID: " << ptr->id << endl;
		cout << "NAME: " << ptr->name << endl;
		cout << "phone#: " << ptr->phoneno << endl;
		cout << "address: " << ptr->addr << endl;
		cout << "invoice: " << ptr->invoice << " SR" << endl;
		ptr = ptr->next;
		cout << "------------------------------------------------------" << endl;
	}
}
void UpdateInvoice() {
    int n_id;
    cout << endl << "*(The invoice with SR greater than 100 will be increased by 15 percent)*\n please enter ID :";
    cin >> n_id;
    node* ptr;
    ptr = head;
    while (ptr != NULL) {
        //ptr = ptr->next; why move to the second node??
        if (ptr != NULL && ptr->id == n_id) {
            //add 15 percent on invoice greater than 100 SR
            float updated_invoice = ptr->invoice;
            if (updated_invoice > 100) {
                float r = updated_invoice * 0.15;
                updated_invoice += r;
                //moved inside
                ptr->invoice = updated_invoice;
                cout<<"Updated successfully !!";
            }//else if less than 100 what will happen?
        //code goes here
        }//after if else befor the end of while
    ptr = ptr -> next;
   }
}

void UpdateRecord() {
	int n_id;
	cout << endl << "please enter the record ID to update the record : ";
	cin >> n_id;
	string n_name;
	string n_phoneno;
	string n_addr;
	float n_invoice;

	bool found = false;
	node* ptr;
	ptr = head;
	while (ptr != NULL) {
		if (ptr->id == n_id) {
			found = true;
			cout << endl << "please enter new name : ";
			cin >> n_name;
			cout << endl << "please enter new phone#  ";
			cin >> n_phoneno;
			cout << endl << "please enter new address : ";
			cin >> n_addr;
			cout << endl << "please enter new total invoice amount : ";
			cin >> n_invoice;
			ptr->name = n_name;
			ptr->phoneno = n_phoneno;
			ptr->addr = n_addr;
			ptr->invoice = n_invoice;
			cout << endl << "Record Updated !! " << endl;
			return;
		}
		ptr = ptr->next;
	}
	if (found == false) {
		cout << endl << "ID does not exist !!" << endl;
	}

}
int main() {

	string Continue= "y";
	
	while (Continue == "y") {
		int option;
		cout << "-------------------Menu-------------------" << endl;
		cout << "Enter 1 to create a Record" << endl;
		cout << "Enter 2 to delete a Record(if less than 10SR)" << endl;
		cout << "Enter 3 to show  a Record" << endl;
		cout << "Enter 4 to update a invoice(increase SR 100 invoice by 15%)" << endl;
		cout << "Enter 5 to smart seach a Record" << endl;
		cout << "Enter 6 to show all patient records" << endl;
		cout << "Enter 7 to Update a Record " << endl;
		cout << "Enter 8 to Exit " << endl;
		cout <<"please Enter your choice : ";
		cin >> option;
		cout << endl;
		if (option == 1) {
			CreateRecord();
		}
		else if (option == 2) {
			DeleteRecord();
		}
		else if (option == 3){
			ShowRecord();
		}
		else if (option == 4) {
			UpdateInvoice();
		}
		else if (option == 5) {
			SmartSearchRecord();
		}
		else if (option == 6) {
			printall();
		}
		else if (option == 7) {
			UpdateRecord();
		}
		else if (option == 8) {
		    cout<<endl<<"Thank You & Bye ";
			break;
		}
		else{
		    cout<<"Incorrect selection!!!"<< endl;
		}
		cout << endl << "Do you want to continue Enter (y) or to stop Enter (n) : " ;
		cin >> Continue;
		cout<<endl;
		
		if(Continue != "n" && Continue != "y"){
	        cout<<"Incorrect entry !!";
	        cout<<"\n\nplease Enter again\n";
	        cout << endl << "Do you want to continue Enter (y) or to stop Enter (n) : " ;
		    cin >> Continue;
		    cout<<endl;
		}
	    if(Continue == "n"){
	        cout<<endl<<"Thank You & Bye ";
	    }
	}
	
    
}