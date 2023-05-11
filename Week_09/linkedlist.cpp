#include <iostream>
using namespace std;

struct Node {

    /* data */
    string user_name;
    string password;
    Node *link;
};

struct LinkedList{

    Node * head = NULL;
    Node * tail = NULL;

    int length = 0;

    void insert(string user_name,string password){
        if (head==NULL){
            Node * temp;
            temp = new Node;
            temp->user_name = user_name;
            temp->password = password;

            temp->link = NULL;
            head = temp; 
            length++;
        }
        else{

            Node * temp;
            Node * prev;
            Node * tail;

            temp = new Node;
            temp->user_name = user_name;
            temp->password = password;
            temp->link = NULL;
            tail = head;
            while (true){
                
                if (tail->link== NULL){
                    break;
                }
                else{
                    tail = tail->link;
                }
            }
            tail->link = temp;
            length++;
        }
    }

    void search(string user_name){
        Node * temp = head;
        for(int i=0;i<length;i++){
            if(temp->user_name==user_name){
                cout<<"Password: "<<temp->password<<"\n";
                break;
            }
            else{
                temp = temp->link; 
            }
        }
    }

    void print_list(){
        if (head == NULL){
            cout<<"[]"<<endl;
        }
        else{
            Node * temp = head;
            cout<< "[";
            while (temp != NULL){
                cout<<temp->user_name<<", ";
                temp = temp->link;
            }
             cout<< "]"<<endl;
        }
    }


};
