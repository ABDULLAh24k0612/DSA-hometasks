    
#include<iostream>
using namespace std;

class node{
   public :
		string name;
        int price;
		node*next;
		
		node(string name,int price){
			this->name=name;
            this->price=price;
			next=NULL;
		}
};
class cart{

    public:
    node*head;
    node*tail;

    cart(){
        head=tail=NULL;
    }

    void push_front(string name,int price){
		
		node*newnode=new node(name,price);
		if(head==NULL){
			head=tail=newnode;
		}
		else{
			newnode->next=head;
			head=newnode;
		}
	}

    void push_end(string name,int price){
		
		node*newnode=new node(name,price);
		if(head==NULL){
			head=tail=newnode;
		}
		else{
			tail->next=newnode;
			tail=newnode;
		}
	}

    void insertafter(string name,int price,string targetname){
		node*temp=head;
		node*newnode=new node(name,price);
		while(temp->name!=targetname){
			temp=temp->next;
		}
		newnode->next=temp->next;
		temp->next=newnode;
		
		}

        void search(string targetname){
           node*temp=head;

           while(temp!=NULL){
            if(temp->name==targetname){
                cout<<"price of this "<< temp->name << "is:"<< temp->price<< endl; 
            }
            temp=temp->next;
           }
        }

        void display(){
            node*temp=head;
            while(temp!=NULL){
               cout<< "name="<<temp->name<<","<<"price="<<temp->price<<endl;
               temp=temp->next; 

            }
            
        }

};
int main() {
    cart c;

    
    c.push_end("Laptop", 1000);
    c.push_end("Phone", 700);
    c.push_end("Tablet", 400);
    c.push_end("Headphones", 150);

    
    c.push_front("Smartwatch", 200);

    
    c.push_end("Keyboard", 80);

    
    c.insertafter("Monitor", 300, "Phone");

   
    c.search("Tablet");

    
    cout << "\nFull cart contents:\n";
    c.display();

    return 0;
}
