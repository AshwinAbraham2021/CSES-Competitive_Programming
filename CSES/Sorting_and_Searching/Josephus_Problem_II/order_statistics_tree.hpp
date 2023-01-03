#ifndef ORD_STAT_TREE_HPP
#define ORD_STAT_TREE_CPP

#include <functional>
#include <set>
#include <utility>
#include <cstdint>
template <typename T, typename less = std::less<T>> // less must be a total order on Ts inserted
class Set {
    struct Node {
        T obj;
        std::size_t rank;
        bool black;
        Node *parent;
        Node *left;
        Node *right;


        Node(const T &, bool = true, Node * = nullptr, Node * = nullptr, Node * = nullptr); // parent, left, right
        Node(const Node &);
        Node &operator=(const Node &);
        Node(Node &&);
        Node &operator=(Node &&);
        ~Node();
    } *root;

    uint8_t child_p(const Node*) const; // 0 -> left, 1 -> right, 2 -> root, 3 -> nullptr
    std::size_t rank(const Node *) const;
    bool is_black(const Node *) const;
    std::size_t black_height(const Node *) const; // number of black nodes (excluding given, including null) on any (downward) path from node to null
    void left_rotate(Node *); // ptr and ptr->right must not be null
    void right_rotate(Node *); // ptr and ptr->left must not be null

    public:
        Set<T, less>();
        Set<T, less>(const std::set<T, less> &s);
        Set<T, less>(const Set<T, less> &);
        Set<T, less>(Set<T, less> &&);
        Set<T, less> &operator=(const Set<T, less> &);
        Set<T, less> &operator=(Set<T, less> &&);
        ~Set<T, less>();

        class iterator {
            Node* ptr;

            public:
                const T &operator*() const; // val at iterator (UB if end())
                const T *operator->() const; // val->_ (UB if end())
                iterator prev() const; // iterator to predecessor of value (returns iterator to largest element if end()), returns end() if begin()
                iterator next() const; // iterator to successor of value (returns end() if end())
                iterator &operator++();
                iterator operator++(int);
                iterator &operator--();
                iterator operator--(int);
                bool operator==(const iterator &);
                bool operator!=(const iterator &);
                iterator(Node* = nullptr);
        };

        std::pair<iterator, bool> insert(const T &); // (iterator to prev existing element or newly inserted element, whether insertion changed set)
        // std::pair<iterator, bool> erase(const T &); // (iterator to upper_bound(val) in set after erase, whether erase changed set)
        // iterator erase(const iterator &); // iterator to upper_bound(*it) in set after erase (does nothing if it == end())
        iterator find(const T &) const; // returns it such that *it == val or end() if val not in set
        iterator lower_bound(const T &) const; // returns iterator to smallest element not less than val (end() if all elements are less than val)
        iterator upper_bound(const T &) const; // returns iterator to smallest element greater than val (end() if no element is greater than val)
        iterator begin() const; // iterator to smallest element in set (end() iff set is empty)
        iterator end() const; // iterator to one past largest element in set
        std::size_t greater(const T &) const; // number of elements in set greater than val
        std::size_t lesser(const T &) const;  // number of elements in set less than val
        std::size_t in_range(const T &, const T &) const; // number of elements in set >= val1 and <= val2 (UB if less(val1, val2))
        std::size_t size() const; // number of elements in set
        bool empty() const; // is set empty
};

template <typename T, typename less>
Set<T, less>::Node::Node(const T &obj, bool black, Node *parent, Node *left, Node *right): obj(obj), black(black), left(left), right(right), parent(parent)
{
    rank = 1 + (left == nullptr ? 0 : left->rank) + (right == nullptr ? 0 : right->rank);
}

template <typename T, typename less>
uint8_t Set<T, less>::child_p(const Set<T, less>::Node* ptr) const // 0 for left, 1 for right, 2 for root, 3 for null
{
    if(ptr == nullptr) return 3;
    else if(ptr->parent == nullptr) return 2;
    else return ptr->parent->right == ptr;
}

