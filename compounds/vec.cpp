#include "scalars.h"

template<typename T, usize L>
class Vec {
public:
    T* arr = nullptr;
    usize len = 0;
    usize cap = 0;

    Vec() = default;

    ~Vec() {delete[] arr;}

    void append(const T& val) {
        if (len == cap) grow();
        arr[len++] = val;
    }
    void extend(const T(&vals)[L]) {
        if (len + L > cap) batch_grow(len + L);

        for (usize i = 0; i < L; i++) {
            arr[len++] = vals[i];
        }
    }

    Vec& operator=(const Vec& other) {
        
        return *this;
    }

    T& operator[](usize i) {return arr[i];}
    const T& operator[](usize i) const {return arr[i];}

private:
    void grow() {
        cap = cap? cap * 2 : 1;
        T* newarr = new T[cap];

        for (usize i = 0; i < len; i++) {
            newarr[i] = std::move(arr[i]);
        }

        delete[] arr;
        arr = newarr;
    }
    void batch_grow(usize target) {
        if (!target) return;

        cap = 2;
        while (target >>= 1) cap <<= 1; 

        T* newarr = new T[cap];
        for (usize i = 0; i < len; i++)
            newarr[i] = std::move(arr[i]);

        delete[] arr;
        arr = newarr;
    }
};
