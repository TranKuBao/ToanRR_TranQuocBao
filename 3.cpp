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
int chuyenKieu(char s[])
{
    int res = 0;
    for(int i = 0; i < strlen(s); i++ )
    {
        res = res*10 + ((int)s[i] - 48) ;
    }
    return res;
}
int main()
{
    dske DS_ke[maxx];
    FILE *f=NULL;
    char arr[100],*p;
    f=fopen("input1_1.txt","r");
    int k,luu,n;
    fscanf(f,"%d",&n);
    while(fgets(arr,100,f) != NULL)
    {
        p=strtok(arr," ");
        int dem=0;
        while(p!=NULL)
        {
            k=chuyenKieu(p);
            if(dem==0)
            {
                luu=k;
                dem++;
                DS_ke[luu].so_duong_di=0;
            }
            else
            {
                DS_ke[luu].so_duong_di++;
                DS_ke[luu].list[DS_ke[luu].so_duong_di]=k;
            }
            p=strtok(NULL," ");
        } 
    }
    // đọc ghi vào DS_ke xong

    ofstream out;
    out.open("output1_1.txt");
    int matrix[maxx][maxx]={0};
    for(int i=1;i<=n;i++)
    {
        if(DS_ke[i].so_duong_di!=0)
        {
            for(int j=1;j<DS_ke[i].so_duong_di;j++)
            {
                matrix[i][DS_ke[i].list[j]]=1;
            }
        }
    }
    out<<n<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            out<<matrix[i][j]<<" ";
        }
        out<<endl;
    }// in xong ma trận kề
    out<<"Ma Tran ke!!!\n";

    dsCanh DS_canh;
    DS_canh.soluong=0;
    int deg[maxx]={0};
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(matrix[i][j]==1)
            {
                deg[i]++;
            }
            if(matrix[i][j]==1 && i<j)
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
    out<<"Danh sach canh!!\n";
    //in xong danh sach KE

    for(int i=1;i<=n;i++)
    {
        out<<"deg("<<i<<")= "<<deg[i]<<"\t";
    }
    out.close();
}