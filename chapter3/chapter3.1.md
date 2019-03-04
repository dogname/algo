<!-- @import "[TOC]" {cmd="toc" depthFrom=2 depthTo=3 orderedList=false} -->

<!-- code_chunk_output -->

* [渐进记号](#渐进记号)
* [练习](#练习)
	* [3.1-1](#31-1)
	* [3.1-2](#31-2)
	* [3.1-3](#31-3)
	* [3.1-4](#31-4)
	* [3.1-5](#31-5)
	* [3.1-6](#31-6)
	* [3.1-7](#31-7)
	* [3.1-8](#31-8)

<!-- /code_chunk_output -->
## 渐进记号  

O 渐进上界
$\Omega$渐进下界 

## 练习  

### 3.1-1
存在$n_0$使得$n \geqslant n_0$时，$f(n)\geqslant0,g(n)\geqslant 0 $ 令$c_1=0.5，c_2=1$
那么 
$$c_1(f(n)+g(n))=0.5(f(n)+g(n))\leqslant  max(f(n),g(n))$$
$$c_2(f(n)+g(n))=f(n)+g(n)\geqslant max(f(n),g(n))$$
所以
$$max(f(n),g(n))=\Theta(f(n)+g(n))$$

### 3.1-2 

令$c=\left( (1+\dfrac{a}{n} \right)^b$
当$n\geqslant 2|a|$时存在$c_1=0.5^b,c_2=2^b$使
$$c_1n^b\leqslant (n+a)^b \leqslant c_2 n^b $$
即$$(n+a)^b%=\Theta(n^b)$$

### 3.1-3

$O(n^2)$是上边界，“至少”是下边界

### 3.1-4 

$2^{n+1}=2*2^n=O(2^n)$
$2^{2n}=2^n*2^n>O(n^2)$

### 3.1-5

当 $f(n)=O(g(n)),f(n)=\Omega(g(n))$ 时
$$0\leqslant c_1g(n)\leqslant f(n), n\geqslant n_1$$
$$f(n)\leqslant c_2g(n), n\geqslant n_2$$
所以
$$0\leqslant c_1g(n)\leqslant f(n) \leqslant c_2g(n), n\geqslant max(n_1,n_2)$$
根据定义$f(n)=\Theta(g(n))$
反过来也成立

### 3.1-6
根据定理3.1

### 3.1-7

$f(n)< cg(n) < f(n)$无解所以$o(g(n))\cap\omega(g(n))=\emptyset$

### 3.1-8

$\Omega(g(n,m))={f(n,m):\exist c,n_0,m_0, 当 n\geqslant n_0,m\geqslant m_0,有 f(n,m)\geqslant cg(n,m)}$

$\Theta(g(n,m))={f(n,m):\exist c_1,c_2,n_0,m_0, 当 n\geqslant n_0,m\geqslant m_0,有0\leqslant c_1g(n,m)\leqslant f(n,m)\leqslant c_2g(n,m)}$
