<!-- @import "[TOC]" {cmd="toc depthFrom=2 depthTo=3 orderList=false} -->

<!-- code_chunk_output -->

* [习题](#习题)
	* [4.1-1](#41-1)
	* [4.1-2](#41-2)
	* [4.1-3](#41-3)
	* [4.1-4](#41-4)

<!-- /code_chunk_output -->
## 习题  

### 4.1-1

返回最大值与它的索引

### 4.1-2

```c
FIND_MAXIMUM_SUBARRAY(A)
    lindex = 0
    rindex = 0
    sum    = -INF
    for i = 1 to A.length
        tmp = 0
        for j = i to A.length
            tmp += A[j]
            if tmp > sum 
                sum    = tmp
                lindex = i
                rindex = j
    return(lindex, rindex, sum)
```

### 4.1-3  


### 4.1-4 

> 如果最终结果是负数，就返回空子数组

### 4.1-5 

```c

FIND_MAXIMUM_SUBARRAY(A)
    l=1
    r=1
    sum = A[1]
    for i = 1 to A.length
        tmp = 0
        for j = i + 1 downto 1
            tmp += A[j]
            if(tmp > sum)
                sum = tmp 
                l   = j
                r   = i+1
    return(l, r ,sum)

```