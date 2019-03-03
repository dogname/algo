<!-- @import "[TOC]" {cmd="toc" depthFrom=2 depthTo=3 orderedList=false} -->

<!-- code_chunk_output -->

* [练习](#练习)
	* [2.2-1](#22-1)
	* [2.2-2](#22-2)
	* [2.2-3](#22-3)
	* [2.2-4](#22-4)

<!-- /code_chunk_output -->
## 练习  

### 2.2-1

$\Theta(n^3)$  

### 2.2-2 

```c

SELECTION-SORT(A)
    for i = 1 to A.length-1
        min_index = i
        for j = i + 1 to A.length
            if(A[min_index] < A[j])
                min_index = j
        temp = A[i]
        A[i] = A[min_index]
        A[min_index] = temp
```

循环不变式 
> 在第i次循环开始时，前i-1项已经排好序且所有项都不比后面的项大  

为啥前n-1项
> 根据循环不变式，前n-1项排完后，最后一项一定是最大值  

最好情况
> $T(n) = (n-1)+(n-1)+2(n+1)(n-2)/2+(n-1)+(n-1)+(n-1)=\Theta(n^2)$

最坏情况
> $T(n) = (n-1)+(n-1)+3(n+1)(n-2)/2+(n-1)+(n-1)+(n-1)=\Theta(n^2)$

### 2.2-3  

结果的可能分布$f(x)=\frac{1}{n}$  
平均检查(比较)次数 $T(n) =\sum_{i=1}^{n}\frac{i}{n}=\frac{n+1}{2}$
最坏的检查次数 n 
最好与最坏的时间复杂度都是$\Theta(n)$ 

### 2.2-4 

先进行验证
