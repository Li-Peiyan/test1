## 摊还分析

### 1、二项队列

- Insert 的摊还运行时间是 O(1)

- DeleteMin 的摊还运行时间是 O(log N)

- Merge 的摊还运行时间 O(log N)

### 2、斜堆

- 合并两个斜堆（Merge）的摊还运行时间是 O(log N)
- Insert、DeleteMin 操作基本上是一些 Merge 操作，摊还运行时间是 O(log N)

### 3、斐波那契堆

- Insert 和 Merge 对于懒惰二项队列的摊还运行时间是 O(1)，DeleteMin 对于懒惰二项队列的摊还运行时间对是 O(log N)

- Insert 的摊还运行时间对于斐波那契堆是 O(1)

- Merge 的摊还运行时间对于斐波那契堆 O(1)
- DecteaseKey 的摊还运行时间对于斐波那契堆 O(1)
- DeleteMin 的摊还运行时间对于斐波那契堆是 O(log N)

### 4、伸展树

- 在节点X展开一棵根为T的树的摊还时间最多为 3(R(T)一R(X))＋1=O(log N)
