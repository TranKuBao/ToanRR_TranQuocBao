#include<iostream>
#include<fstream>
#include<string.h>
#define maxx 99 

using namespace std;
struct dske
{
    int list[maxx];
    int so_duong_di;
};
struct dsCanh
{
    int dau[maxx];
    int cuoi[maxx];
    int soluong;
};
int main()
{
    ifstream in;
    in.open("input1.txt");
    int n;
    int a[maxx][maxx];
    in>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            in>>a[i][j];
        }
    }
    in.close();

    struct dske DS_ke[maxx];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]==1)
            {
                DS_ke[i].so_duong_di++;
                DS_ke[i].list[DS_ke[i].so_duong_di]=j;
            }
        }
    }
    ofstream out;
    out.open("input1_1.txt");
    out<<n<<endl;
    for(int i=1;i<=n;i++)
    {
        out<<i<<"   " ;
        for(int j=1;j<=DS_ke[i].so_duong_di;j++)
        {
            out<<DS_ke[i].list[j]<<" ";
        }
        out<<endl;
    }
    out.close();

    out.open("input1_2.txt");
    out<<n<<endl;
    struct dsCanh DS_canh;
    DS_canh.soluong=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]==1 && i<j)
            {
                DS_canh.soluong++;
                DS_canh.dau[DS_canh.soluong]=i;
                DS_canh.cuoi[DS_canh.soluong]=j;
            }  
        }
    }
    for(int i=1;i<=DS_canh.soluong;i++)
    {
        out<<DS_canh.dau[i]<<" "<<DS_canh.cuoi[i]<<endl;
    }
    out.close();
}   