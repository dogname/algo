<!-- @import "[TOC]" {cmd="toc" depthFrom=2 depthTo=3 orderList=false} -->

<!-- code_chunk_output -->

* [分治法](#分治法)
* [练习](#练习)
	* [2.3-1](#23-1)
	* [2.3-2](#23-2)
	* [2.3-3](#23-3)
	* [2.3-4](#23-4)
	* [2.4-5](#24-5)
	* [2.4-6](#24-6)

<!-- /code_chunk_output -->
# 设计算法  

## 分治法  

1. 分解：原问题分解为结构相同的小问题
2. 解：  解决子问题  
3. 合并: 合并子问题  

## 练习

### 2.3-1  
![merge](/assets/merge_2sk7kvf09.svg)

### 2.3-2

```c
void Merge(int* ar, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	int *left, *right;
	left = new int[n1];
	right = new int[n2];
	memcpy(left, &ar[p], n1 * sizeof(int));
	memcpy(right, &ar[q + 1], n2 * sizeof(int));
	int i = 0, j = 0;
	for (int k = p; k <= r; k++)
	{

		if (i < n1 && j < n2)
		{
			if (left[i] < right[j])
			{
				ar[k] = left[i];
				i++;
			}
			else
			{
				ar[k] = right[j];
				j++;
			}
		}
		else if (i == n1)
		{
			ar[k] = right[j];
			j++;
		}
		else
		{
			ar[k] = left[i];
			i++;
		}
	}
	delete[] left;
	delete[] right;
}

void MergeSort(int* ar, int p, int r)
{
	if (p < r)
	{
		int q = (r + p) / 2;
		MergeSort(ar, p, q);
		MergeSort(ar, q + 1, r);
		Merge(ar, p, q, r);
	}
}

```

### 2.3-3

证明:

1. $n=2$ 时，$T(n)=2log_22=2$ 成立
2. 假设$n=2^k, k =1,2,\cdots$ 时 $T(2^k)=2^k log_2(2^k)=k2^k$成立
则$n=2^{k+1}$，时 $T(2^{k+1})=2T(2^k)+n=2\times T(2^k)+2^{k+1}=(k+1)2^{k+1}=nlog_2 n$成立  

### 2.3-4

$$T(n)=\begin{cases}
\Theta(1) &n=1\\
T(n-1)+Cn &n>1
\end{cases}$$

### 2.4-5

```c
BINARY-SEARCH(A,v)
    left = 1
    right = A.length
    while left <= right
        mid = (right+left)/2
        if(v = A[mid])
            return mid
        if(v < A[mid])
            high = mid - 1
        else 
            high = mid + 1
    return NIL
```
$$T(n)=\begin{cases}
\Theta(1) &n=1\\
\theta(1) + T(n/2) &n>1;
\end{cases}$$

### 2.4-6

不行，虽然查找时间变为对数增长，但是插入需要移动元素仍然线性增长

 ### 2.4-7

 考虑用归并排序后在二分查找
 ```c

EXISTENCE(S,x)
    MERGE-SORT(S)
    sum = x1 + x2;
    for i = 1 to S.length
        if BIANRY-SEARCH(S, x-S[i]) != NIL)
            return true
    return false

 ```
