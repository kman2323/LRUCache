#ifndef _LRUCACHE_H_
#define _LRUCACHE_H_

#include <deque>
#include <map>
#include <iostream>
#include <iterator>
using namespace std;
struct page {
    int key;
    int val;
};
class LRUCache
{
    int size; // of queue

    deque<page> q;
    pair<int,int> isPresent(int key);
    void push_to_back(int key);

    public:
        int get(int key);
        void put(pair<int,int> data);
        LRUCache(int s) : size(s) { }

};


#endif
