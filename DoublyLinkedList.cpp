/**
* UFRJ - Universidade Federal do Rio de Janeiro
* DMA/IM - Departamento de Matemática Aplicada do Instituto de Matemática
*
* (MAE 016) Top. Eng. Dados B: Estruturas de Dados e seus Algoritmos
*
* Tarefa de Programação 003 – Hierarquia de Classes de Estruturas de Dados Lineares
*
* Prof. Milton R Ramirez (milton@matematica.ufrj.br)
* Data da criação : 01 de Novembro de 2023
* Data da alteração: 04 de novembro de 2023
*
* Autores: 
* Luiza Costa Pacheco - DRE: 119169147
* Eric Silva Kraus - DRE: 115104789
* Felipe Gomes Táparo - DRE: 119959237 
*
**/

#include <iostream>
#include <initializer_list>
#include <string>

using namespace std;

enum Directions {UP_DOWN, DOWN_UP}; 

class Node {
    int data;
    Node *next;
    Node *previous;
    friend class DoublyLinkedList;

public:
    Node (int data) : data(data), next(nullptr), previous(nullptr) {} // Node class constructor
    int getData() const { return data;} 
    void setData(int newData) {data = newData;}

};

class DoublyLinkedList {
    Node *head;
    Node *tail;
    int length; 
    friend class PriorityQueue;

public:
    DoublyLinkedList(initializer_list<int> items);

    void push (int data);
    void push_back (int data);

    int pop ();
    int pop_back ();

    void traverseList (Directions direction);

    int getLength() const {return length;}

    Node *searchFromIndex(int index);
    void swapNodes(int node1, int node2);
    void bubbleSort();
};

DoublyLinkedList::DoublyLinkedList (initializer_list<int> items) : head(nullptr), tail(nullptr), length(0) {
    for (auto &data : items)
        push(data);
}

void DoublyLinkedList::push (int data){
    Node *newNode = new Node(data);


    if (head == nullptr){
        tail = newNode;
    } else {
        newNode->next = head;
        head->previous = newNode;
    }
    head = newNode;
    length++;
}

void DoublyLinkedList::push_back (int data){
    Node *newNode = new Node(data);

    cout << "Node created, data = " << newNode->getData() << "." << endl;

    if (tail == nullptr){
        head = newNode;
    } else {
        newNode->previous = tail;
        tail->next = newNode;
    }
    tail = newNode;
    length++;
}

void DoublyLinkedList::traverseList (Directions direction){
    Node *currentNode;
    currentNode = (direction == UP_DOWN ? head : tail); 
    while (currentNode) { // Will stop when NullNode comes
        cout << currentNode -> data << ", ";
        currentNode = (direction == UP_DOWN ? currentNode->next : currentNode->previous);
    }

    cout << endl;
}

int DoublyLinkedList::pop (){
    if (head == nullptr){
        cout << "Error: no head node to pop." << endl;
        return -1;
    }

    Node *aux = head;

    if(head == tail)
        head = tail = nullptr;
    else{
        head = head->next;
        head->previous = nullptr;
    }
     
    cout << "Data poped: " << aux->getData() << endl;
    length --;
    return aux->getData();
}

int DoublyLinkedList::pop_back (){
    if (tail == nullptr){
        cout << "Error: no tail node to pop." << endl;
        return -1;
    }

    Node *aux = tail;

    if(head == tail)
        head = tail = nullptr;
    else{
        tail = tail->previous;
        tail->next = nullptr;
    }
     
    cout << "Data poped: " << aux->getData() << endl;
    length --;
    return aux->getData();
}

Node *DoublyLinkedList::searchFromIndex(int index){

    if (index >= length || index  < 0 || head == nullptr){ 
        cout << "Error in index value." << endl;
        return nullptr; 
    }
    Node *currentNode = head; 
    for (int i = 0; i < index; i++){
        currentNode = currentNode->next;
    }

    return currentNode;
}

void DoublyLinkedList::swapNodes(int node1, int node2){

    int aux = searchFromIndex(node1)->getData();
    searchFromIndex(node1)->setData(searchFromIndex(node2)->getData());
    searchFromIndex(node2)->setData(aux);
}

