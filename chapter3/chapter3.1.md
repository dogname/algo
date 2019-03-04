## 渐进记号  

O 渐进上界
$\Omega$渐进下界 

## 练习  

### 3.1-1
存在$n_0$使得$n\reqslant n_0$时，$f(n)\reqslant 0,g(n)\reqslant 0 $ 令$c_1=0.5，c_2=1$
那么 
$$c_1(f(n)+g(n))=0.5(f(n)+g(n))\leqslant  max(f(n),g(n))$$
$$c_2(f(n)+g(n))=f(n)+g(n)\reqslant max(f(n),g(n))$$
所以
$$max(f(n),g(n))=\Theta(f(n)+g(n))$$

### 3.1-2 

令$c=\left( (1+\dfrac{a}{n} \right)^b$
当$n\reqslant 2|a|$时存在$c_1=0.5^b,c_2=2^b$使
$$c_1n^b\leqslant (n+a)^b \leqslant c_2 n^b $$
即$$(n+a)^b%=\Theta(n^b)$$

### 3.1-3
