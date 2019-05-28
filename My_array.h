#ifndef CPP_MY_ARRAY_H
#define CPP_MY_ARRAY_H

#include <iostream>
#include <cstdlib>

template <typename T, int n>
class My_array {
private:
    T ar[n];
public:
    explicit My_array( const T &v );
    My_array() : My_array(0) { }
    virtual T &operator[]( int i );
    virtual T operator[]( int i ) const;
    ~My_array(){ std::cout << "~My_array called!" << std::endl;}
};

template<typename T, int n>
My_array<T, n>::My_array(const T &v) {
    for( int i = 0; i < n; ++i )
        ar[i] = v;
}

template<typename T, int n>
T &My_array<T, n>::operator[](int i) {
    return ar[i];
}

template<typename T, int n>
T My_array<T, n>::operator[](int i) const {
    return ar[i];
}

#endif //CPP_MY_ARRAY_H
