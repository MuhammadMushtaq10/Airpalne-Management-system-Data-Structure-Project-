#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
using namespace std;
const int T_S = 200;
class HashTableEntry {
   public:
      int key;
      int val;
      HashTableEntry(int key, int val) {
         this->key= key;
         this->val = val;
      }
};
class HashMapTable {
   private:
      HashTableEntry **t;
   public:
      HashMapTable() {
         t = new HashTableEntry * [T_S];
         for (int i = 0; i< T_S; i++) {
            t[i] = NULL;
         }
      }
      int HashFunc(int key) {
         return key % T_S;
      }
      void Insert(int key, int val) {
         int h = HashFunc(key);
         while (t[h] != NULL && t[h]->key != key) {
            h = HashFunc(h + 1);
         }
         if (t[h] != NULL)
            delete t[h];
         t[h] = new HashTableEntry(key, val);
      }
      int SearchKey(int key) {
         int h = HashFunc(key);
         while (t[h] != NULL && t[h]->key != key) {
            h = HashFunc(h + 1);
         }
         if (t[h] == NULL)
            return -1;
         else
         	cout<<"element found "<<endl;
            return t[h]->val;
            
      }
      void Remove(int key) {
         int h = HashFunc(key);
         while (t[h] != NULL) {
            if (t[h]->key == key)
               break;
            h = HashFunc(h + 1);
         }
         if (t[h] == NULL) {
            cout<<"No Element found at key "<<key<<endl;
            return;
         } else {
            delete t[h];
         }
         cout<<"Element Deleted"<<endl;
      }
      ~HashMapTable() {
         for (int i = 0; i < T_S; i++) {
            if (t[i] != NULL)
               delete t[i];
               delete[] t;
         }
      }
};
int main() {
   HashMapTable obj;
   obj.Insert(24 , 321);
   obj.Insert(52 , 112);
   obj.Insert(91 , 721);
   obj.Insert(67 , 435);
   obj.Insert(48 , 333);
   obj.Insert(89 , 112);
   obj.SearchKey(52);
   obj.Remove(89);
   
   return 0;
}