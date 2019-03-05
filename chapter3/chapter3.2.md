## 标准记号与常用函数

1. 模运算
    1. 取余$a\mod b = a - n\lfloor a/n\rfloor$   
    2. 同余 $if\ a\ mod\ n=b\ mod\ n$记$a\equiv b(mod\ n)$  
        - $a\equiv b(mod\ n)\Leftrightarrow (a-b)mod\ n=0$
2. 阶乘  
    - 斯特林(Stirling) 公式
    $$n! = \sqrt{2\pi n}\left( \dfrac{n}{e} \right)^n\left( 1+\Theta\left(\dfrac{1}{n}\right)\right)$$  
    - \[ n! = \sqrt{2\pi n}\left( \dfrac{n}{e} \right)^ne^{a_n},\qquad \dfrac{1}{12n+1}< a_n < \dfrac{1}{12n} \]
3. 斐波那契数列  
\[ F(n)=\begin{cases}
0& n=0\\
1& n=1\\
F(n-1)+F(n-2)& n\geqslant 2
\end{cases} \]
    - 通项公式  
    \[ F_n=\dfrac{\phi^n-\hat{\phi}^n}{\sqrt{5}} \]
    - $ \phi,\hat{\phi} $是$x^2=x+1$的两个根  

## 练习  

### 3.2-1  

> $n \geqslant m\Rightarrow f(n)\geqslant f(m), g(n)\geqslant g(m)\Rightarrow f(n)+g(n) \geqslant f(m)+g(m)\Rightarrow f(n)+g(n)$ 是单调递增函数
> $n \geqslant m\Rightarrow g(n)\geqslant g(m)\Rightarrow f(g(n))\geqslant f(g(m))\Rightarrow f(g(n)) $是单调递增函数


### 3.2-2  

> $ a^{log_bc}=a^{log_aclog_ba}=c^{log_ba} $

### 3.2-3 

> $$\lg (n!) = \lg\left( \sqrt{2\pi n}\left( \dfrac{n}{e} \right)^n\left( 1+\Theta\left(\dfrac{1}{n}\right)\right)\right)=\Theta(\lg\sqrt(n))+\Theta(n\lg n)+\Theta(1/n) = \Theta(n\lg n) $$ 
> $n > 2, \dfrac{n!}{2^n} > 1$  
> $n>3,\dfrac{n!}{n^n}<1$  

### 3.2-4 

不会

### 3.2-5  
$$ \lg^*(\lg{n}) = \lg^*n - 1 > \lg(\lg^*(n))$$

### 3.2-6 

计算一下

### 3.2-7  

1. $F_0=0,F_1=1$显然满足  
2. 假设满足$F_{n-2}=\dfrac{\phi^{n-2}-\hat{\phi}^{n-2}}{\sqrt{5}},F_{n-1}=\dfrac{\phi^{n-1}-\hat{\phi}^{n-1}}{\sqrt{5}}$
\[ F_n=F_{n-2}+F_{n-1}=\dfrac{\phi^{n-2}(1+\phi)-\hat{\phi}^{n-2}(1+\hat{\phi})}{\sqrt{5}}=\dfrac{\phi-\hat{\phi}}{\sqrt{5}} \]

### 3.2-8

$ k\ln k = \Theta(n)\Rightarrow n=\Theta(k\ln k)\Rightarrow \ln n = \Theta(\ln k)\Rightarrow n/ \ln n=\Theta(k\ln k /\ln k)=\Theta(k)\Rightarrow k=\Theta(n\ln n) $