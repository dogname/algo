<!-- @import "[TOC]" {cmd="toc" depthFrom=2 depthTo=3 orderedList=false} -->

<!-- code_chunk_output -->

* [思考题](#思考题)
	* [2-1](#2-1)
	* [2-2](#2-2)
	* [2-3](#2-3)
	* [2-4](#2-4)

<!-- /code_chunk_output -->

## 思考题

### 2-1 

a. $T(n)=\dfrac{n}{k}T(k)=\frac{n}{k}\Theta\left( k^2 \right)=\Theta(nk)$
b. 合并层数为 $lg(n/k)$ 合并是线性复杂度 $T(n)=\Theta(nlg(n/k))$  
c. $lgn$
d. 

### 2-2

a. 还应该包含A'与A的元素相同  
b. A[j..n]中最小的元素被交换到A'[j]
c. 
d. $\Theta(n^2)$不过有更大的常数

### 2-3  

a. n次乘法和n次加法$T(n)=\Theta(n)$
b. 

```c
y = 0
for i = 0 to n
    temp = 1
    for j = 0 to i
        temp =  x * temp
    y = y + a[i]* temp;
```
$ T(n)=\Theta(n^2)$, 比Horner要慢
c. 
> 初始: y=0 根据约定满足式子
> 保持:  设某次开始前满足式子，下次迭代前，即本次结束后
\[y=a_i+x\sum_{k=0}^{n-(i+1)}a_{k+i+1}x^k
=a_ix^0+\sum_{k=0}^{n-(i+1)}a_{k+i+1}x^{k+1}
=a_ix^0+\sum_{k=1}^{n-i+1}a_{k+i}x^k=\sum_{k=0}^{n-(i-+1)}a_{k+i-1+1}x^k\]
仍然满足式子。  

d. 

### 2-4 

a. (1,5) (2,5) (3,4) (3,5) (4,5). 
b. 递减数组共有$(n-1)+...+1=n(n-1)/2$. 
c. 插入排序只进行相邻元素的赋值，一次减少一对逆序队对。显然，排序完成时不存在逆序对
所以插入排序的复杂度与逆序对恶的数目成正比
d. 