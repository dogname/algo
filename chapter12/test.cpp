#include "bintree.h"
int main()
{
  int a[20]={7,4,2,6,5,1,8,3,9,10,1,2,1,1,1};
  BinTree Bt(a,20);
  Bt.InorderTreeWalk();
  Bt.InorderTreeWalk();
  return 0;
}
