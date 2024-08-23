// coded by Jai_Khatri

#include <bits/stdc++.h>

using namespace std;
//------------------------------

typedef long long ll;
typedef long double ld;
#define pii pair<int , int>
#define vi vector<int>
#define pll pair<ll , ll>
#define vl vector<ll>
#define vb vector<bool>
#define vip(a,n)    for(ll i=0;i<n;i++) cin>>a[i];
#define p(v)         for(auto x:v) cout<<x<<' ';cout<<'\n';
#define n1 "\n"
#define pb push_back
#define ppb pop_back
#define F first
#define S second 
#define all(a) (a).begin() , (a).end()
#define sz(a) ((int)((a).size()))

const ll INF = 4e18;
//---------------------------------
class Node{
public:
   Node* links[26];
   bool flag = false;

   bool containsKey(char ch)
   {
      return links[ch-'a'] != NULL;
   }

   void put(char ch , Node *node)
   {
      link[ch-'a'] = node;
   }

   Node* get(char ch)
   {
      return links[ch-'a'];
   }

   void setEnd()
   {
      flag = 1;
   }

}

class Trie{
public:

   Node* root;

   Trie()
   {
      root = new Node();

   }

   void insert(string word)
   {

      Node* node = root;

      for(int i=0; i<word.size(); i++)
      {
         if(!node->containsKey(word[i]))
         {
            node->put(word[i] , new Node());
         }

         node = node->get(word[i]);
      }

      node->setEnd();
   }

   bool search(string word)
   {
      Node* node = root;

      for(int i=0; i<word.size(); i++)
      {
         if(!node->containsKey(word[i]))
         {
            return 0;
         }

         node = node->get(word[i]);
      }

      return node->flag;
   }


   bool startsWith(string word)
   {
      Node* node = root;
      for(int i=0; i<word.size(); i++)
      {
         if(!node->containsKey(word[i]))
         {
            return 0;
         }

         node = node->get(word[i]);
      }

      return 1;
   }
};
// main code starts here


int32_t main(){

    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        
        


        
    }


    return 0;

}   