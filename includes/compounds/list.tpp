
template<typename T>
List<T>::List() = default;
template<typename T>
List<T>::List(std::initializer_list<T> lst) {
    for (const T& e : lst) append(e);
}
template<typename T>
List<T>::List(const List& other) {
    for (Node<T>* curr = other.head; curr; curr = curr->nxt)
        append(curr->val);
}
template<typename T>
List<T>::List(List&& other) noexcept: head(other.head), tail(other.tail), len(other.len) {
    other.head = nullptr;
    other.tail = nullptr;
    other.len = 0;
}

template<typename T>
usize List<T>::get_len() const {return len;}

template<typename T>
List<T>& List<T>::operator=(const List& other) {
    if (this != &other) {
        clear();
        for (Node<T>* curr = other.head; curr; curr = curr->nxt)
            append(curr->val);
    }
    return *this;
}

template<typename T>
List<T>::~List() {clear();}

template<typename T>
void List<T>::append(const T& val) {
    Node<T>* n = new Node<T>;
    n->val = val;
    n->prev = tail;

    if (tail) {
        tail->nxt = n;
        tail = n;
    } else {
        head = tail = n;
    }
    len++;
}
template<typename T>
void List<T>::prepend(const T& val) {
    Node<T>* n = new Node<T>;
    n->val = val;
    n->nxt = head;

    if (head) {
        head->prev = n;
        head = n;
    } else {
        head = tail = n;
    }
    len++;
}

template<typename T>
List<T> List<T>::slice(usize a, usize b) {
    if (a > len) {
        std::cerr << "Invlaid slice range: a out of range: " << a << " > " << len << "\n";
        exit(1);
    }
    if (b > len) {
        std::cerr << "Invlaid slice range: b out of range: " << b << " > " << len << "\n";
        exit(1);
    }
    if (a > b) {
        std::cerr << "Invlaid slice range: a > b (" << a << " > " << b << ")\n";
        exit(1);
    }

    List<T> out;

    for (usize i = a; i < b; i++) {
        out.append((*this)[i]);
    }

    return out;
}

template<typename T>
T& List<T>::operator[](usize index) {
    if (index >= len) throw std::out_of_range("Index out of bounds");
    
    Node<T>* curr;
    if (index < len >> 1) {
        curr = head;
        for (usize i = 0; i < index; i++) curr = curr->nxt;
    } else {
        curr = tail;
        for (usize i = len - 1; i > index; i--) curr = curr->prev;
    }
    return curr->val;
}
template<typename T>
const T& List<T>::operator[](usize index) const {
    if (index >= len) throw std::out_of_range("Index out of bounds");
    
    Node<T>* curr;
    if (index < len >> 1) {
        curr = head;
        for (usize i = 0; i < index; i++) curr = curr->nxt;
    } else {
        curr = tail;
        for (usize i = len - 1; i > index; i--) curr = curr->prev;
    }
    return curr->val;
}

template<typename T>
void List<T>::clear() {
    Node<T>* curr = head;
    while (curr) {
        Node<T>* nxt = curr->nxt;
        delete curr;
        curr = nxt;
    }
    head = tail = nullptr;
    len = 0;
}
