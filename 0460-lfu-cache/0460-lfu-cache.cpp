class Node{
    public:
    int key,val,freq;
    Node* prev;
    Node* next;
    Node(int k,int v){
        key=k;
        val=v;
        freq=1;
        prev=next=nullptr;
    }
};


class List{
    public:
    int size;
    Node* head;
    Node* tail;

    List(){
        size=0;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }

    void addfront(Node*node){
        Node* temp=head->next;
        node->next=temp;
        node->prev=head;
        head->next=node;
        temp->prev=node;
        size++;
    }

    void removenode(Node*node){
        Node* prevnode=node->prev;
        Node* nextnode=node->next;
        prevnode->next=nextnode;
        nextnode->prev=prevnode;
        size--;
    }
};


class LFUCache {
public:
    unordered_map<int,Node*>keynode;
    unordered_map<int,List*>freqlist;
    int capacity;
    int minfreq;
    int currsize;

    LFUCache(int capacity) {
        this->capacity=capacity;
        minfreq=0;
        currsize=0;    
    }

    void updatefreq(Node* node){
        keynode.erase(node->key);
        freqlist[node->freq]->removenode(node);
        if(node->freq==minfreq && freqlist[node->freq]->size==0)minfreq++;
        node->freq++;

        List* nexthigherfreqlist=new List();
        if(freqlist.find(node->freq)!=freqlist.end()){
            nexthigherfreqlist=freqlist[node->freq];
        }
        nexthigherfreqlist->addfront(node);
        freqlist[node->freq]=nexthigherfreqlist;
        keynode[node->key]=node;
    }
    
    int get(int key) {
        if(keynode.find(key)==keynode.end())return -1;
        Node* node=keynode[key];
        int ans=node->val;
        updatefreq(node);
        return ans;
    }
    
    void put(int key, int value) {
        if(capacity==0)return;
        if(keynode.find(key)!=keynode.end()){
            Node* node=keynode[key];
            node->val=value;
            updatefreq(node);
            return;
        }
        if(currsize==capacity){
            List* list=freqlist[minfreq];
            Node* nodetoremove=list->tail->prev;
            keynode.erase(nodetoremove->key);
            list->removenode(nodetoremove);
            currsize--;
        }
        currsize++;
        minfreq=1;
        List* listfreqone=new List();

        if(freqlist.find(minfreq)!=freqlist.end()){
            listfreqone=freqlist[minfreq];
        }
        Node* node = new Node(key,value);
        listfreqone->addfront(node);
        keynode[key]=node;
        freqlist[minfreq]=listfreqone;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */