class Node {
public:
    int key, val;
    Node* prev;
    Node* next;

    Node(int k,int v){
        key=k;
        val=v;
        prev=next=NULL;
    }
};

class LRUCache {
public:
    int cap;
    unordered_map<int,Node*> mp;

    Node* head;
    Node* tail;

    LRUCache(int capacity){
        cap=capacity;

        head=new Node(-1, -1);
        tail=new Node(-1, -1);

        head->next=tail;
        tail->prev=head;
    }

    void remove(Node* node){
        Node* p=node->prev;
        Node* n=node->next;

        p->next=n;
        n->prev=p;
    }
    void insert(Node* node){
        Node* n = head->next;

        head->next = node;
        node->prev = head;

        node->next = n;
        n->prev = node;
    }

    int get(int key){

        if (mp.find(key)==mp.end())
            return -1;

        Node* node = mp[key];

        remove(node);
        insert(node);

        return node->val;
    }

    void put(int key, int value) {

        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->val = value;
            remove(node);
            insert(node);
        }else{
            if(mp.size() == cap) {
                Node* lru = tail->prev;
                remove(lru);
                mp.erase(lru->key);
            }

            Node* node = new Node(key, value);
            insert(node);
            mp[key] = node;
        }
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */