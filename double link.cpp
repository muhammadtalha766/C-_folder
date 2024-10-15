#include <iostream>
using namespace std;

struct node
{
    int data;
    node *prev;
    node *next;
};

node *head = NULL;

void beginsert();
void lastinsert();
void random_insert();
void begin_delete();
void last_delete();
void random_delete();
void display();
void search();

int main()
{
    int choice = 0;
    while (choice != 9)
    {
        cout << "\n...Choose One Option from the following List...\n"
             << "\n1. Insert in beginning\n2. Insert at last\n3. Insert item at any location\n4. Delete from Beginning\n5. Delete from last\n6. Delete item from any location\n7. Search\n8. Show\n9. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            beginsert();
            break;
        case 2:
            lastinsert();
            break;
        case 3:
            random_insert();
            break;
        case 4:
            begin_delete();
            break;
        case 5:
            last_delete();
            break;
        case 6:
            random_delete();
            break;
        case 7:
            search();
            break;
        case 8:
            display();
            break;
        case 9:
            exit(0);
            break;
        default:
            cout << "Invalid Choice..";
        }
    }
    return 0;
}

void beginsert()
{
    node *ptr = new node();
    int item;
    if (ptr == NULL)
    {
        cout << "\nOVERFLOW";
    }
    else
    {
        cout << "\nEnter value: ";
        cin >> item;
        ptr->data = item;
        ptr->next = head;
        ptr->prev = NULL;
        if (head != NULL)
            head->prev = ptr;
        head = ptr;
        cout << "Item inserted";
    }
}

void lastinsert()
{
    node *ptr = new node();
    node *temp;
    int item;
    if (ptr == NULL)
    {
        cout << "\nOVERFLOW";
    }
    else
    {
        cout << "\nEnter value: ";
        cin >> item;
        ptr->data = item;
        if (head == NULL)
        {
            ptr->next = NULL;
            ptr->prev = NULL;
            head = ptr;
            cout << "Item inserted";
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
            ptr->next = NULL;
            cout << "Item inserted";
        }
    }
}

void random_insert()
{
    int i, loc, item;
    node *ptr = new node();
    node *temp;
    if (ptr == NULL)
    {
        cout << "\nOVERFLOW";
    }
    else
    {
        cout << "Enter Value: ";
        cin >> item;
        ptr->data = item;
        cout << "\nEnter the location: ";
        cin >> loc;
        temp = head;
        for (i = 1; i < loc; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                cout << "\ncan't insert\n";
                return;
            }
        }
        ptr->next = temp->next;
        ptr->prev = temp;
        if (temp->next != NULL)
            temp->next->prev = ptr;
        temp->next = ptr;
        cout << "Item inserted";
    }
}

void begin_delete()
{
    node *ptr;
    if (head == NULL)
    {
        cout << "\nList is empty\n";
    }
    else
    {
        ptr = head;
        head = ptr->next;
        if (head != NULL)
            head->prev = NULL;
        delete ptr;
        cout << "Item deleted from the beginning ...\n";
    }
}

void last_delete()
{
    node *ptr, *ptrl;
    if (head == NULL)
    {
        cout << "\nList is empty";
    }
    else if (head->next == NULL)
    {
        head = NULL;
        delete head;
        cout << "\nOnly node of the list deleted ..\n";
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptrl = ptr;
            ptr = ptr->next;
        }
        ptrl->next = NULL;
        delete ptr;
        cout << "Item deleted\n";
    }
}

void random_delete()
{
    node *ptr, *ptrl;
    int loc, i;

    cout << "\n Enter the location: ";
    cin >> loc;
    ptr = head;
    for (i = 0; i < loc; i++)
    {
        ptrl = ptr;
        ptr = ptr->next;
        if (ptr == NULL)
        {
            cout << "\nCan't delete";
            return;
        }
    }
    if (ptr == head)
    {
        head = ptr->next;
        if (ptr->next != NULL)
            ptr->next->prev = NULL;
    }
    else
    {
        ptrl->next = ptr->next;
        if (ptr->next != NULL)
            ptr->next->prev = ptrl;
    }
    delete ptr;
    cout << "Item deleted\n";
}

void display()
{
    node *temp;
    if (head == NULL)
    {
        cout << "\nList is empty";
    }
    else
    {
        temp = head;
        cout << "\nLinked list elements: ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

void search()
{
    node *temp;
    int item, i = 0;
    temp = head;
    if (temp == NULL)
    {
        cout << "\nEmpty List\n";
    }
    else
    {
        cout << "\nEnter value to be searched: ";
        cin >> item;
        while (temp != NULL)
        {
            i++;
            if (temp->data == item)
            {
                cout << "Item found at location " << i << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Item not found\n";
    }
}
