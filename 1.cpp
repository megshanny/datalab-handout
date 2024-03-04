#include <iostream>
using namespace std;

int thirdBits(void) 
{
  int a1=9; // 1 001
  int a2=a1<<6|a1; // 1 001 001 001   // 12
  int a3=a2<<12|a2; // 1 001 001 001 001 001 001 001 // 24 
  int a4=a3<<9|a3; // 
//    cout<<a4<<endl;
  return a4;
}
int fitsShort(int x) 
{
  int x1=x<<16;
  int x2=x1>>16;
  int ans=!(x2^x);
//   cout<<ans<<endl;
  return ans;
}
int isTmax(int x) 
{
  int x1=x+1; // 0000
//   cout<<x1<<endl;
  int x2=~x1; // 1111
//   cout<<x2<<endl;
  int ans=x^x2;
//   cout<<(!ans)&()<<endl;
  return !ans;
}
int upperBits(int n) 
{ 
  int a=1<<31;
  int a1=a<<!n;
  int ans=a1>>(n+1+~1);
//   cout<<ans<<endl;
//   cout<<(-1<<33)<<endl;
  return ans;
}
int absVal(int x) 
{
  int a=x>>31;
//   cout<<a<<endl;
  int ans=x^a;
  ans+=!!a;
//   cout<<(x^a)<<" "<<!!a<<endl;
//   cout<<2147483646+1<<endl;
//   cout<<ans<<endl;
  return ans;
}
int divpwr2(int x, int n) 
{
    int ans=x>>n;
    cout<<ans<<endl;
    int sum=(!!(x>>31))&(!!n);
    cout<<sum<<endl;
    ans=ans+sum;
    cout<<ans<<endl;
    return ans;
}
int bitMask(int highbit, int lowbit) 
{
  int ff=~0;
  int ans=(ff<<(lowbit))&(~(ff<<(highbit+1)));
  cout<<(ff<<(lowbit))<<endl;
  cout<<(!(ff<<(highbit+1)))<<endl;
  cout<<"ans = "<<ans<<endl;
  return ans;
}
int logicalShift(int x, int n)
{
  int x1=x>>n;
  int x2=~((~0)<<(32+(~n))<<1);
  cout<<(x1&x2)<<endl;
  return x1&x2;
}
int main()
{
    // thirdBits();
    // fitsShort(33368);
    // isTmax(-1);
    // upperBits(1);
    // absVal(0x80000001);
    // divpwr2(0x80000000,0);
    // bitMask(0,2);
    logicalShift(0x80000000,0);
    return 0;
}

