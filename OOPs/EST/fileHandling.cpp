#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int main()
{
   fstream f;
   int a[100];
   int n = 0;

   f.open("abc.dat", ios::binary| ios::out);
   if(f.fail()) {
       cout<<"error opening";
   }

   int arr[] = {4,5,1,3,6,7,1};
   f.write((char*) &arr,sizeof(arr));
   f.close();


   f.open("abc.dat",ios::binary|ios::in);
   if(f.fail()) {
       cout<<"error opening file";
   }
   while(f.read((char*)(&a[n]), sizeof(int)))
   {
       n++;
   }

   for(int i=0;i<n-1;++i)
   {
       for(int j=0;j<n-i-1;++j)
       {
           if (a[j]>a[j+1])
           {
               int t=a[j];
               a[j]=a[j+1];
               a[j+1]=t;
           }

       }
   }
   f.close();
   f.open("abc.dat",ios::binary|ios::out|ios::trunc);

  for(int i=0;i<n;++i)
   {
       f.write((char*)(&a[i]),sizeof(int));
   }
f.close();
}
