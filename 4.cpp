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

// ghi matran * ds_ke * deg
int main()
{
    int n;
    FILE *f=NULL;
    f=fopen("input1_2.txt","r");
    fscanf(f,"%d",&n);
    dsCanh DS_canh;
    DS_canh.soluong=1;
    while(fscanf(f,"%d %d",&DS_canh.dau[DS_canh.soluong],&DS_canh.cuoi[DS_canh.soluong]) != EOF)
    {
        DS_canh.soluong++;
    }
    DS_canh.soluong--;
    // đọc xong DS canh
    
    ofstream out;
    out.open("output1_2.txt");
    int matrix[maxx][maxx]={0};
    int d,c;
    for(int i=1;i<=DS_canh.soluong;i++)
    {
        d=DS_canh.dau[i];
        c=DS_canh.cuoi[i];
        matrix[d][c]=1;
        matrix[c][d]=1;
    }
    out<<n<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            out<<matrix[i][j]<<" ";
        }
        out<<endl;
    }
    out<<"-----------ma tran ke-------------\n";
    //in xong ma traan

    int deg[maxx]={0};
    struct dske DS_ke[maxx];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(matrix[i][j]==1)
            {
                deg[i]++;
            }
            if(matrix[i][j]==1)
            {
                DS_ke[i].so_duong_di++;
                DS_ke[i].list[DS_ke[i].so_duong_di]=j;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        out<<i<<"   " ;
        for(int j=1;j<=DS_ke[i].so_duong_di;j++)
        {
            out<<DS_ke[i].list[j]<<" ";
        }
        out<<endl;
    }
    out<<"---------DS_KE-------\n";
    //in xong ds ke

    for(int i=1;i<=n;i++)
    {
        out<<"deg("<<i<<")= "<<deg[i]<<"\t";
    }
    out.close();
}