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
#include <cstdlib>
#include <ctime>

using namespace std;

class Node {
    int data;
    Node *next;
    friend class CircularList;

public:
    Node (int data) : data(data), next(nullptr) {} // Node class constructor
    int getData() const { return data;} 
    void setData(int newData) {data = newData;}

};

class CircularList {
    Node *head;
    int size; 

public:
    CircularList(int size);

    void insertData (int data, int index);
    Node *removeData (int index);
    Node *checkData (int index);

    int getLength() const {return size;}
    void traverseList ();

    void swap(int index);
    void bubbleSort();
};

CircularList::CircularList (int size) : head(nullptr), size(size) {
    Node *newNode = new Node(0);
    for (int i = 0; i < size; i++){
        if (i == 0){
            head = newNode;
        }
        if (i == size - 1){
            newNode->next = head;
            break;
        }
        
        Node *previousNode = newNode;
        newNode = new Node(0);

        previousNode->next = newNode;
    }
}

void CircularList::traverseList (){
    Node *currentNode = head; 

    for (int i = 0; i < size; i++){
        cout << currentNode->data << "\t";
        currentNode = currentNode->next;
    }

    cout << endl;
}

void CircularList::insertData (int data, int index) {
    if (index >= size)
        cout << "Invalid index." << endl;
    else { 
        Node *currentNode = head; 
        for (int i = 0; i < index; i++)
            currentNode = currentNode->next;
        currentNode->setData(data);
    }

}

Node *CircularList::removeData (int index){
    if (index >= size){
        cout << "Invalid index." << endl;
        return nullptr;
    }

    Node *currentNode = head; 
        for (int i = 0; i < index; i++)
            currentNode = currentNode->next;

        Node *aux = new Node(currentNode->getData());
        currentNode->setData(0);
        return aux; 

}

Node *CircularList::checkData (int index){
    if (index >= size){
        cout << "Invalid index." << endl;
        return nullptr;
    }

    Node *currentNode = head; 
        for (int i = 0; i < index; i++)
            currentNode = currentNode->next;

        return currentNode; 

}

void CircularList::swap(int index){
    if (index < size-1){
        int aux = checkData(index)->getData();
        checkData(index)->setData(checkData(index+1)->getData());
        checkData(index+1)->setData(aux);
    }
}

void CircularList::bubbleSort(){
    bool swapped;
    Node* currentNode;
    for (int i = 0; i < size - 1; i++) {
        currentNode = head;
        swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            Node* nextNode = currentNode->next;
            if (currentNode->data > nextNode->data) {
                int temp = currentNode->data;
                currentNode->data = nextNode->data;
                nextNode->data = temp;
                swapped = true;
            }
            currentNode = nextNode;
        }
        if (!swapped) {
            break;
        }
    }
}

class Polygon{
    CircularList *xCoord;
    CircularList *yCoord;

public:
    Polygon (int size);
    void insertDataX(int data, int index) {xCoord->insertData(data, index);}
    void insertDataY(int data, int index) {yCoord->insertData(data, index);};
    void printPoints();
};

Polygon::Polygon(int size){
    xCoord = new CircularList(size);
    yCoord = new CircularList(size);
}

void Polygon::printPoints(){
    cout << "X: "; xCoord->traverseList();
    cout << "Y: "; yCoord->traverseList();
}


int main(){

    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif

    int index = 1;
    int data, pos;

    int size;

    cout << "What should be the circular list's size?" << endl;
    cin >> size; 
    CircularList *myList = new CircularList(size);

    do
    {
        cout << "Circular List: "; myList->traverseList();
        cout << "1 - Insert random data" << endl;
        cout << "2 - Insert data" << endl;
        cout << "3 - Remove data" << endl;
        cout << "4 - Check data" << endl;
        cout << "5 - Swap data" << endl;
        cout << "6 - Bubble Sort" << endl;
        cout << "0 - Exit" << endl;
        cin >> index;

        #ifdef _WIN32
        system("cls");
        #else
        system("clear");
        #endif

        switch (index){
        case 1:
            srand(time(0));
            for (int i = 0; i < size; i++)
                myList->insertData(rand() % 20, i);
            break;

        case 2:
            cout << "Data to insert: "; cin >> data;
            cout << "Position to insert: "; cin >> pos;
            myList->insertData(data, pos);
            break;

        case 3:
            cout << "Position to remove: "; cin >> pos;
            cout << "Data remove: "<< myList->removeData(pos)->getData() << endl;
            break;

        case 4:
            cout << "Position to check: "; cin >> pos;
            cout << "Data checked: "<< myList->checkData(pos)->getData() << endl;
            break;
        case 5:
            cout << "Position to swap (with next): "; cin >> pos;
            myList->swap(pos);
            break;

        case 6:
            myList->bubbleSort();
            break;
        
        default:
            break;
        }

    } while (index != 0);
    
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif

    cout << "How many points should form the polygon? \t"; cin >> size;

    Polygon *shape = new Polygon(size);

    index = 1;

    do
    {
        cout << "Coordinates:" << endl;
        shape->printPoints();
        cout << "1 - Create random points" << endl;
        cout << "0 - Exit" << endl;
        cin >> index;

        switch (index)
        {
        case 1:
            srand(time(0));
            for (int i = 0; i < size; i++){
                shape->insertDataX(rand() % 20, i);
                shape->insertDataY(rand() % 20, i);
            }
            break;
        
        default:
            break;
        }

    } while (index != 0);
    

    





    return 0;
}   