/*
 * @Descripttion: HashMap.h
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-07-13 16:11:15
 * @LastEditors: shadow3zz
 * @LastEditTime: 2020-07-14 14:40:58
 */ 
#ifndef _HASHMAP_H_
#define _HASHMAP_H_

#include <iostream>

using namespace std;

class HashFunc{
public:
    int operator()(const string & key){
        int hash = 0;
        for (int i = 0; i < key.length(); ++i){
            hash = hash << 7 ^ key[i];
        }
        return (hash & 0x7FFFFFFF);
    }
};

class EqualKey{
public:
    bool operator()(const string& A, const string& B){
        return A == B;
    }
};


static int prime[28] =
{
    57,        97,         193,        389,        769,
    1543,      3079,       6151,       12289,      24593,
    49157,     98317,      196613,     393241,     786433,
    1572869,   3145739,    6291469,    12582917,   25165843,
    50331653,  100663319,  201326611,  402653189,  805306457,
    1610612741
}; 

class HashMapUtil{
public:
    static int FindNextPrime(int current){
        // 通过查找prime数组找到下一个质数
        int i = 0;
        for (;i<28;++i){
            if (current < prime[i])
                break;
        }
        return prime[i];
    }
};

template<class Key, class Value, class HashFunc, class EqualKey>
class HashMap{
private:
    template <class _Key, class _Value>
    class KeyNode
    {
    public:
        _Value value;
        _Key   key;
        int    used;
        KeyNode() :used(0) {}
        KeyNode(const KeyNode& kn){
            value = kn.value;
            key = kn.key;
            used = kn.used;
        }
        KeyNode &operator=(const KeyNode& kn){
            if(this == &kn) return *this;
            value = kn.value;
            key = kn.key;
            used = kn.used;
            return *this;
        }
    };

public:
    HashMap();
    ~HashMap();
    bool insert(const Key& hashKey, const Value& value);
    bool remove(const Key& hashKey);
    void rehash();
    Value& find(const Key& hashKey);
    const Value& operator[](const Key& hashKey) const;
    Value& operator[](const Key& hashKey);

private:
    HashFunc hash;
    EqualKey equal;
    HashMapUtil hml;
    KeyNode<Key, Value> *table;
    int size;
    int capacity;
    static const double loadingFactor;
    int findKey(const Key& hashKey);
};

template<class Key, class Value, class HashFunc, class EqualKey>
const double HashMap<Key, Value, HashFunc, EqualKey>::loadingFactor = 0.9;

template<class Key, class Value, class HashFunc, class EqualKey>
HashMap<Key, Value, HashFunc, EqualKey>::HashMap(){
    hash = HashFunc();
    equal = EqualKey();
    hml = HashMapUtil();
    capacity = hml.FindNextPrime(0);
    table = new KeyNode<Key, Value>[capacity+1];
    for (int i = 0; i < capacity; i++){
        table[i].used = 0;
    }
    size = 0;
}

template<class Key, class Value, class HashFunc, class EqualKey>
HashMap<Key, Value, HashFunc, EqualKey>::~HashMap()
{
    delete []table;
}

template<class Key, class Value, class HashFunc, class EqualKey>
bool HashMap<Key, Value, HashFunc, EqualKey>::insert(const Key& hashKey, const Value& hashValue){
    int index = hash(hashKey) %capacity;
    cout << "Index is " << index << endl;
    if (table[index].used == 1){
        cout << "The key-value must be unique!" << endl;
        return false;
    }
    table[index].used = 1;
    table[index].key = hashKey;
    table[index].value = hashValue;
    
    size++;
    
    if (size >= capacity*loadingFactor){
        rehash();
    }
    return true;
}

template<class Key, class Value, class HashFunc, class EqualKey>
void HashMap<Key, Value, HashFunc, EqualKey>::rehash(){
    int oldCapcity = capacity;
    // 将原数组table深拷贝到一个新的数组当中
    capacity = hml.FindNextPrime(capacity);
    KeyNode<Key, Value> *temp = new KeyNode<Key, Value>[capacity];
    for (int i = 0; i<oldCapcity; ++i)
    {
        if (table[i].used == 1)
            temp[i] = table[i];
    }
    delete []table;
    table = new KeyNode<Key, Value>[capacity+1];
    for (int i = 0; i<capacity; ++i){
        table[i].used = 0; // 初始化新的表
    }
    for (int i = 0; i<oldCapcity; ++i){
        if (temp[i].used == 1)
            insert(temp[i].key, temp[i].value);
    }
    delete []temp;
}

template<class Key, class Value, class HashFunc, class EqualKey>
bool HashMap<Key, Value, HashFunc, EqualKey>::remove(const Key& hashKey){
    int index = findKey(hashKey);
    if (index < 0){
        cout << "No such key!" << endl;
        return false;
    }
    else{
        table[index].used = 0;
        size--;
        return true;
    }
}

template<class Key, class Value, class HashFunc, class EqualKey>
Value& HashMap<Key, Value, HashFunc, EqualKey>::find(const Key& hashKey){
    int index = findKey(hashKey);
    if (index < 0){
        cout << "Can not find the key!" << endl;
        return table[capacity].value;
    }
    else
        return table[index].value;
}

template<class Key, class Value, class HashFunc, class EqualKey>
const Value& HashMap<Key, Value, HashFunc, EqualKey>::operator[](const Key& hashKey) const{
    return find(hashKey); //overload the operation to return the value of the element
}

template<class Key, class Value, class HashFunc, class EqualKey>
Value& HashMap<Key, Value, HashFunc, EqualKey>::operator[](const Key& hashKey)
{
    return find(hashKey); //overload the operation to return the value of the element
}

template<class Key, class Value, class HashFunc, class EqualKey>
int HashMap<Key, Value, HashFunc, EqualKey>::findKey(const Key& hashKey){
    int index = hash(hashKey)%capacity;
    if (table[index].used != 1 || !equal(table[index].key, hashKey))
        return -1;
    else 
        return index;    
}


void Test(){
    HashMap<string, string, HashFunc, EqualKey> hashmap;
    hashmap.insert("hello", "you");
    hashmap.insert("why" , "dream");
    hashmap.insert("java" ,"good");
    hashmap.insert("welcome" ,"haha");
    hashmap.insert("welcome" ,"hehe"); //error, key-value must be unique

    cout<<"after insert:"<<endl;
    cout<<hashmap.find("welcome")<<endl;
    cout<<hashmap.find("java")<<endl;
    cout<<hashmap["why"]<<endl;
    cout<<hashmap["hello"]<<endl;

    if(hashmap.remove("hello"))
        cout<<"remove is ok"<<endl;    //remove is ok
    cout<<hashmap.find("hello")<<endl; //not exist print NULL

    hashmap["why"] = "love"; //modify the value 
    cout<<hashmap["why"]<<endl;
}

#endif  // _HASHMAP_H_