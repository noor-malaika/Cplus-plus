#include <iostream>
#include <string>
using namespace std;
 
struct Node {
  string name;
  string phone;
  Node* next = NULL;
};

class Phonebook{
 private:
  Node* head;

 public:
 
  Phonebook() {
    head = NULL;
  }
  
  bool check(Node *c){
	Node *chck = head;
	while(chck!=NULL){
		if(chck->name==c->name && chck->phone==c->phone){
			return false;
		}
		chck = chck->next;
	}
	return true;
  }
  
  bool check_num_length(Node *n){
  	string s = n->phone;
  	if(s.length()>11){
  		return false;
	}
    for(int i = 0; i<=10; i++){
		if(int(s[i])>57 || int(s[i])<48){
			return false;
		}	
	}
	return true;
  }

  void AddContact() {
    Node* new_node = new Node;
    cout << "Enter name: "; 
    cin>>new_node->name;
    cout<<"Enter phone no: ";
    cin>>new_node->phone;
    bool g = check_num_length(new_node);
    if(g==true){
      if(head == NULL){
        head = new_node;
        cout<<"Contact added successfully!\n";
        return;
      }
      bool f = check(new_node);
      if(f==true){
      	Node* curr = head;
        while (curr->next != NULL) {
          curr = curr->next;
        }
        curr->next = new_node;
        cout<<"Contact added successfully!\n";
	    }
	    else{
	    	cout<<"Contact with the same info already exists in list!\n";
	    	return;
	    }
	  }
	  else{
	  	cout<<"Phone number must be of 11 digits(numbers)!\nPlease enter a valid number.\n";
	  	return;
	  } 
  }

  void RemoveContact() {
    Node* curr = head;
    string name;
    cout << "Enter name: "; 
    cin>>name;
    if(curr == NULL) {
      cout<<"PhoneBook is empty!\n";
      return;
    }
    if(curr->name == name) {
      head = curr->next;
      delete curr;
      cout<<"Contact Deleted!\n";
      return;
    }
    int i = 0;
    while(curr!=NULL){
    	if(curr->name == name){
          i++;
    	}
    	curr = curr->next;
	  }
    if(i>1){
	  	cout<<"More than one record with same name found.\nPlease enter contact number as well!\n";
	  	string phone;
	  	cin>>phone;
	  	curr = head->next;
      Node* prev = head;
	  	while(curr!= NULL) {
      	if(curr->name == name && curr->phone == phone){
        	prev->next = curr->next;
          delete curr;
          cout<<"Contact Deleted!\n";
          return;
      	}
        prev = curr;
      	curr = curr->next;
      }
	  }
    else if(i==1){
      Node *prev = head;
      curr = head;
      while(curr != NULL) {
        if(curr->name == name){
          prev->next = curr->next;
          delete curr;
          cout<<"Contact Deleted!\n";
          return;
        }
        prev = curr;
        curr = curr->next;
      }
    }
    else{
      cout<<"Contact not found!\nTry another name!\n";
      return;
    }
  }

  void Update() {
    if(head == NULL){
      cout<<"Empty list!\n";
      return;
    }
    Node* curr = head;
    string name;
    cout << "Enter name: "; 
    cin>>name;
    int i = 0;
    while(curr!=NULL){
    	if(curr->name == name){
      		cout << curr->name << ": " << curr->phone << endl;
          i++;
    	}
    	curr = curr->next;
	  }
    if(i==1){
      curr = head;
      while(curr!=NULL){
        if(curr->name==name){
          break;
        }
        curr = curr->next;
      }
    }
	  if(i==0){
      	cout<<"Record not found!\n";
      	return;
	  }
	  if(i>1){
	  	cout<<"More than one record with same name found.\nPlease enter contact number as well!\n";
	  	string phone;
	  	cin>>phone;
	  	curr = head;
	  	while(curr!= NULL) {
      	if(curr->name == name && curr->phone == phone){
        		break;
      	}
      	curr = curr->next;
      }
	  }
    cout<<"(1) Update name\n(2) Update contact\n(3) Both\nEnter choice: ";
	  int choice;
    cin>>choice;
    if(choice==1){
    	if(curr->name == name){
      		cout << "Enter updated name: "; 
      		cin>>curr->name;
      		cout<<"Modified!\n";cout<<curr;
      		return;
    	}
	  }
	  else if(choice==2){
      if(curr->name == name){
      		cout << "Enter updated contact number: "; 
      		cin>>curr->phone;
      		cout<<"Modified!\n";
      		return;
      }
	  }
	  else if(choice==3){
      if(curr->name == name){
      		cout << "Enter updated name: "; 
      		cin>>curr->name;
      		cout << "Enter updated contact number: "; 
      		cin>>curr->phone;
      		cout<<"Modified!\n";
      		return;
      }
	  }
	  else{
	  	cout<<"Please select a valid option!\n";
	  	return;
	  }
  }

