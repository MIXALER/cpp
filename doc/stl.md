## 1 STL 基本概念

### 1.1 STL 的诞生

-   C++ 需要一套标准的，可以重复利用的基本数据结构和算法
-   体现 C++ 的**面向对象**和**泛型编程**思想

### 1.2 基本概念

-   全称 Standard Template Library 标准模板库
-   广义上分为：容器（container）算法（algorithm）迭代器（iterator）
-   **容器和算法之间通过迭代器无缝连接**
-   STL 几乎所有的代码都采用了模板类或者模板函数

### 1.3 STL 六大组件

分别是： 容器，算法，迭代器，仿函数，适配器（配接器），空间配置器

1.  容器：各种数据结构，如 vector，list，deque，set，map 等，用来存放数据
2.  算法：各种常用的算法，如 sort，find，copy， for_each 等
3.  迭代器：扮演了容器与算法之间的胶合剂
4.  仿函数：行为类似函数，作为算法的某种策略
5.  适配器：一种用来修饰容器或者仿函数或者迭代器接口的东西
6.  空间适配器：负责空间的配置与管理，在堆区开辟和释放内存

### 1.4 容器，算法，迭代器

容器：

将运用最广泛的一些数据结构实现出来

常用的数据结构：数组，链表，树，栈，队列，集合，哈希表等

分为 **序列式容器** 和 **关联式容器**

-   **序列式容器**：强调值得排序，每个元素都有固定的位置，array，vector

-   **关联式容器**：二叉树结构，各元素没有严格的物理上的顺序关系

算法

两类：

-   质变算法：运算过程中会改变区间内元素的内容，拷贝，替换，删除等
-   非质变算法：不会更改区间元素的内容，查找，计数，遍历，求最值等

迭代器

容器和算法之间的粘合剂

提供一种方法，使之能够按顺序访问某个容器所含的各个元素，而又无需暴露该容器的内部表示方式

每个容器都有自己专属的迭代器

迭代器使用非常类似于指针，初学阶段可以理解迭代器为指针

迭代器种类：

| 种类           | 功能                                                   | 支持运算                                 |
| -------------- | ------------------------------------------------------ | ---------------------------------------- |
| 输入迭代器     | 对数据的只读访问                                       | 只读，支持 ++，==，！=                   |
| 输出迭代器     | 对数据的只写访问                                       | 只写，支持 ++                            |
| 前向迭代器     | 读写操作，并能向前推进迭代器                           | 读写，支持 ++，==，！=                   |
| 双向迭代器     | 读写操作，并能向前和向后操作                           | 读写，支持 ++，--                        |
| 随机访问迭代器 | 读写操作，可以跳跃的方式访问任意数据，功能最强的迭代器 | 读写，支持 ++，--，[n], -n, <, <=, >, >= |

常用容器中迭代器种类为双向迭代器和随机访问迭代器

## 2 常用容器

### 2.1 string 容器

#### 2.1.1 基本概念

#### 2.1.2 构造函数

#### 2.1.3 赋值操作



### 2.2 vector 容器

### 2.3 deque 容器

### 2.4 stack 容器

### 2.5 queue 容器

### 2.6 list 容器

### 2.7 set / multiset 容器

### 2.8 map / multimap 容器








