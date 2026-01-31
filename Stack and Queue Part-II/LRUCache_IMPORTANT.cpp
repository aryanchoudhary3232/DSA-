#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
public:
    class Node
    {
    public:
        int key, value;
        Node *prev;
        Node *next;

        Node(int key, int value)
        {
            this->key = key;
            this->value = value;
            this->prev = NULL;
            this->next = NULL;
        }
    };

    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    unordered_map<int, Node *> mp;
    int capacity;

    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (mp.find(key) != mp.end())
        {
            Node *node = mp[key];

            //remove node
            node->prev->next = node->next;
            node->next->prev = node->prev;

            //add to head
            node->next = head->next;
            head->next->prev = node;
            head->next = node;
            node->prev = head;

            return node->value;
        }

        return -1;
    }

    void put(int key, int value)
    {
        if(mp.find(key) != mp.end()) {
            Node* node = mp[key];

             //remove node
            node->prev->next = node->next;
            node->next->prev = node->prev;

            //add to head
            node->next = head->next;
            head->next->prev = node;
            head->next = node;
            node->prev = head;

            node->value = value;
            return;

        }
        if (mp.size() == this->capacity)
        {
            Node *deletedNode = tail->prev;
            deletedNode->prev->next = tail;
            tail->prev = deletedNode->prev;

            mp.erase(deletedNode->key);
            delete deletedNode;
        }
        Node *newNode = new Node(key, value);
        Node *headNext = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = headNext;
        headNext->prev = newNode;

        mp[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    // Create cache with capacity 2
    LRUCache cache(2);

    // Put values in cache
    cache.put(1, 1);
    cache.put(2, 2);

    // Get value for key 1
    cout << cache.get(1) << endl;

    // Insert another key (evicts key 2)
    cache.put(3, 3);

    // Key 2 should be evicted
    cout << cache.get(2) << endl;

    // Insert another key (evicts key 1)
    cache.put(4, 4);

    // Key 1 should be evicted
    cout << cache.get(1) << endl;

    // Key 3 should be present
    cout << cache.get(3) << endl;

    // Key 4 should be present
    cout << cache.get(4) << endl;
    return 0;
}
