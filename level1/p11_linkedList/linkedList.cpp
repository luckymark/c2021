#include <sstream>

#include "illegalParameter.h"
#include "linearList.h"
#include "linkedNode.h"

template <typename T>
class linkedList : public linearList<T> {  //链表
   public:
    linkedList();
    linkedList(const linkedList<T>&);
    ~linkedList();

    bool empty() const { return listSize == 0; }
    int size() const { return listSize; };
    T& get(int theIndex) const;
    int indexOf(const T& theElement, int theIndex = -1) const;
    void erase(int theIndex);
    void insert(int theIndex, const T& theElement);
    void output(std::ostream& out) const;
    void clear();
    void push_back(const T& theElement);
    void pop_back();

    void set(int theIndex, const T& theElement);
    void resize(int size, const T& theElement);
    void reverse();

   protected:
    linkedNode<T>* firstNode;
    linkedNode<T>* lastNode;
    int listSize;
};

template <typename T>
linkedList<T>::linkedList() {
    firstNode = nullptr;
    lastNode = nullptr;
    listSize = 0;
}

template <typename T>
linkedList<T>::linkedList(const linkedList<T>& theList) {
    listSize = theList.listSize;
    if (listSize == 0) {
        linkedList();
        return;
    }
    linkedNode<T>* sourceNode = theList.firstNode;
    firstNode = new linkedNode<T>(sourceNode->element);
    linkedNode<T>* currentNode = firstNode;
    sourceNode = sourceNode->next;

    while (sourceNode != nullptr) {
        currentNode->next = new linkedNode<T>(sourceNode->element);
        currentNode = currentNode->next;
        sourceNode = sourceNode->next;
    }
    lastNode = currentNode;
    lastNode->next = nullptr;
}

template <typename T>
linkedList<T>::~linkedList() {
    linkedNode<T>* tempNode;
    while (firstNode != nullptr) {
        tempNode = firstNode->next;
        delete firstNode;
        firstNode = tempNode;
    }
}

template <typename T>
T& linkedList<T>::get(int theIndex) const {
    if (theIndex >= listSize || theIndex < 0) {
        std::ostringstream s;
        s << "获取失败 链表大小为" << listSize << " 输入Index为" << theIndex << std::endl;
        throw illegalParameter(s.str());
    }
    linkedNode<T>* currentNode = firstNode;
    for (int i = 0; i < theIndex; ++i) {
        currentNode = currentNode->next;
    }
    return currentNode->element;
}

template <typename T>
int linkedList<T>::indexOf(const T& theElement, int theIndex) const {
    if (theIndex >= listSize - 1 || theIndex < -1) {
        return -1;
    }

    linkedNode<T>* currentNode = firstNode;
    int index = theIndex + 1;
    for (int i = -1; i < theIndex; ++i) {
        currentNode = currentNode->next;
    }
    while (currentNode != nullptr && currentNode->element != theElement) {
        ++index;
        currentNode = currentNode->next;
    }
    if (currentNode == nullptr) {
        return -1;
    }
    return index;
}

template <typename T>
void linkedList<T>::erase(int theIndex) {
    if (theIndex >= listSize || theIndex < 0) {
        std::ostringstream s;
        s << "删除失败 链表大小为" << listSize << " 输入Index为" << theIndex << std::endl;
        throw illegalParameter(s.str());
    }
    linkedNode<T>* deleteNode;
    if (theIndex == 0) {
        deleteNode = firstNode;
        firstNode = firstNode->next;
    } else {
        linkedNode<T>* preNode = firstNode;
        for (int i = 1; i < theIndex; ++i) {
            preNode = preNode->next;
        }
        deleteNode = preNode->next;
        preNode->next = deleteNode->next;
        if (deleteNode == lastNode) lastNode = preNode;
    }
    delete deleteNode;
    --listSize;
}

