//https://leetcode.com/problems/lru-cache/submissions/
class LRUCache {
    class node {
        public:
        int key, value;
        node *next, *prev;
        node(int _key, int _value){
            key = _key;
            value = _value ;
        }
    };
    
    node *head = new node(-1,-1);
    node *tail = new node(-1,-1);
    
    int cap = 0, cnt = 0;
    
    unordered_map<int,node*> tracker ;
    
public:
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
        cnt = 0 ;
    }
    
    int get(int key) {
        if(tracker.find(key) != tracker.end()){
            node *temp = tracker[key] ;
            int value = temp->value ;
            
            delNode(temp);
            
            setToFront(key,value);
            
            return value ;
        }
        return -1;
    }
    
    void delNode(node *curr){
        node *delPrev = curr->prev ;
        node *delNext = curr->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }
    
    void setToFront(int key, int value){
        node *temp = new node(key,value);
        node *nxt = head->next ;
        head->next = temp;
        temp->next = nxt;
        nxt->prev = temp ;
        temp->prev = head;
        tracker[key] = temp ;
    }
    
    void put(int key, int value) {
        
        if(tracker.find(key) != tracker.end()){
            node *existingNode = tracker[key];
            delNode(existingNode);
            tracker.erase(key) ;
            -- cnt ;
        }
        
        if(cnt == cap){
            int lastKey = tail->prev->key;
            tracker.erase(lastKey);
            delNode(tail->prev) ;
            -- cnt;
        }
            
        setToFront(key,value);  
        cnt ++ ;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
