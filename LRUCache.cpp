#include "LRUCache.h"
// pop from front if exceeds size
// last accessed is back of que

pair<int,int> LRUCache::isPresent(int key)
{
    int count = 0;
    
    for(auto i = q.begin() ; i < q.end(); i++ )
    {
        if((*i).key == key)
        {
        //    cout << " key present " << count << endl;
            return make_pair(count,(*i).val);
        }
        count++;
    }
    //cout << " key NOT present " << key << " " << endl;
    return make_pair(-1,-1);
}

void LRUCache::push_to_back(int idx)
{
    if(idx == -1)
        return;

    auto it = q.begin();

    for(int i = 1; i <= idx; i++)
    {
        if(it!=q.end())
        {
            it++;
        }
    }
    page p;
    p.key = (*it).key;
    p.val = (*it).val;

    q.erase(it);
    q.push_back(p);
}

int LRUCache::get(int key)
{
    pair<int,int> idx = isPresent(key);
    if( idx.first != -1)
        push_to_back(idx.first);

    return idx.second;
}


void LRUCache::put(pair<int,int> data)
{
    pair<int,int> ret = isPresent(data.first);
    if(ret.first == -1)
    {
        if(q.size() >= size)
        {   
            page n = q.front();
          //  cout << " " << n.key << " " << n.val << endl;
            q.pop_front();
        }

    page p;
    p.key = data.first;
    p.val = data.second;
    q.push_back(p);
    //cout << " q size = " << q.size() << endl;
    }
    return;
}

int main()
{
    LRUCache l1(4);
    l1.put(make_pair(1,11));
    l1.put(make_pair(2,22));
    l1.put(make_pair(3,33));
    l1.put(make_pair(4,44));


    cout << l1.get(1) << endl;
    cout << l1.get(1) << endl;
    cout << l1.get(1) << endl;
       cout << l1.get(2) << endl;   cout << l1.get(4) << endl;   cout << l1.get(6) << endl;
    l1.put(make_pair(5,55));
    l1.put(make_pair(6,66));

    cout << l1.get(1) << endl;


    return 0;
}
