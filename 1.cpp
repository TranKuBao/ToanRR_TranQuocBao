#include<iostream>
#include<fstream>
#include<string.h>
#define maxx 99 

using namespace std;

int main()
{
    int n;
    int a[maxx][maxx];
    cout<<"So Dinh cua do thi 1: ";cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }

    ofstream out;
    out.open("input1.txt");
    out<<n;
    out<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            out<<a[i][j]<<" ";
        }
        out<<endl;
    }

    
    cout<<"So Dinh cua do thi 2: ";cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    out.close();
    out.open("input2.txt");
    out<<n;
    out<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            out<<a[i][j]<<" ";
        }
        out<<endl;
    }
    out.close();
}
/*
0 1 0 1 1 0
1 0 1 0 1 1
0 1 0 1 0 1
1 0 1 0 1 0
1 1 0 1 0 1
0 1 1 0 1 0
*/