<!-- @import "[TOC]" {cmd="toc" depthFrom=2 depthTo=3 orderList=false} -->

<!-- code_chunk_output -->

* [思考题](#思考题)
	* [3-1](#3-1)
	* [3-2](#3-2)
	* [3-4](#3-4)

<!-- /code_chunk_output -->

## 思考题

### 3-1

a. $$\lim_{n\to\infty}\frac{p(n)}{n^k} \leqslant 1 \Rightarrow p(n)=O(n^k) $$
b. $$\lim_{n\to\infty}\frac{p(n)}{n^k} \geqslant 1 \Rightarrow p(n)=\Omega(n^k) $$
c. $$k=d,p(n)=O(n^k),p(n)=\Omega(n^k)\Rightarrow p(n)=\Theta(n^k)$$
d. $$\lim_{n\to\infty}\frac{p(n)}{n^k} < 1 \Rightarrow p(n)=o(n^k) $$
e. $$\lim_{n\to\infty}\frac{p(n)}{n^k} > 1 \Rightarrow p(n)=\omega(n^k) $$

### 3-2 
|O|o|$\Omega$|$\omega$|$\Theta$|
|:--:|:--:|:--:|:--:|:--:|
|Yes|Yes|No|No|No|
|No|No|Yes|Yes|No|
|No|No|No|No|No|
|No|No|Yes|Yes|No|
|Yes|No|Yes|No|Yes|
|Yes|No|Yes|No|Yes|  

### 3-4 

a. false  
b. fasle  
c. true  
d. false  
e. false, 不过f(n)>1时成立  
f. true  
g. false  
h. true  