template <typename T, typename less>
std::size_t Set<T, less>::rank(const Set<T, less>::Node *ptr) const
{
    if(ptr == nullptr) return 0;
    return ptr->rank;
}

template <typename T, typename less>
bool Set<T, less>::is_black(const Set<T, less>::Node *ptr) const
{
    return ptr == nullptr || ptr->black;
}

template <typename T, typename less>
std::size_t Set<T, less>::black_height(const Set<T, less>::Node *ptr) const
{
    if(ptr == nullptr) return 0;
    std::size_t bh = 1; // for null at the end
    for(const Node *pptr = ptr->left; pptr != nullptr; pptr = pptr->left)
    {
        if(is_black(pptr)) ++bh;
    }
    return bh;
}

template <typename T, typename less>
Set<T, less>::Node::Node(const Set<T, less>::Node &other): obj(other.obj), rank(other.rank), black(other.black), parent(other.parent)
{
    if(other.left == nullptr) left = nullptr;
    else
    {
        left = new Node(*other.left);
        left->parent = this;
    }

    if(other.right == nullptr) right = nullptr;
    else
    {
        right = new Node(*other.right);
        right->parent = this;
    }
}

template <typename T, typename less>
typename Set<T, less>::Node &Set<T, less>::Node::operator=(const Set<T, less>::Node &other)
{
    if(child_p() == 0) parent->left = nullptr;
    else if(child_p() == 1) parent->right = nullptr;

    delete left;
    delete right;

    parent = other.parent;
    obj = other.obj;
    black = other.black;
    rank = other.rank;

    if(other.left == nullptr) left = nullptr;
    else left = new Node(*left);

    if(other.right == nullptr) right = nullptr;
    else right = new Node(*right);

    return *this;
}

template <typename T, typename less>
Set<T, less>::Node::Node(Set<T, less>::Node &&other): obj(std::move(other.obj)), rank(other.rank), black(other.black), parent(other.parent), left(other.left), right(other.right)
{
    other.left = nullptr;
    other.right = nullptr;
    delete &other;
}

template <typename T, typename less>
typename Set<T, less>::Node &Set<T, less>::Node::operator=(Set<T, less>::Node &&other)
{
    if(child_p() == 0) parent->left = nullptr;
    else if(child_p() == 1) parent->right = nullptr;

    delete left;
    delete right;

    obj = std::move(other.obj);
    rank = other.rank;
    black = other.black;
    parent = other.parent;
    left = other.left;
    right = other.right;

    other.left = nullptr;
    other.right = nullptr;
    delete &other;

    return *this;
}

template <typename T, typename less>
Set<T, less>::Node::~Node()
{
    delete left;
    delete right;
}

template <typename T, typename less>
Set<T, less>::Set(): root(nullptr) {}

template<typename T, typename less>
Set<T, less>::Set(const std::set<T, less> &s): root(nullptr)
{
    for(const auto &obj : s) insert(obj);
}

template<typename T, typename less>
Set<T, less>::Set(const Set<T, less> &other)
{
    if(other.root == nullptr) root = nullptr;
    else root = new Node(*root);
}

template<typename T, typename less>
Set<T, less>::Set(Set<T, less> &&other): root(other.root)
{
    other.root = nullptr;
}

template<typename T, typename less>
Set<T, less> &Set<T, less>::operator=(const Set<T, less> &other)
{
    delete root;
    if(other.root == nullptr) root = nullptr;
    else root = new Node(*root);
}

template<typename T, typename less>
Set<T, less> &Set<T, less>::operator=(Set<T, less> &&other)
{
    delete root;
    root = other.root;
    other.root = nullptr;
}

template<typename T, typename less>
Set<T, less>::~Set()
{
    delete root;
}

template<typename T, typename less>
std::size_t Set<T, less>::size() const
{
    return rank(root);
}

template<typename T, typename less>
bool Set<T, less>::empty() const
{
    return root == nullptr;
}

