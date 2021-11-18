#pragma once
#include <algorithm>
#include <iterator>
#include <set>
#include <iostream>


namespace Sets {

    using namespace std;

    template <class T, class CMP = less<T>, class ALLOC = allocator<T> >
    set<T, CMP, ALLOC> operator * (
        const set<T, CMP, ALLOC>& s1, const set<T, CMP, ALLOC>& s2)
    {
        set<T, CMP, ALLOC> s;
        set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(),
            inserter(s, s.begin()));
        return s;
    }

    template <class T, class CMP = less<T>, class ALLOC = allocator<T> >
    set<T, CMP, ALLOC> operator + (
        const set<T, CMP, ALLOC>& s1, const set<T, CMP, ALLOC>& s2)
    {
        set<T, CMP, ALLOC> s;
        set_union(s1.begin(), s1.end(), s2.begin(), s2.end(),
            inserter(s, s.begin()));
        return s;
    }

    template <class T>
    ostream& operator << (ostream& out, const set<T>& values)
    {
        const char* sep = " ";
        for (const T& value : values) {
            out << sep << value; sep = ", ";
        }
        return out;
    }
    template <class T>
    ostream& operator << (ostream& out, const multiset<T>& values)
    {
        const char* sep = " ";
        for (const T& value : values) {
            out << sep << value; sep = ", ";
        }
        return out;
    }
}