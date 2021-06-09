#include <iostream>
#include<unordered_map>
#include<map>
using namespace std;

class Cache{
    unordered_map<int, int>cache;
    map<int, list<int>time_list>timestamp;
    //map<int, int>timestamp;
    int time;
    int cache_size;
public:
    Cache(int c)
    {
        cache_size=c;
        time=0;
    }
    void insert_pair(int key, int value[])
    {
        if(cache.size()<cache_size)
        {
            cache.insert(make_pair(key,value));
            timestamp.insert(make_pair(time,key));
            time++;
            cout<<"inserted "<<endl;
        }
        else
        {
            //map<int,list<int>time_list> :: iterator it;

            /*map<int,int> :: iterator it;
            it=timestamp.begin();
            int key_delete=it->first;
            int del_value=it->second;
            timestamp.erase(key_delete);

            cache.erase(del_value);
            cache.insert(make_pair(key,value));
            timestamp.insert(make_pair(time,key));
            time++;
             cout<<"replaced "<<endl;
             */
        }
    }

    int access(int key)
    {
        unordered_map<int, int> :: iterator it;
        it = cache.find(key);
        if(it != cache.end())
        {
            map<int, int> :: iterator tp=timestamp.begin();
            while(tp!=timestamp.end())
            {
                if(tp->second==key)
                {
                    timestamp.erase(tp->first);
                    timestamp.insert(make_pair(time, key));
                    time++;
                    break;
                }
                tp++;
            }

            return it->second;
        }

        else
        {
            cout<<"element not in cache"<<endl;
            return -1;
        }
    }

    void print_cache()
    {
        unordered_map<int, int> :: iterator it=cache.begin();
        while(it!=cache.end())
        {
            cout<<it->first<<" - "<<it->second<<endl;
            it++;
        }
    }

};

int main()
{
    int c_size;
    cout<<"Enter max cache size"<<endl;
    cin>>c_size;
    Cache c(c_size);
    c.insert_pair(1,2);
    c.insert_pair(2,3);
    int m= c.access(1);
    cout<<"access: "<<m<<endl;
    cout<<"cache:"<<endl;
    c.insert_pair(5,6);
    c.insert_pair(7,8);
    c.insert_pair(3,5);
    c.print_cache();
    c.insert_pair(9,3);
    c.print_cache();
    c.insert_pair(10,3);
    cout<<"cache:"<<endl;
    c.print_cache();
    return 0;
}