template <typename T, typename less>
Set<T, less>::iterator::iterator(Node* ptr): ptr(ptr) {}

template <typename T, typename less>
const T &Set<T, less>::iterator::operator*() const
{
    return ptr->obj;
}

template <typename T, typename less>
const T *Set<T, less>::iterator::operator->() const
{
    return &(ptr->obj);
}

template <typename T, typename less>
bool Set<T, less>::iterator::operator==(const Set<T, less>::iterator &other)
{
    return ptr == other.ptr;
}

template <typename T, typename less>
bool Set<T, less>::iterator::operator!=(const Set<T, less>::iterator &other)
{
    return ptr != other.ptr;
}

template<typename T, typename less>
typename Set<T, less>::iterator Set<T, less>::iterator::next() const
{
    if(ptr == nullptr) return iterator();
    else
    {
        Node *pptr = ptr;
        if(pptr->right == nullptr)
        {
            while(true)
            {
                int c;
                if(pptr == nullptr) c = 3;
                else if(pptr->parent == nullptr) c = 2;
                else c = (pptr->parent->right == pptr);

                if(c == 0) return iterator(pptr->parent);
                else if(c == 2) return iterator();
                pptr = pptr->parent;
            }
        }
        else
        {
            pptr = pptr->right;
            while(pptr->left != nullptr) pptr = pptr->left;
            return iterator(pptr);
        }
    }
}

template<typename T, typename less>
typename Set<T, less>::iterator Set<T, less>::iterator::prev() const
{
    if(ptr == nullptr)
    {
        if(root == nullptr) return iterator();
        const Node *pptr = root;
        while(pptr->right != nullptr) pptr = pptr->right;
        return iterator(pptr);
    }
    else
    {
        const Node *pptr = ptr;
        if(pptr->left == nullptr)
        {
            while(true)
            {
                int c;
                if(pptr == nullptr) c = 3;
                else if(pptr->parent == nullptr) c = 2;
                else c = (pptr->parent->right == pptr);

                if(c == 1) return iterator(pptr->parent);
                else if(c == 2) return iterator();
                pptr = pptr->parent;
            }
        }
        else
        {
            pptr = pptr->left;
            while(pptr->right != nullptr) pptr = pptr->right;
            return iterator(pptr);
        }
    }
}

template<typename T, typename less>
typename Set<T, less>::iterator &Set<T, less>::iterator::operator++()
{
    *this = next();
    return *this;
}

template<typename T, typename less>
typename Set<T, less>::iterator Set<T, less>::iterator::operator++(int)
{
    iterator temp = *this;
    *this = next();
    return temp;
}

template<typename T, typename less>
typename Set<T, less>::iterator &Set<T, less>::iterator::operator--()
{
    *this = prev();
    return *this;
}

template<typename T, typename less>
typename Set<T, less>::iterator Set<T, less>::iterator::operator--(int)
{
    iterator temp = *this;
    *this = prev();
    return temp;
}

template<typename T, typename less>
typename Set<T, less>::iterator Set<T, less>::begin() const
{
    if(root == nullptr) return iterator();
    Node *pptr = root;
    while(pptr->left != nullptr) pptr = pptr->left;
    return iterator(pptr);
}

template<typename T, typename less>
typename Set<T, less>::iterator Set<T, less>::end() const
{
    return iterator();
}


template<typename T, typename less>
std::size_t Set<T, less>::greater(const T &val) const
{
    const Node *ptr = root;
    std::size_t num_greater = 0;
    while(ptr != nullptr)
    {
        if(less()(val, ptr->obj))
        {
            num_greater += (1 + rank(ptr->right));
            ptr = ptr->left;
        }
        else if(less()(ptr->obj, val)) ptr = ptr->right;
        else
        {
            num_greater += rank(ptr->right);
            break;
        }
    }
    return num_greater;
}

