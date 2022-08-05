struct Node{
    Node* link[26];
    bool flag = false;
    
    bool containsKey(char c){
        return link[c-'a'] != NULL;
    }
    
    void insert(char c){
        link[c-'a'] = new Node();
    }
    
    Node* get(char c){
        return link[c-'a'];
    }
    
    void setEnd(){
        flag = true;
    }
    
    bool isEnd(){
        return flag;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++){
            char c = word[i];
            if(!node->containsKey(c))
                node->insert(c);
            node = node->get(c);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++){
            char c = word[i];
            if(!node->containsKey(c))
                return false;
            node = node->get(c);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i=0;i<prefix.size();i++){
            char c = prefix[i];
            if(!node->containsKey(c))
                return false;
            node = node->get(c);
        }
        return true;
    }
};
