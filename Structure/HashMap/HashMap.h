// 碰撞(collision)採用 linked list 解決

#include <stdio.h>

struct Node 
{
    int key;
    int value;
    
    Node* next;
    Node(): key(0), value(0), next(nullptr) {}
    Node(int k, int v): key(k), value(v), next(nullptr) {}
    Node(Node n): key(n.key), value(n.value), next(n.next);
};

class HashMap
{
public:
    HashMap(int size);
    ~HashMap();

    void Insert(Node data);
    void Search(int key);
private:
    int hash_size;
    Node** table;

    int HashFunction(int key);
};