  void Search() {
    if (head == NULL) {
      cout<<"Empty list!\n";
      return;
    }
    Node* curr = head;
    string name;
    cout << "Enter name: "; 
    cin>>name;
    int i = 0;
    while(curr!=NULL){
    	if(curr->name == name){
      		cout << curr->name << ": " << curr->phone << endl;
      		i++;
    	}
    	curr = curr->next;
	}
	if(i==0)
    	cout<<"Record not found!\n";
  }

  void PrintPhonebook() {
    if (head == NULL) {
      cout<<"Empty list!\n";
      return;
    }
    Node* curr = head;
    cout<<"All records are listed below!\nName| \tContact no\n";
    cout<<"==============================================================="<<endl;
    while (curr != NULL) {
      cout << curr->name << ": " << curr->phone << endl;
      curr = curr->next;
    }
  }

  // Selection sort function
  void SelectionSort() {
    if (head == NULL) {
      cout<<"Empty list!\n";
      return;
    }
    Node* current = head;

    while (current) {
      Node* min_name = current;
      Node* next_node = current->next;

      while (next_node) {
        if (next_node->name < min_name->name) {
          min_name = next_node;
        }
        next_node = next_node->next;
      }
      if (min_name != current) {
        string temp = current->name;
        current->name = min_name->name;
        min_name->name = temp;
        string ph = current->phone;
        current->phone = min_name->phone;
        min_name->phone = ph;
      }
      current = current->next;
    }
    cout<<"Sorted!\n";
    PrintPhonebook();
  }

  void Menu(){
		char choice;
		cout<<"\n\t\t __PhoneBook Manager___"<<endl;
		cout<<"\n\t__Welcome To PhoneBook Manager___"<<endl;
		cout<<"\n\n\tS.No	|  Function		\t|	Description"<<endl;
		cout<<"=========================================================================="<<endl;
		cout<<"\n\t1\t|  Add Contact   \t\t|\t"<<"Insert New Contact"<<endl;
		cout<<"\n\t2\t|  Search Contact\t\t|\t"<<"Search Contact With Name"<<endl;
		cout<<"\n\t3\t|  Update Contact\t\t|\t"<<"Update Contact "<<endl;
		cout<<"\n\t4\t|  Delete Contact\t\t|\t"<<"Delete Contact With Name"<<endl;
		cout<<"\n\t5\t|  Show Records  \t\t|\t"<<"Show Record"<<endl;
		cout<<"\n\t6\t|  Sort PhoneBook\t\t|\t"<<"Chronologically Sort PhoneBook"<<endl;
		cout<<"\n\t7\t|  Exit!         \t\t|\t"<<"Exit PhoneBook"<<endl;
		cout<<"=========================================================================="<<endl;
		cout<<"\nEnter Your Choice"<<endl;
		cin>>choice;
    if(int(choice)<49 || (choice)>55){
      cout<<"Invalid choice!\n";
      Menu();
    }
		switch(choice)
		{
			case '1':
				AddContact();
				Menu();
			case '2':
				Search();
				Menu();
			case '3':
				Update();
				Menu();
			case '4':
				RemoveContact();
				Menu();
			case '5':
				PrintPhonebook();
				Menu();
			case '6':
				SelectionSort();
				Menu();
		  case '7':
		    exit(0);
    }	
  }
};

int main(){
  Phonebook phonebook;
  phonebook.Menu();

  return 0;
}