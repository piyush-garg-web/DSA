class TrieNode {
public:
    char ch;
    TrieNode* children[10];
    bool isTerminal;

    TrieNode(char ch) {
        this->ch = ch;
        for (int i = 0; i < 10; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }

    ~TrieNode() {
    for (int i = 0; i < 10; i++) {
        if (children[i] != NULL) {
            delete children[i];
        }
    }
}
};

class Trie {
    TrieNode* root;

public:
    Trie() { root = new TrieNode('\0'); }

    void insertUtil(TrieNode* root, string word) {
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        TrieNode* child;

        int index = word[0] - '0';
        if (root->children[index] != NULL) {
            child = root->children[index];
        }

        else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insert(string word) { insertUtil(root, word); }

    int prefixLengthUtil (TrieNode* root,string word) {
        int length=0;
        for (int i=0;i<word.length();i++) {
            char ch=word[i];
            int index=ch-'0';
            if (root->children[index]!=NULL) {
                length++;
                root=root->children[index];
            }
            else {
                break;
            }
        }
        return length;
    }

    int prefixLength (string word) {
        return prefixLengthUtil(root,word);
    }

    ~Trie() {
    delete root;
}
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie t;
        for (int i=0;i<arr2.size();i++) {
            t.insert(to_string(arr2[i]));
        }

        int length=0;
        int maxLength=0;

        for (int i=0;i<arr1.size();i++) {
            length=t.prefixLength(to_string(arr1[i]));
            maxLength=max(maxLength,length);
        }

        return maxLength;
    }
};