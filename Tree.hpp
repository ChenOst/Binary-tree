namespace ariel{
class Tree{

private:
    struct node{
        int data;
        node* left;
        node* right;
    };

    node* rootValue;

    void   insertPrivate(int data, node* ptr);
    void   printPrivate(node* ptr);
    node*  returnNodePrivate(int data, node* ptr);
    bool   containsPrivate(int data, node* ptr);
    int    sizePrivate(node* ptr);
    int    parentPrivate(int data, node* ptr);
    int    findSmallestPrivate(node* ptr);
    void   removePrivate(int data, node* parent);
    void   removeRoot();
    void   removeMatch(node* parent, node* match, bool left);


public:

    Tree();
    node*  createLeaf(int data);
    void   insert(int data);
    void   print();
    node*  returnNode(int data);
    bool   contains(int data);
    int    right(int data);
    int    left(int data);
    int    size();
    int    parent(int data);
    int    root();
    int    findSmallest();
    void   remove(int data);
    
};
};