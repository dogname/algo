<!-- @import "[TOC]" {cmd="toc" depthFrom=2 depthTo=3 orderedList=false} -->

<!-- code_chunk_output -->

* [思考题](#思考题)
	* [2-1](#2-1)
	* [2-2](#2-2)
	* [2-3](#2-3)

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
> 初始: 当$i=n$时，$y=0$ 满足
> 保持: 假设当n=k时，满足和式 $  $ 