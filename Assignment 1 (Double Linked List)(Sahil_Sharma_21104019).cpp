#include <iostream>
using namespace std;

class node
{
public:
    int Age_Input;
    string Name_Input;
    node *previous;
    node *next;

    node(int Age_Input, string Name_Input)
    {
        this->Age_Input = Age_Input;
        this->Name_Input = Name_Input;
        this->previous = NULL;
        this->next = NULL;
    }
};

node *takeinput()
{
    int Age_Input;
    string Name_Input;
    int count = 0;
    // int terminator;
    node *head = NULL;
    node *temp = head;

    cout << "When the entries are complete , Enter stop when prompted to enter name \n " << endl;
    cout << "Please  enter the name of the family member " << endl;
    cin >> Name_Input;
    if (Name_Input != "stop")
    {
        cout << "Please  enter the age of the family member : " << endl;
        cin >> Age_Input;
    }
    while (Name_Input != "stop")
    {
        node *newnode = new node(Age_Input, Name_Input);

        if (head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        if (temp->next == NULL)
        {
            newnode->previous = temp;
            temp->next = newnode;
            temp = temp->next;
        }
        else
        {

            newnode->previous = temp;
            temp->next = newnode;
            temp = temp->next;
        }

        cout << "Please  enter the name of the family member : " << endl;
        cin >> Name_Input;
        if (Name_Input != "stop")
        {
            cout << "Please  enter the age of the family member : " << endl;
            cin >> Age_Input;
        }
    }
    return head;
}

void printdata(node *head)
{
    node *temp = head;
    cout << "The Data on Family members as Feeded is as follow : \n ";
    while (temp != NULL)
    {
        cout << "The name of Member is \t" << temp->Name_Input << " and Age is \t" << temp->Age_Input << endl;
        temp = temp->next;
    }
}
int main()
{
    cout << "\n Data Structures Assignment-1 \n \n Submitted by \t Sahil Sharma \n Branch \t Electrical \n SID \t \t  21104019 \n \n " ;
    cout << "Creating A Doubly linked list with Family members as elements \n ";
    node *head = takeinput();
    printdata(head);
    cout << " \n  Thank You \n " ;
    return 0;
}