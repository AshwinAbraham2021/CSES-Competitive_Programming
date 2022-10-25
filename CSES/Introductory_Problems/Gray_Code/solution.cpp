/*
* AUTHOR: ASHWIN ABRAHAM
*/

#include <bits/stdc++.h>
using namespace std;
 
int prevgray(int, int);
 
int nextgray(int num, int n)
{
    if(n==1) return num^1;
    int pown = (1<<n);
    if(num%pown==(pown>>1) || num%pown==(pown>>2)) return num^(pown>>1);
    if(num&(pown>>1)) return prevgray(num, n-1);
    return nextgray(num, n-1);
}
 
int prevgray(int num, int n)
{
    if(n==1) return num^1;
    int pown = (1<<n);
    if(num%pown==3*(pown>>2) || num%pown==0) return num^(pown>>1);
    if(num&(pown>>1)) return nextgray(num, n-1);
    return prevgray(num, n-1);
}
 
void printbin(int num, int n)
{
    for(int i = n-1; i>=0; --i) cout << ((num&(1<<i))>>i);
    cout << '\n';
    return;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int num = 0;
    for(int i = 0; i<(1<<n); ++i)
    {
        printbin(num, n);
        num = nextgray(num, n);
    }
    return 0;
}