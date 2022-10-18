#include<iostream>
#include<fstream>
#include<string.h>
#define maxx 99 

using namespace std;
struct dske
{
    int soluong;
    int list[maxx];
};
struct dsCanh
{
    int soluong;
    int dau[maxx];
    int cuoi[maxx];
};
int main()
{
    int matrix[maxx][maxx]={0};
    ifstream in;
    in.open("input2.txt");
    int n;
    in>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            in>>matrix[i][j];
        }
    }
    in.close();
    ofstream out;
    out.open("input2_1.txt");
    out<<n<<endl;
    struct dske DS_ke[maxx];
    for(int i=1;i<=n;i++)
    {
        DS_ke[i].soluong=0;
        for(int j=1;j<=n;j++)
        {
            if(matrix[i][j]==1)
            {
                DS_ke[i].soluong++;
                DS_ke[i].list[DS_ke[i].soluong]=j;
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        out<<i<<"   ";
        if(DS_ke[i].soluong!=0)
        {
            for(int j=1;j<=DS_ke[i].soluong;j++)
            {
                out<<DS_ke[i].list[j]<<" ";
            }
        }
        out<<"\n";
    }//in xong DS_ke

    out.close();
    out.open("input2_2.txt");
    out<<n<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(matrix[i][j]!=0)
            {
                
                out<<i<<" "<<j<<endl;
            }
        }
    }

}