#include "HashMap.h"

HashMap::HashMap(int size): hash_size(size)
{
    table = new Node*[size];
    for(int i = 0; i < size; i++) {
        table[i] = 0;      // initialize
    }
}

void HashMap::Insert(Node data)
{
    int index = HashFunction(data.key);
    Node* new_node = new Node(data);

    if(table[index] == NULL) {
        table[index] = new_node;
    }
    else {
        Node* temp = table[index]->next;   // ex: 5->9->NULL, add 4
        table[index]->next = new_node;     //     5->4->9->NULL
        new_node->next = temp;
    }

}

int HashMap::HashFunction(int key)
{
    return key % hash_size;
}