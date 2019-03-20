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

### 4.3-6

> Show that the solution to $T(n)=2T(\lfloor n/2 \rfloor+17)+n$ is $O(n\lg n)$

假设 $m<n$ 时 $T(m)=O\left((m-34)\lg (m-34)\right)$, 特别的，当 $ m=\lfloor n/2\rfloor $时
$ T(n)\leqslant 2c(\lfloor n/2\rfloor-17)\lg (\lfloor n/2  \rfloor-17)+n\leqslant 2c(n/2-17)\lg(n/2-17)+n=c(n-34)\lg\dfrac{n-34}{2}+n=c(n-34)\lg(n-34)-c(n-34)+n\leqslant c(n-34)\lg(n-34)$
$$n\geqslant \dfrac{34c}{c-1}, c>1$$

$T(n)=O((n-34)\lg(n-34))=O(n\lg n)$

### 4.3-7 

> Using the master method in Section 4.5, you can show that the solution to the recurrence $ T(n)= 4T(n/3)+n = \Theta(n^{\log_34}) $. Show that a substitution proof with the assumption $ T(n)\leqslant cn^{\log_34} $ fails. Then show how to subtract off a lower-order term to make a substitution proof work.

$ T(n)\leqslant 4c(n/3)^{\log_34}+n=cn^{\log_34}+n$
错误的结束了

assumption $T(n)\leqslant cn^{\log_34}-an$