template <typename T>
void linkedList<T>::insert(int theIndex, const T& theElement) {
    if (theIndex > listSize || theIndex < 0) {
        std::ostringstream s;
        s << "插入失败 链表大小为" << listSize << " 输入Index为" << theIndex << std::endl;
        throw illegalParameter(s.str());
    }
    if (theIndex == 0) {
        firstNode = new linkedNode<T>(theElement, firstNode);
        if (listSize == 0) {
            lastNode = firstNode;
        }
    } else {
        linkedNode<T>* preNode = firstNode;
        for (int i = 1; i < theIndex; ++i) {
            preNode = preNode->next;
        }
        preNode->next = new linkedNode<T>(theElement, preNode->next);
        if (listSize == theIndex) {
            lastNode = preNode->next;
        }
    }
    ++listSize;
}

template <typename T>
void linkedList<T>::output(std::ostream& out) const {
    for (linkedNode<T>* currentNode = firstNode; currentNode != nullptr; currentNode = currentNode->next) {
        out << currentNode->element << ' ';
    }
}

template <typename T>
void linkedList<T>::clear() {
    linkedNode<T>* tempNode = firstNode;
    while (firstNode != nullptr) {
        tempNode = firstNode->next;
        delete firstNode;
        firstNode = tempNode;
    }
    listSize = 0;
}

template <typename T>
void linkedList<T>::push_back(const T& theElement) {
    linkedNode<T>* newNode = new linkedNode<T>(theElement, nullptr);
    if (listSize == 0) {
        firstNode = newNode;
        lastNode = newNode;
    } else {
        lastNode->next = newNode;
        lastNode = newNode;
    }
    ++listSize;
}

template <typename T>
void linkedList<T>::pop_back() {
    if (listSize == 0) {
        std::cerr << "链表为空" << std::endl;
        return;
    } else if (listSize == 1) {
        delete firstNode;
        firstNode = nullptr;
        lastNode = nullptr;
    } else {
        linkedNode<T>* preNode = firstNode;
        for (int i = 2; i < listSize; ++i) {
            preNode = preNode->next;
        }
        delete lastNode;
        preNode->next = nullptr;
        lastNode = preNode;
    }
    --listSize;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const linkedList<T>& l) {
    l.output(out);
    return out;
}

template <typename T>
void linkedList<T>::set(int theIndex, const T& theElement) {
    if (theIndex >= listSize || theIndex < 0) {
        std::cerr << "更改失败 链表大小为" << listSize << " 输入Index为" << theIndex << std::endl;
        return;
    }
    linkedNode<T>* currentNode = firstNode;
    for (int i = 0; i < theIndex; ++i) {
        currentNode = currentNode->next;
    }
    currentNode->element = theElement;
}

template <typename T>
void linkedList<T>::resize(int size, const T& theElement) {
    if (size < 0) {
        std::ostringstream s;
        s << "失败 大小为" << listSize << " 输入Size为" << size << std::endl;
        throw illegalParameter(s.str());
    } else if (size < listSize) {
        while (size < listSize) {
            pop_back();
        }
    } else if (size > listSize) {
        while (size > listSize) {
            push_back(theElement);
        }
    } else {
        return;
    }
}

template <typename T>
void linkedList<T>::reverse() {
    lastNode = firstNode;

    linkedNode<T>* tempNode = nullptr;
    linkedNode<T>* nextNode = nullptr;

    while (firstNode != nullptr) {
        nextNode = firstNode->next;
        firstNode->next = tempNode;
        tempNode = firstNode;
        firstNode = nextNode;
    }
    firstNode = tempNode;
}

int main() {
    linkedList<int> l;
    for (int i = 1; i <= 10; ++i) l.push_back(i);
    l.set(9, 5);

    linkedList<int> list(l);

    std::cout << list << std::endl;
    list.reverse();
    std::cout << list << std::endl;

    int i1 = list.indexOf(5);
    int i2 = list.indexOf(5, i1);
    int i3 = list.indexOf(5, i2);
    std::cout << "节点序号从0开始" << std::endl;
    std::cout << "数字5第一次出现节点序号：" << i1 << std::endl;
    std::cout << "数字5第一次出现节点序号：" << i2 << std::endl;
    std::cout << "数字5第一次出现节点序号：" << i3 << std::endl;

    return 0;
}