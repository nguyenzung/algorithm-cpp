#ifndef LIST_H
#define LIST_H

template <class T>
class List {
    
    class Node {
    protected:
        T _value;
        Node *_next;
        Node *_prev;
        
    public:
        Node():_next(nullptr), _prev(nullptr){}
        Node(T value):_value(value),_next(nullptr), _prev(nullptr){}
        
        void addNext(Node *next) { this->_next = next; }
        
        void addPrev(Node *prev) { this->_prev = prev; }
        
        Node* next() { return this->_next; }
        
        Node* prev() { return this->_prev; }
        
        T value() { return this->_value; }
    };
    
    class Iterator
    {
    protected:
        Node* ptr;
    
    public:
        Iterator(Node *ptr) { this->ptr = ptr; }
    
        Iterator& operator = (Node* ptr)
        {
            this->ptr = ptr;
            return *this;
        }
    
        Iterator& operator++()
        {
            ptr = ptr->next();
            return *this;
        }
     
        Iterator operator++(int)
        {
            Iterator iterator = *this;
            ++*this;
            return iterator;
        }

        bool operator!=(const Iterator& iterator) { return ptr != iterator.ptr; }
            
        bool operator==(const Iterator& iterator) { return ptr == iterator.ptr; }
     
        Node* operator*() { return ptr; }
    };
    
protected:
    Node *head;
    Node *tail;
    int size;
    
public:
    List():size(0), head(new Node()), tail(new Node()){
        head->addNext(tail);
        tail->addPrev(head);
    }
    
    ~List()
    {
        Node *curr = head;
        while(curr != nullptr) {
            Node *next = curr->next();
            delete curr;
            curr = next;
        }
    }
    
    void push_back(T t)
    {
        Node *node = new Node(t);
        Node *_prev = tail->prev();
        _prev->addNext(node);
        node->addPrev(_prev);
        node->addNext(tail);
        tail->addPrev(node);
    }
    
    void push_front(T t) 
    {
        Node *node = new Node(t);
        Node *_next = head->next();
        node->addNext(_next);
        _next->addPrev(node);
        head->addNext(node);
        node->addPrev(head);
    }
    
    Iterator begin()
    {
        return Iterator(this->head->next());
    }
     
    Iterator end()
    {
        return Iterator(tail);
    }
};

#endif // LIST_H