template<typename T, typename less>
std::size_t Set<T, less>::lesser(const T &val) const
{
    const Node *ptr = root;
    std::size_t num_lesser = 0;
    while(ptr != nullptr)
    {
        if(less()(val, ptr->obj)) ptr = ptr->left;
        else if(less()(ptr->obj, val))
        {
            num_lesser += (1 + rank(ptr->left));
            ptr = ptr->right;
        }
        else
        {
            num_lesser += rank(ptr->left);
            break;
        }
    }
    return num_lesser;
}


template <typename T, typename less>
std::size_t Set<T, less>::in_range(const T &a, const T &b) const // !less(b, a) must be true
{
    return size() - lesser(a) - greater(b);
}

template <typename T, typename less>
typename Set<T, less>::iterator Set<T, less>::find(const T &val) const
{
    const Node *ptr = root;
    while(ptr != nullptr)
    {
        if(less()(val, ptr->obj)) ptr = ptr->left;
        else if(less()(ptr->obj, val)) ptr = ptr->right;
        else return iterator(ptr);
    }
    return iterator();
}

template <typename T, typename less>
typename Set<T, less>::iterator Set<T, less>::lower_bound(const T &val) const
{
    const Node *ptr = root;
    const Node *ptr_to_bigger = nullptr;
    while(ptr != nullptr)
    {
        if(less()(ptr->obj, val)) ptr = ptr->right;
        else if(less()(val, ptr->obj))
        {
            ptr_to_bigger = ptr;
            ptr = ptr->left;
        }
        else return iterator(ptr);
    }
    return iterator(ptr_to_bigger);
}

template <typename T, typename less>
typename Set<T, less>::iterator Set<T, less>::upper_bound(const T &val) const
{
    const Node *ptr = root;
    const Node *ptr_to_bigger = nullptr;
    while(ptr != nullptr)
    {
        if(less()(ptr->obj, val)) ptr = ptr->right;
        else if(less()(val, ptr->obj))
        {
            ptr_to_bigger = ptr;
            ptr = ptr->left;
        }
        else return iterator(ptr).next();
    }
    return iterator(ptr_to_bigger);
}

template <typename T, typename less>
void Set<T, less>::left_rotate(Node *ptr) // ptr and ptr->right must not be null
{
    uint8_t cp = child_p(ptr);
    Node *x = ptr;
    Node *y = ptr->right;
    Node *b = ptr->right->left; // may be null
    Node *d = ptr->parent; // may be null
    x->right = b;
    x->parent = y;
    y->left = x;
    y->parent = d;
    if(b != nullptr) b->parent = x;
    switch(cp)
    {
        case 0: // d->left was x
        {
            d->left = y;
            break;
        }
        case 1: // d->right was x
        {
            d->right = y;
            break;
        }
        case 2: // d was null (x was root)
        {
            root = y;
            break;
        }
    }
    x->rank = 1 + rank(x->left) + rank(x->right);
    y->rank = 1 + rank(y->left) + rank(y->right);
    if(d != nullptr) d->rank = 1 + rank(d->left) + rank(d->right);
}

template <typename T, typename less>
void Set<T, less>::right_rotate(Node *ptr) // ptr and ptr->left must not be null
{
    uint8_t cp = child_p(ptr);
    Node *x = ptr;
    Node *y = ptr->left;
    Node *b = ptr->left->right; // may be null
    Node *d = ptr->parent; // may be null
    x->left = b;
    x->parent = y;
    y->right = x;
    y->parent = d;
    if(b != nullptr) b->parent = x;
    switch(cp)
    {
        case 0: // d->left was x
        {
            d->left = y;
            break;
        }
        case 1: // d->right was x
        {
            d->right = y;
            break;
        }
        case 2: // d was null (x was root)
        {
            root = y;
            break;
        }
    }
    x->rank = 1 + rank(x->left) + rank(y->left);
    y->rank = 1 + rank(y->left) + rank(y->right);
    if(d != nullptr) d->rank = 1 + rank(d->left) + rank(d->right);
}

