#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int a;
    cin>>a;
    int count;
    for(int i = 0; i < a; i++)
    {
        count *= i;
    }
   count << count;
}