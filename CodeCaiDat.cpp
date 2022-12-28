//stack
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct NODE {
    int Data;
    int next;
};

struct LINKEDSTACK
{
    int Top = -1;
    void init() {
        Top = -1;
    }
    static const int M = 1000;
    NODE _stack[M];
    bool insert(NODE Y) {
        Top = Top + 1;
        if (Top >= M) return false;
        _stack[Top] = Y;
        return true;
    }
    NODE deleteElement() {
        NODE result;
        result.next = -1;
        if (Top < 0) {
            return result;
        }
        result = _stack[Top];
        Top = Top - 1;
        return result;
    }
}

//Queue
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

struct NODE {
    int Data;
    int next;
};

struct QUEUE
{
    int Front;
    int Rear;

    static const int M = 1000;
    NODE _queue[M];

    void init() {
        Front = -1;
        Rear = -1;
    }
    bool insert(NODE Y) {
        if (Front == -1)
        {
            Front = Front + 1;
            Rear = Rear + 1;
            _queue[Rear] = Y;
            return true;
        }

        Rear = Rear + 1;
        if (Rear > M) return false;
        _queue[Rear] = Y;
        return true;
    }
    NODE deleteElement() {
        NODE result;
        result.next = -1;
        if (Front < 0) {
            return result;
        }
        result = _queue[Front];
        Front = Front + 1;
        return result;

    }

    bool isEmpty()
    {
        return Front <= -1;
    }
};

//deque
//Deque
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct NODE {
    int Data;
    NODE* next;
    NODE* prev;
};
struct DEQUE
{
    NODE* LeftMost;
    NODE* RightMost;
    void init() {
        LeftMost = nullptr;
        RightMost = nullptr;
    }
    bool insert(NODE* Y, bool left)
    {
        if (left == true) {
            if (LeftMost == nullptr) {//push ben trai
                RightMost = Y;
                RightMost->next = nullptr;
                LeftMost = Y;
                LeftMost->next = nullptr;
                return true;
            }
            LeftMost->next = Y;
            LeftMost = Y;
            return true;
        }
        else {
            if (LeftMost == nullptr) {
                RightMost = Y;
                RightMost->next = nullptr;
                LeftMost = Y;
                LeftMost->next = nullptr;
                return true;
            }
            Y->next = RightMost;
            RightMost = Y;
            return true;
        }
    }
    bool isEmpty()
    {
        return LeftMost == nullptr;
    }
    NODE* deleteQUEUE(bool left) {
        if (left == true) {
            if (this->isEmpty()) return nullptr;
            NODE* result;
            result = new NODE();
            result->Data = RightMost->Data;
            NODE* next = RightMost->next;
            delete(RightMost);
            RightMost = next;
            if (RightMost == nullptr)
                LeftMost = nullptr;
            return result;
        }
        else {
            if (this->isEmpty()) return nullptr;
            NODE* result;
            result = new NODE();
            result->Data = LeftMost->Data;
            NODE* node = RightMost;
            NODE* node1 = nullptr;
            while (node->next != nullptr) {
                node1 = node;
                node = node->next;
            }
            delete(LeftMost);
            LeftMost = node1;
            if (LeftMost == nullptr)
                LeftMost->next = nullptr;
            return result;
        }
    }
};

//link list
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

typedef struct Node NODE;

struct LinkedList
{
    Node* head;
    Node* tail;

    void init()
    {
        head = nullptr;
        tail = nullptr;
    }

    void ThemDau(Node* Y)
    {
        if (head == nullptr)
        {
            head = tail = Y;
            tail->next = nullptr;
        }
        else
        {
            Y->next = head;
            head = Y;
            tail->next = nullptr;
        }
    }

    void ThemCuoi(Node* Y)
    {
        if (head == nullptr)
        {
            head = tail = Y;
            tail->next = nullptr;
        }
        else
        {
            tail->next = Y;
            tail = Y;
            tail->next = nullptr;
        }
    }

    void ThemGiua(Node* Y, int k)
    {
        if (k == 0)
        {
            ThemDau(Y);
        }
        else
        {
            int dem = 0;
            NODE* g = new NODE;

            for (NODE* l = head; l != nullptr; l = l->next)
            {
                if (dem == k)
                {

                    Y->next = l;
                    g->next = Y;
                    break;
                }
                g = l;
                dem++;
            }
        }
    }

    void XoaDau()
    {
        if (head == nullptr) return;
        else
        {
            Node* p = new Node;
            p = head;
            head = head->next;
            delete p;
            tail->next = nullptr;
        }
    }

    void XoaCuoi()
    {
        if (head == nullptr) return;
        else
        {
            Node* p = new Node;
            p = head;
            if (p->next == nullptr)
            {
                head = nullptr;
                delete p;
                return;
            }
            while (p->next->next != nullptr)
            {
                p = p->next;
            }
            Node* temp = new Node;
            temp = p->next;
            tail = p;
            delete temp;
            tail->next = nullptr;
        }
    }

    void XoaGiua(int k)
    {
        if (k == 0)
        {
            XoaDau();
        }

        else
        {
            int dem = 0;
            NODE* g = new NODE;

            for (NODE* l = head; l != nullptr; l = l->next)
            {
                if (dem == k)
                {
                    g->next = l->next;
                    delete l;
                    break;
                }
                g = l;
                dem++;
            }
        }
    }
};

//circle list
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

typedef struct Node NODE;

struct CircleList
{
    Node* head;
    Node* tail;

    void init()
    {
        head = nullptr;
        tail = nullptr;
    }

    void ThemDau(Node* Y)
    {
        if (head == nullptr)
        {
            head = tail = Y;
            tail->next = head;
        }
        else
        {
            Y->next = head;
            head = Y;
            tail->next = head;
        }
    }

    void ThemCuoi(Node* Y)
    {
        if (head == nullptr)
        {
            head = tail = Y;
            tail->next = head;
        }
        else
        {
            tail->next = Y;
            tail = Y;
            tail->next = head;
        }
    }

    void ThemGiua(Node* Y, int k)
    {
        if (k == 0)
        {
            ThemDau(Y);
        }
        else
        {
            int dem = 0;
            NODE* g = new NODE;

            for (NODE* l = head; l != nullptr; l = l->next)
            {
                if (dem == k)
                {

                    Y->next = l;
                    g->next = Y;
                    break;
                }
                g = l;
                dem++;
            }
        }
    }

    void XoaDau()
    {
        if (head == nullptr) return;
        else
        {
            Node* p = new Node;
            p = head;
            head = head->next;
            delete p;
            tail->next = head;
        }
    }

    void XoaCuoi()
    {
        if (head == nullptr) return;
        else
        {
            Node* p = new Node;
            p = head;
            if (p->next == nullptr)
            {
                head = nullptr;
                delete p;
                return;
            }
            while (p->next->next != nullptr)
            {
                p = p->next;
            }
            Node* temp = new Node;
            temp = p->next;
            tail = p;
            delete temp;
            tail->next = head;
        }
    }

    void XoaGiua(int k)
    {
        if (k == 0)
        {
            XoaDau();
        }

        else
        {
            int dem = 0;
            NODE* g = new NODE;

            for (NODE* l = head; l != nullptr; l = l->next)
            {            
                if (dem == k)
                {
                    g->next = l->next;
                    delete l;
                    break;
                }
                g = l;
                dem++;
            }
        }
    }
};









