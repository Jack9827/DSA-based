#include <bits/stdc++.h>

using namespace std;
int N = 1e2+1;
vector<int> prime ( N , 1);


void seive(){
    prime[0] = 0;
    prime[1] = 0;
     for (int p = 2; p * p <= N; p++) {
        
        if (prime[p] == true) {
            for (int i = p * p; i <= N; i += p)
                prime[i] = false;
        }
    }
}

int main(){

    seive();
    // print factors of 10

    for(int i=0; i<prime.size() ; i++){
        cout << i << " " << prime[i] << "\n";
    }

    return 0;
}