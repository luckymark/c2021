#ifndef linkedNode_
#define linkedNode_

template <typename T>
class linkedNode {  //链表节点
   public:
    linkedNode() {}
    linkedNode(T theElement) { element = theElement; }
    linkedNode(T theElement, linkedNode* theNext) {
        element = theElement;
        next = theNext;
    }
    T element;
    linkedNode* next;
};
#endif