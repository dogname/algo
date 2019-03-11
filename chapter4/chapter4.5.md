<!-- @import "[TOC]" {cmd="toc" depthFrom=2 depthTo=3 orderList=false } -->

<!-- code_chunk_output -->

* [主方法](#主方法)
* [练习](#练习)
	* [4.5-1](#45-1)
	* [4.5-2](#45-2)
	* [4.5-3](#45-3)
	* [4.5-4](#45-4)
	* [4.5-5](#45-5)

<!-- /code_chunk_output -->
## 主方法  

$$T(n)=aT(n/b)+f(n)$$

1. $ f(n)=O(n^{\log_b a-\varepsilon}) \Longrightarrow T(n)=\Theta(n^{\log_ba})$  
1. $ f(n)=\Theta(n^{\log_ba})\Longrightarrow T(n)=\Theta(n^{\log_ba}\lg n) $ 
1. $ f(n)=\Omega(\log_ba+\varepsilon)\Longrightarrow T(n)=\Theta(f(n)) $

## 练习  

### 4.5-1  

a. $T(n)=\Theta(\sqrt{n})$  
b. $T(n)=\Theta(\sqrt{n}\lg n) $  
c. $T(n)=\Theta(n)$ 
d. $T(n)=\Theta(n^2) $

### 4.5-2  

48

### 4.5-3  

$n^{\lg 1}=1=\Theta(1)\Longrightarrow T(n)=\Theta(\lg n)$

### 4.5-4  

不能

$n^{\lg 4-\varepsilon}=n^{2-\varepsilon}\neq O(...)\neq O(...)$

### 4.5-5

