template<typename T>
Vec<T>::Vec() = default;
template<typename T>
Vec<T>::Vec(std::initializer_list<T> arr) {
    for (const T& e : arr) append(e);
}

template<typename T>
Vec<T>::~Vec() {delete[] arr;}

template<typename T>
usize Vec<T>::get_len() const {return len;}

template<typename T>
usize Vec<T>::get_cap() const {return cap;}

template<typename T>
void Vec<T>::append(const T& val) {
    if (len == cap) grow();
    arr[len++] = val;
}
template<typename T>
template<usize L>
void Vec<T>::extend(const T(&vals)[L]) {
    if (len + L > cap) batch_grow(len + L);

    for (usize i = 0; i < L; i++) {
        arr[len++] = vals[i];
    }
}

template<typename T>
void Vec<T>::reserve(const usize target) {
    if (target < len) {
        std::cerr << "Cannot reserve less space than the current length of the vector:"
            << target << "<" << len << "\n";
        exit(1);
    }

    cap = target;

    T* newarr = new T[cap];
    for (usize i = 0; i < len; i++)
        newarr[i] = std::move(arr[i]);

    delete[] arr;
    arr = newarr;
}

template<typename T>
Vec<T> Vec<T>::slice(usize a, usize b) {
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

    usize n = b - a;
    Vec<T> out;
    out.batch_grow(n);

    T* dest = out.arr;
    for (usize i = a; i < b; i++) {
        *dest++ = arr[i];
    }
    out.len = n;

    return out;
}

template<typename T>
Vec<T>& Vec<T>::operator=(Vec other) {
    std::swap(arr, other.arr);
    std::swap(len, other.len);
    std::swap(cap, other.cap);

    return *this;
}

template<typename T>
T& Vec<T>::operator[](usize i) {return arr[i];}
template<typename T>
const T& Vec<T>::operator[](usize i) const {return arr[i];}

template<typename T>
void Vec<T>::grow() {
    cap = cap? cap * 2 : 1;
    T* newarr = new T[cap];

    for (usize i = 0; i < len; i++) {
        newarr[i] = std::move(arr[i]);
    }

    delete[] arr;
    arr = newarr;
}
template<typename T>
void Vec<T>::batch_grow(usize target) {
    if (!target) return;

    cap = 2;
    while (target >>= 1) cap <<= 1; 

    T* newarr = new T[cap];
    for (usize i = 0; i < len; i++)
        newarr[i] = std::move(arr[i]);

    delete[] arr;
    arr = newarr;
}

template<typename T>
void Vec<T>::clear() {
    for (usize i = 0; i < len; i++) {
        arr[i].~T(); 
    }

    delete[] arr;
    arr = nullptr;
    len = 0;
    cap = 0;
}