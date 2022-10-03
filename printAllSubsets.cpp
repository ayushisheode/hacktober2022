#include <bits/stdc++.h>
using namespace std;

void fun(string ip,string op)
{
    if(ip.length()==0)
    {
        cout<<op<<endl;
        return;
    }
    string op1=op;    
    string op2=op;
    op2.push_back(ip[0]);
    ip.erase(0,1);

    // cout<<"ip:"<<ip;
    // cout<<" op1:"<<op1;
    // cout<<" op2:"<<op2<<endl;

    fun(ip,op1);
    fun(ip,op2);
}

int main() {
    string s;
    cin>>s;

    fun(s,"");
}