
#include<iostream>

using namespace std;

struct link{
    int data;
    link* next;
};

link *head = nullptr;

void insert(int num){
    if(head == nullptr){
        head = new link();
        head->data = num;
        head->next = nullptr;
    }
    else{
        link* temp1 = head;
        link* temp2 = new link();
        temp2->data = num;
        temp2->next = nullptr;
        while(temp1->next != nullptr){
            temp1 = temp1->next;
        }
        temp1->next = temp2;
    }
}

void display(){
    link* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void middleNode(){
    link* slow = head;
    link* fast = head;
    if(head != nullptr){
        while((fast != nullptr)&&(fast->next != nullptr)){
            slow = slow->next;
            fast = fast->next->next;
        }
        cout<<"Middle node data : "<<slow->data<<endl;
    }
}

void loop(){
    link* slow = head;
    link* fast = head;
    while(slow && fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            cout<<"loop found"<<slow->data<<endl;
            return;
        }
    }
}

void reverse(){
    link *prev = nullptr, *current = head, *next = nullptr;
    while(current != nullptr){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    display();
}

void compareTwoNode(){
   link* temp1 = head;
   link* temp2 = head;
   while((temp1 != nullptr) & (temp2 != nullptr)){
       if(temp1->data != temp2->data){
           cout<<"Not equal"<<endl;
           return;
       }
       temp1 = temp1->next;
       temp2 = temp2->next;
   }
   if(temp1 == temp2){
       cout<<"Equal"<<endl;
   }
   else cout<<"Not equal"<<endl;
}

void deleteLinkList(){
    link* temp = head;
    while(head){
        temp = head->next;
        delete head;
        head = nullptr;
        head = temp;
    }cout<<"Empty node"<<endl;
}

int main()
{
    for(int i = 1; i <=4; i++) insert(i);
    display();
    middleNode();
   // head->next->next->next->next = head->next;  //To make loop
    loop();
    reverse();
    compareTwoNode();
    deleteLinkList();
    display();
    return 0;
}
