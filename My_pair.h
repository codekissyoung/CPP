#ifndef CPP_MY_PAIR_H
#define CPP_MY_PAIR_H

template <typename T1, typename T2>
class My_pair {
private:
    T1 a;
    T2 b;
public:
    My_pair() = default;
    My_pair( const T1 &av, const T2 &bv );

    T1 &first() { return a; }
    T2 &second() { return b; }

    T1 first() const;
    T2 second() const;
};

template<typename T1, typename T2>
My_pair<T1, T2>::My_pair(const T1 &av, const T2 &bv) : a{av}, b{bv}{ }

template<typename T1, typename T2>
T1 My_pair<T1, T2>::first() const { return a; }

template<typename T1, typename T2>
T2 My_pair<T1, T2>::second() const { return b; }

#endif //CPP_MY_PAIR_H
