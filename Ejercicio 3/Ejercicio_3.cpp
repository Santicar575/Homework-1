#include <iostream>
#include <memory>

//Declaracion de structs
using node_t = struct node{
    int data;
    std::shared_ptr<node> next;
};

using list_t = struct{
    std::shared_ptr<node_t> head;
    std::shared_ptr<node_t> tail;
    int size=0;
};

//Declaracion de funciones
std::shared_ptr<node_t> create_node(int value);
void push_front(std::shared_ptr<list_t>& list, std::shared_ptr<node_t> node);
void push_back(std::shared_ptr<list_t>& list, std::shared_ptr<node_t> node);
void insert(std::shared_ptr<list_t>& list, std::shared_ptr<node_t> node, int pos);
void erase(std::shared_ptr<list_t>& list, int pos);
void print_list(std::shared_ptr<list_t>&list);

int main(){
    std::shared_ptr<list_t> list = std::make_shared<list_t>();
    //Prueba push_front()
    push_front(list,create_node(1));
    push_front(list,create_node(2));
    print_list(list);
    //Prueba push_back()
    push_back(list,create_node(3));
    push_back(list,create_node(4));
    print_list(list);
    //Prueba insert en posicion mayor al size de la lista
    insert(list,create_node(6),100);
    //Prueba insert en diferentes posiciones
    insert(list,create_node(5),5);
    insert(list,create_node(0),0);
    insert(list,create_node(100),3);
    print_list(list);
    //Prueba erase en posicion mayor al size de la lista
    erase(list,100);
    //Prueba erase en diferentes posiciones
    erase(list,5);
    erase(list,0);
    print_list(list);
}

std::shared_ptr<node_t> create_node(int value){
    std::shared_ptr<node_t> aux_node = std::make_shared<node_t>();
    aux_node->data = value;
    aux_node->next = nullptr;
    return aux_node;
}

void push_front(std::shared_ptr<list_t>& list, std::shared_ptr<node_t> node){
    if(!list->head){
        list->head = node;
        list->tail = node;
        list->size++;
        return;
    }
    node->next = list->head;
    list->head = node;
    list->size++;
}

void push_back(std::shared_ptr<list_t>& list, std::shared_ptr<node_t> node){
    if(!list->tail){
        push_front(list,node);
    }
    list->tail->next = node;
    list->tail = node;
    list->size++;
} 

void insert(std::shared_ptr<list_t>& list, std::shared_ptr<node_t> node, int pos){
    if(pos >= list->size){
        //Si no existe la posicion se inserta al final
        std::cout<<"No existe la posisicon "<<pos<<". El nodo fue insertado al final de la lista"<<std::endl;
        push_back(list,node);
        return;
    }
    if(pos == 0){
        //Si la posicion es 0 se inserta al inicio
        push_front(list,node);
        return;
    }
    int aux = 0;
    std::shared_ptr<node_t> aux_node = list->head;
    //Avanzo hasta llegar a la posicion anterior a la que quiero insertar
    while(aux != pos){
        aux_node = aux_node->next;
        aux++;
    }
    node->next = aux_node->next;
    aux_node->next = node;
    list->size++;
}

void erase(std::shared_ptr<list_t>& list, int pos){
    int aux = 0;
    std::shared_ptr<node_t> aux_node = list->head;
    if(pos == 0){
        //Si la posicion es 0 se elimina el primer nodo
        list->head = list->head->next;
        list->size--;
        return;
    }
    if(pos >= list->size){
        std::cout<<"No existe la posisicon "<<pos<<". Se elimino el ultimo nodo"<<std::endl;
        //La nueva posicion es la ultima
        pos = list->size -1;
    }
    //Avanzo hasta llegar al nodo anterior al que quiero borrar
    while(aux != pos-1){
        aux_node = aux_node->next;
        aux++;
    }
    //Borro el nodo en la posicion pos
    aux_node->next = aux_node->next->next;
    list->size--;
}

void print_list(std::shared_ptr<list_t>& list){
    std::shared_ptr<node_t> aux_node = list->head;
    while(aux_node->next != nullptr){
        std::cout<<aux_node->data<<"->";
        aux_node = aux_node->next;
    }
    std::cout<<aux_node->data<<std::endl;
}
