#ifndef USER_COLLECTION_NODE_H
#define USER_COLLECTION_NODE_H

struct NODE {
    int value;
    NODE* rightNode;
    NODE* leftNode;

    explicit NODE(int newElement) : value(newElement), rightNode(nullptr), leftNode(nullptr){}

    ~NODE(){
        delete rightNode;
        delete leftNode;
    }
};


#endif //USER_COLLECTION_NODE_H
