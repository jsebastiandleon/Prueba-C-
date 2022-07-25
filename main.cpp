#include <iostream>
#include <random>
#include <chrono>

using namespace std;

class Node {
public:
    string data;
    Node* next;

    Node()
    {
        data = " ";
        next = NULL;
    }

    Node(string data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Linkedlist {
    Node* head;

public:

    Linkedlist() { head = NULL; }

    void insertNode(string);

    void printList();

    void deleteNode(int);
};


void Linkedlist::deleteNode(int nodeOffset)
{
    Node *temp1 = head, *temp2 = NULL;
    int ListLen = 0;

    if (head == NULL) {
        cout << "Lista vacia." << endl;
        return;
    }

    while (temp1 != NULL) {
        temp1 = temp1->next;
        ListLen++;
    }

    if (ListLen < nodeOffset) {
        cout << "Index fuera del rango de la lista"
             << endl;
        return;
    }


    temp1 = head;

    if (nodeOffset == 1) {
        head = head->next;
        delete temp1;
        return;
    }

    while (nodeOffset-- > 1) {
        temp2 = temp1;
        temp1 = temp1->next;
    }

    temp2->next = temp1->next;

    delete temp1;
}


void Linkedlist::insertNode(string data)
{
    Node* newNode = new Node(data);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {

        temp = temp->next;
    }

    temp->next = newNode;
}

void Linkedlist::printList()
{
    Node* temp = head;

    if (head == NULL) {
        cout << "List empty" << endl;
        return;
    }

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}


static std::string generate_uuid(size_t len, int random_aux) {

  static const char x[] = "0123456789abcde";

    std::string uuid;
    uuid.reserve(len);

    std::random_device rand;
    std::mt19937 gen(rand() + random_aux);

    std::uniform_int_distribution < > dis(0, sizeof(x) - 2);
    uuid.erase();

    for (size_t i = 0; i < len; i++){
        uuid += x[dis(gen)];
    }

  return uuid;
}

std::string timeToString(std::chrono::system_clock::time_point &t)
{
    std::time_t time = std::chrono::system_clock::to_time_t(t);
    std::string time_str = std::ctime(&time);
    time_str.resize(time_str.size() - 1);
    return time_str;
}

int main()
{

    Linkedlist list;

    srand(time(NULL));

    int random_aux;
    string id_proceso;

        for (int i=1; i< 1001 ;i++){
            auto time_p = std::chrono::system_clock::now();
            random_aux = rand();
            id_proceso= generate_uuid(10,random_aux);
            cout << timeToString(time_p) + " > order  [" + id_proceso +"] "<< i <<" was successfully prosecuted"<< endl;
            list.insertNode(id_proceso);

            if (i == 10 || i == 121 || i == 510 || i == 770 ||  i == 900 || i== 988 || i==1000 )
                    cout << timeToString(time_p) + " Total orders executed: " << i << "/"  << "1000" << endl;
        }
    return 0;
}