void DoublyLinkedList::bubbleSort(){
    if (head == nullptr || head->next == nullptr) {
        return;
    }
    
    bool swapped;
    do {
        swapped = false;
        Node *current = head;
        while (current->next != nullptr) { 
            if (current->data > current->next->data) {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);

}

class PriorityQueue {

    DoublyLinkedList *dll;

public:

    PriorityQueue(initializer_list<int> items);
    void insertItem(int data);
    void traverseList(){dll->traverseList(UP_DOWN);};
    
};

PriorityQueue::PriorityQueue (initializer_list<int> items) {
    dll = new DoublyLinkedList(items);
    dll->bubbleSort();    
}

void PriorityQueue::insertItem(int data){
    int auxData = dll->head->getData();
    int index = 1;
    dll->push(data);
    while (auxData < data){
        dll->swapNodes(index, index-1);
        index++;
        auxData =  dll->searchFromIndex(index)->getData();
    }

}


int main(){

    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif

    int index = 1;
    int aux = 0;
    DoublyLinkedList newList = {0};

    do
    {
        cout << endl << "Double linked list: "; newList.traverseList(UP_DOWN);
        cout << "1 - Start list with specified entries." << endl; 
        cout << "2 - Insert at the beginning." << endl;
        cout << "3 - Insert at the end." << endl;
        cout << "4 - Pop at the beginning." << endl;
        cout << "5 - Pop at the end." << endl;
        cout << "6 - Search data in index" << endl;
        cout << "7 - Swap 2 nodes in list" << endl;
        cout << "8 - Bubble sort list" << endl;
        cout << "9 - Traverse list from top to bottom." << endl;
        cout << "10 - Traverse list from bottom to top." << endl;
        cout << "11 - Check list length." << endl;
        cout << "0 - Finish" << endl;

        cin >> index;

        #ifdef _WIN32
        system("cls");
        #else
        system("clear");
        #endif


        switch (index) {
        case 1:
            cout << "Starting list with {1, 5, 2, 3, 0, 4, 7, 6} elements..." << endl;
            newList = {1, 5, 2, 3, 0, 4, 7, 6};
            break;

        case 2:
            cout << "What element should be pushed?  " ;
            cin >> aux;
            newList.push(aux);
            break;
        
        case 3:
            cout << "What element should be pushed?  " ;
            cin >> aux;
            newList.push_back(aux);
            break;

        case 4:
            newList.pop();
            break;
        
        case 5:
            newList.pop_back();
            break;

        case 6:
            cout << "What is the wanted data's index?  ";
            cin >> aux;
            cout << "List[" << aux << "] = " << newList.searchFromIndex(aux)->getData() << endl;
            break;

        case 7:
            int node1, node2;
            cout << "Enter nodes to swap: ";
            cin >> node1;
            cin >> node2;
            newList.swapNodes(node1, node2);
            break;

        case 8:
            newList.bubbleSort();
            break;    


        case 9:
            newList.traverseList(UP_DOWN);
            break; 

        case 10:
            newList.traverseList(UP_DOWN);
            break; 

        case 11: 
            cout << "List length is " << newList.getLength() << "." << endl;
            break;
    
        default:
            break;
        }

        cout << endl; 
    } while (index != 0);

    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif

    initializer_list<int> items = {16, 15, 5, 20, 5, 7, 6, 11};

    PriorityQueue *queue = new PriorityQueue(items);

    cout << "Priority Queue created. Initial items: 16, 15, 5, 20, 5, 7, 6, 11" << endl;

    do
    {
        cout << "Priority Queue: ";
        queue->traverseList();
        cout << "1 - Insert Item" << endl;
        cout << "0 - Exit" << endl;

        cin >> index;

        #ifdef _WIN32
        system("cls");
        #else
        system("clear");
        #endif

        switch (index)
        {
        case 1:
            cout << "What element should be inserted? " << endl;
            cin >> aux;;
            queue->insertItem(aux);
            break;
        
        default:
            break;
        }
    } while (index != 0);
    



    return 0;
}