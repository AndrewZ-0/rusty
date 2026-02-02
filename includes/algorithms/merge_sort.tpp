template<typename T>
void merge_sort(T *arr, usize len) {
    if (len < 2) return;

    usize i;
    usize m = len / 2;
    usize r_len = len - m;
    T *l = new T[m];
    T *r = new T[r_len];
    for (i = 0; i < m; i++) {
        l[i] = arr[i];
    }
    for (i = 0; i < r_len; i++) {
        r[i] = arr[i + m];
    }
    
    merge_sort(l, m);
    merge_sort(r, r_len);

    usize l_ptr = 0, r_ptr = 0;
    i = 0;
    while(l_ptr < m && r_ptr < r_len) {
        if (l[l_ptr] < r[r_ptr]) {
            arr[i++] = l[l_ptr++];
        } else {
            arr[i++] = r[r_ptr++];
        }
    }

    while (l_ptr < m) {
        arr[i++] = l[l_ptr++];
    }
    while (r_ptr < r_len) {
        arr[i++] = r[r_ptr++];
    }

    delete[] l;
    delete[] r;
}

template<typename T, usize L>
void merge_sort(T(&arr)[L]) {
    if (L < 2) return;

    usize i;
    usize m = L / 2;
    usize r_len = L - m;
    T *l = new T[m];
    T *r = new T[r_len];
    for (i = 0; i < m; i++) {
        l[i] = arr[i];
    }
    for (i = 0; i < r_len; i++) {
        r[i] = arr[i + m];
    }
    
    merge_sort(l, m);
    merge_sort(r, r_len);

    usize l_ptr = 0, r_ptr = 0;
    i = 0;
    while(l_ptr < m && r_ptr < r_len) {
        if (l[l_ptr] < r[r_ptr]) {
            arr[i++] = l[l_ptr++];
        } else {
            arr[i++] = r[r_ptr++];
        }
    }

    while (l_ptr < m) {
        arr[i++] = l[l_ptr++];
    }
    while (r_ptr < r_len) {
        arr[i++] = r[r_ptr++];
    }

    delete[] l;
    delete[] r;
}

template<typename T>
void merge_sort(Vec<T> &arr) {
    if (arr.get_len() < 2) return;

    usize i;
    usize m = arr.get_len() / 2;
    usize r_len = arr.get_len() - m;
    T *l = new T[m];
    T *r = new T[r_len];
    for (i = 0; i < m; i++) {
        l[i] = arr[i];
    }
    for (i = 0; i < r_len; i++) {
        r[i] = arr[i + m];
    }
    
    merge_sort(l, m); 
    merge_sort(r, r_len);

    usize l_ptr = 0, r_ptr = 0;
    i = 0;
    while(l_ptr < m && r_ptr < r_len) {
        if (l[l_ptr] < r[r_ptr]) {
            arr[i++] = l[l_ptr++];
        } else {
            arr[i++] = r[r_ptr++];
        }
    }

    while (l_ptr < m) {
        arr[i++] = l[l_ptr++];
    }
    while (r_ptr < r_len) {
        arr[i++] = r[r_ptr++];
    }

    delete[] l;
    delete[] r;
}

template<typename T>
void merge_sort(List<T> &lst) {
    if (lst.get_len() < 2) return;

    usize i;
    usize m = lst.get_len() / 2;
    usize r_len = lst.get_len() - m;
    T *l = new T[m];
    T *r = new T[r_len];
    for (i = 0; i < m; i++) {
        l[i] = lst[i];
    }
    for (i = 0; i < r_len; i++) {
        r[i] = lst[i + m];
    }
    
    merge_sort(l, m); 
    merge_sort(r, r_len);

    usize l_ptr = 0, r_ptr = 0;
    i = 0;
    while(l_ptr < m && r_ptr < r_len) {
        if (l[l_ptr] < r[r_ptr]) {
            lst[i++] = l[l_ptr++];
        } else {
            lst[i++] = r[r_ptr++];
        }
    }

    while (l_ptr < m) {
        lst[i++] = l[l_ptr++];
    }
    while (r_ptr < r_len) {
        lst[i++] = r[r_ptr++];
    }

    delete[] l;
    delete[] r;
}