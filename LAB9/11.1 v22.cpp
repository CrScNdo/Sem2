#include <iostream>

using namespace std;
int list_size;

struct list
{
    list *nptr;
    char data;
};

list* push_back(list * head, char data)
{
    if (list_size == 0)
    {
        list_size++;
        return new list {nullptr, data};
    }
    else
    {
        list* current = head;
        while (current->nptr != nullptr)
        {
            current = current->nptr;
        }
        current->nptr = new list{nullptr, data};
        list_size++;
        return head;
    }
}

void print_list(list* head)
{
    list* current = head;
    while (current)
    {
        cout << current->data << " ";
        current = current->nptr;
    }
    cout << endl;
}

list* delete_at(list* head, int index)
{
    if (head == nullptr || index < 0 || index >= list_size)
    {
        return head;
    }

    if (index == 0)
    {
        list* temp = head;
        head = head->nptr;
        delete temp;
        list_size--;
        return head;
    }

    list* current = head;
    for (int i = 0; current != nullptr && i < index - 1; i++)
    {
        current = current->nptr;
    }

    if (current != nullptr && current->nptr != nullptr)
    {
        list* temp = current->nptr;
        current->nptr = current->nptr->nptr;
        delete temp;
        list_size--;
    }
    return head;
}

list* insert_before(list* head, int index, char* new_elements, int n)
{
    if (index < 0 || index >= list_size)
    {
        cout << "Invalid index!" << endl;
        return head;
    }

    if (index == 0) {
        for (int i = 0; i < n; i++)
        {
            list* new_node = new list{head, new_elements[i]};
            head = new_node;
            list_size++;
        }
        return head;
    }

    list* current = head;
    for (int i = 0; current != nullptr && i < index - 1; i++) {
        current = current->nptr;
    }

    for (int i = 0; i < n; i++) {
        list* new_node = new list{current->nptr, new_elements[i]};
        current->nptr = new_node;
        current = new_node;
        list_size++;
    }

    return head;
}


void delete_list(list* head)
{
    while (head)
    {
        list* temp = head;
        head = head->nptr;
        delete temp;
    }
}

int main()
{
    char data;
    int n, index;
    list_size = 0;
    list* head = nullptr;
    cout << "How many words to write ?" << endl;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> data;
        head = push_back(head, data);
    }
    print_list(head);
    cout << "Enter number of word to delete" << endl;
    cin >> index;
    head = delete_at(head, index);
    print_list(head);
    cout << "Enter the index before which you want to insert new elements: ";
    cin >> index;
    cout << "Enter the number of elements to insert: ";
    cin >> n;
    char new_elements[n];
    cout << "Enter the new elements to insert:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> new_elements[i];
    }
    head = insert_before(head, index, new_elements, n);
    print_list(head);
    delete_list(head);
    return 0;
}
