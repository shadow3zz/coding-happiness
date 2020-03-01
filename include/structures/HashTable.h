/*
 * @Descripttion: 
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-02-26 11:26:54
 * @LastEditors: shadow3zz
 * @LastEditTime: 2020-02-29 20:08:48
 */
#pragma once
#include <string>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

int hash(const std::string &key);
int hash(int key);
int hash(const Employee & item);
template <typename HashedObj>
class HashTable
{
private:
    std::vector<std::list<HashedObj> > theLists;
    int currentSize;
    
    void rehash();
    int myhash(const HashedObj&x) const{
        int hashVal = hash(x);
        hashVal %= theLists.size();
        if (hashVal < 0)
            hashVal += theLists.size();
        return hashVal;
    }
    
public:
    explicit HashTable(int size = 101){};

    bool contains(const HashedObj &x) const{
        const std::list<HashedObj> & whichList = theLists[myhash{x}];
        return std::find(whichList.begin(), whichList.end(), x) != whichList.end();
    }

    void makeEmpty(){
        for (int i = 0; i < theLists.size(); i++){
            theLists[i].clear();
        }
    }
    bool insert(const HashedObj &x){
        std::list<HashedObj> & whichList = theLists[myhash(x)];
        if (std::find(whichList.begin(), whichList.end(), x)) return false;
        whichList.push_back(x);

        if (++currentSize > theLists.size()) rehash();

        return true;
    }
    voif remove(const HashedObj &x){
        std::list<HashedObj> & whichList = theLists[myhash(x)];
        std::list<HashedObj>::iterator itr = std::find(whichList.begin(), whichList.end(), x);
        if (itr!=whichList.end())
            return false;
        whichList.erase(x);
        --currentSize;
        return true;
    }
    
    ~HashTable(){};
};

//Example of an Employee class
class Employee
{
private:
    std::string name;
    double salary;
    int seniority;
public:
    Employee(/* args */);
    ~Employee();
    const std::string & getName() const{ return name;}
    bool operator==(const Employee & rhs) const { return getName() == rhs.getName();}
    bool operator!=(const Employee & rhs) const {return !(*this==rhs);}
};

int hash(const Employee & item){
    return hash(item.getName());
}