template <typename T, typename less>
std::pair<typename Set<T, less>::iterator, bool> Set<T, less>::insert(const T &val)
{
    /*
     * A Red Black Tree should satisfy:
     * 1. It should be a BST
     * 2. Every node is either red or black
     * 3. The root is black and nullptr is black
     * 4. Red nodes must have only black children
     * 5. Each path from any node to null must have the same number of black nodes (excluding node, including null)
     * 
     * We first do normal BST insertion and paint the new node red if the new node is not root else paint it black
     * Properties 1, 2, 3, 5 are preserved (5 because null (black) on one path is replaced by a red node with two null (black) children -> the 2 new paths have same black_height)
     * We perform rotations to preserve 4
     */
    if(root == nullptr)
    {
        root = new Node(val);
        return std::pair<iterator, bool>(iterator(root), true);
    }
    Node *ptr = root;
    while(true)
    {
        if(less()(val, ptr->obj))
        {
            if(ptr->left == nullptr)
            {
                ptr->left = new Node(val, false, ptr);
                ptr = ptr->left;
                break;
            }
            else ptr = ptr->left;
        }
        else if(less()(ptr->obj, val))
        {
            if(ptr->right == nullptr)
            {
                ptr->right = new Node(val, false, ptr);
                ptr = ptr->right;
                break;
            }
            else ptr = ptr->right;
        }
        else return std::pair<iterator, bool>(iterator(ptr), false);
    }
    for(Node *pptr = ptr; pptr != nullptr; pptr = pptr->parent) pptr->rank = 1 + rank(pptr->left) + rank(pptr->right);
    Node *pptr = ptr;
    // if ptr->parent is initially black then no rule is violated, simply proceed. Following is true iff we don't just proceed
    /* Before each iteration (true initially as well):
     * 1. ptr is neither root nor null and is red. ptr->parent is neither root nor null and is red. There are no other pairs of red parent, red child
     * 2. Rules 1,2,3,5 are valid
     * 
     * After the last iteration:
     * 1. ptr is not null and is red
     * 2. Rules 1,2,4,5 are valid
     * 3. If root is red, then it is because ptr is root
     */
    while(!is_black(ptr->parent)) // never changing color of ptr
    {
        Node *parent = ptr->parent; // must be red
        Node *gparent = parent->parent; // must be black, not null
        if(child_p(parent) == 0) // either 0 or 1 since parent is not black (therefore it is neither root nor null)
        {
            Node *uncle = parent->parent->right;
            if(!is_black(uncle))
            {
                // changing a black node with two red children to a red node with two black children maintains property 5
                gparent->black = false;
                parent->black = true;
                uncle->black = true;
                ptr = gparent;
            }
            else
            {
                if(child_p(ptr) == 0)
                {
                    parent->black = true;
                    gparent->black = false;
                    right_rotate(gparent);
                    // break; loop anyway breaks
                }
                else
                {
                    ptr = parent;
                    left_rotate(ptr);
                    // goes into above if statement in next iter
                }
            }
        }
        else
        {
            // same with l, r interchanged
            Node *uncle = parent->parent->left;
            if(!is_black(uncle))
            {
                // changing a black node with two red children to a red node with two black children maintains property 5
                gparent->black = false;
                parent->black = true;
                uncle->black = true;
                ptr = gparent;
            }
            else
            {
                if(child_p(ptr) == 1)
                {
                    parent->black = true;
                    gparent->black = false;
                    left_rotate(gparent);
                    // break; anyway breaks
                }
                else
                {
                    ptr = parent;
                    right_rotate(ptr);
                    // goes into above if statement next iter
                }
            }
        }
    }
    root->black = true;
    return std::pair<iterator, bool>(iterator(pptr), true);
}

// template <typename T, typename less>
// typename Set<T, less>::iterator Set<T, less>::erase(const Set<T, less>::iterator &itr)
// {
//     Node *ptr = itr.ptr;
//     if(ptr == nullptr) return iterator();
    
// }
#endif