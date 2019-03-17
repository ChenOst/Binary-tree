namespace ariel{
class Tree{

private:
    struct node{
        int data;
        node* left;
        node* right;
    };

    node* rootValue;

    void  insertPrivate(int data, node* ptr);
    void  printPrivate(node* ptr);
    node* ReturnNodePrivate(int data, node* ptr);
    bool  containsPrivate(int data, node* ptr);
    int   sizePrivate(int data, node* ptr);
    node*  parentPrivate(int data, node* ptr);
    void  removePrivate(int data, node* ptr);
    void  removeRoot();
    int   findSmallestPrivate(node* ptr);

public:

    Tree();
    node* CreateLeaf(int data);
    void  insert(int data);
    void  print();
    node* ReturnNode(int data);
    bool  contains(int data);
    node*  right(int data);
    node*  left(int data);
    int   size();
    node*  parent(int data);
    node*  root();
    void  remove(int data);
    int   findSmallest();
    void  removeMatch(node* parent, node* match, bool left);

};
};