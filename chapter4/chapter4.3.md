## 用代入法求解递归

## 练习

### 4.3-1 

假设$m<n$时都成立，当$m=n-1$时
$$T(n)\leqslant c(n–1)^2+n=cn^2–n(2c-c/n-1)\leqslant cn^2,c>1$$
$$T(1)=1$$满足

### 4.3-2

假设满足$O(lg (n-1/2))$
$$T(n)\leqslant c\lg ((n+1)/2-1/2) +1=clg n-c+1\leqslant c\lg n$$

### 4.3-3 

添加常数

### 4.3-4

$n\lg n + n$

### 4.3-5  

假设$T(n)=O(n\lg (n-1/2) +n+1)=O(nlg n)$
$$T(1)=\Theta(1)\leqslant O(\lg 1/2 +2)=O(1)$$
满足，假设 $ m < n $ 时的m都成立 当 $m=\lfloor n/2 \rfloor$, 与$m=\lceil n/2 \rceil =\lfloor (n+1)/2  \rfloor$ 带入

$ T(n) \leqslant \lfloor (n+1)/2  \rfloor\lg (\lfloor (n+1)/2 \rfloor -1/2)+\lfloor n/2\rfloor \lg (\lfloor n/2\rfloor -1/2)+\Theta(n)\leqslant nlg n+\Theta(n)$


