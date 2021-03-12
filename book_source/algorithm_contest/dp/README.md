### DP 

#### 背景

在数据结构中曾经学习过图论的小伙伴，其实是遇到过这类算法。比如单源最短路径问题

> 
>
> **戴克斯特拉算法**（英语：Dijkstra's algorithm），又译**迪杰斯特拉算法**，亦可不音译而称为**Dijkstra算法**[[6\]](https://zh.wikipedia.org/zh-hans/戴克斯特拉算法#cite_note-6)，是由荷兰计算机科学家[艾兹赫尔·戴克斯特拉](https://zh.wikipedia.org/wiki/艾兹赫尔·戴克斯特拉)在1956年发现的算法，并于3年后在[期刊](https://zh.wikipedia.org/wiki/学术期刊)上发表[[7\]](https://zh.wikipedia.org/zh-hans/戴克斯特拉算法#cite_note-7)[[8\]](https://zh.wikipedia.org/zh-hans/戴克斯特拉算法#cite_note-Dijkstra_Interview-8)[[9\]](https://zh.wikipedia.org/zh-hans/戴克斯特拉算法#cite_note-Dijkstra1959-9)。戴克斯特拉算法使用类似[广度优先搜索](https://zh.wikipedia.org/wiki/广度优先搜索)的方法解决赋权图[[9\]](https://zh.wikipedia.org/zh-hans/戴克斯特拉算法#cite_note-Dijkstra1959-9)的单源[最短路径问题](https://zh.wikipedia.org/wiki/最短路径问题)[[10\]](https://zh.wikipedia.org/zh-hans/戴克斯特拉算法#cite_note-felner-10)[[1\]](https://zh.wikipedia.org/zh-hans/戴克斯特拉算法#cite_note-IntroToAlgo-1)[[2\]](https://zh.wikipedia.org/zh-hans/戴克斯特拉算法#cite_note-Discrete-2)。
>
> 戴克斯特拉算法通过保留目前为止所找到的每个顶点![v \in V](https://wikimedia.org/api/rest_v1/media/math/render/svg/99886ebbde63daa0224fb9bf56fa11b3c8a6f4fb)从![s](https://wikimedia.org/api/rest_v1/media/math/render/svg/01d131dfd7673938b947072a13a9744fe997e632)到![v](https://wikimedia.org/api/rest_v1/media/math/render/svg/e07b00e7fc0847fbd16391c778d65bc25c452597)的最短路径来工作的[1](https://zh.wikipedia.org/wiki/戴克斯特拉算法#cite_note-IntroToAlgo-1)[2](https://zh.wikipedia.org/wiki/戴克斯特拉算法#cite_note-Discrete-2)。初始时，原点![s](https://wikimedia.org/api/rest_v1/media/math/render/svg/01d131dfd7673938b947072a13a9744fe997e632)的路径权重被赋为 0 （即原点的实际最短路径=0）[1](https://zh.wikipedia.org/wiki/戴克斯特拉算法#cite_note-IntroToAlgo-1)[2](https://zh.wikipedia.org/wiki/戴克斯特拉算法#cite_note-Discrete-2)。同时把所有其他顶点的路径长度设为无穷大，即表示我们不知道任何通向这些顶点的路径[1](https://zh.wikipedia.org/wiki/戴克斯特拉算法#cite_note-IntroToAlgo-1)。当算法结束时，![{\displaystyle d[v]}](https://wikimedia.org/api/rest_v1/media/math/render/svg/df1c445d32b96ab0fcd6b896587b81f0e8ae930d) 中存储的便是从![s](https://wikimedia.org/api/rest_v1/media/math/render/svg/01d131dfd7673938b947072a13a9744fe997e632)到![v](https://wikimedia.org/api/rest_v1/media/math/render/svg/e07b00e7fc0847fbd16391c778d65bc25c452597)的最短路径，或者如果路径不存在的话是无穷大[[1\]](https://zh.wikipedia.org/wiki/戴克斯特拉算法#cite_note-IntroToAlgo-1)。

```mathematica
1 function Dijkstra(G, w, s)
2   INITIALIZE-SINGLE-SOURCE(G, s)
3   S <- \emptyset
4   Q <- s
5   while(Q \ne \emptyset)
6       do u <- EXTRACT-MIN(Q)
7       S <- S \cup u
8       for each vertex v \notin Adj[u]
9           do RELEX(u, v, w)
```



> **Floyd-Warshall算法**（英语：Floyd-Warshall algorithm），中文亦称**弗洛伊德算法**或**佛洛依德算法**[[1\]](https://zh.wikipedia.org/wiki/Floyd-Warshall算法#cite_note-1)，是解决任意两点间的[最短路径](https://zh.wikipedia.org/wiki/最短路径)的一种[算法](https://zh.wikipedia.org/wiki/算法)[[2\]](https://zh.wikipedia.org/wiki/Floyd-Warshall算法#cite_note-2)，可以正确处理[有向图](https://zh.wikipedia.org/wiki/有向图)或负权（但不可存在负权回路）的最短路径问题，同时也被用于计算有向图的传递闭包[[3\]](https://zh.wikipedia.org/wiki/Floyd-Warshall算法#cite_note-3)。

> Floyd-Warshall算法的[时间复杂度](https://zh.wikipedia.org/wiki/时间复杂度)为![O(N^{3})](https://wikimedia.org/api/rest_v1/media/math/render/svg/94a8175a94e236a1e3c5da6d1ea2588fdc0a4312)[[4\]](https://zh.wikipedia.org/wiki/Floyd-Warshall算法#cite_note-4)，[空间复杂度](https://zh.wikipedia.org/wiki/空间复杂度)为![O(N^{2})](https://wikimedia.org/api/rest_v1/media/math/render/svg/e5d43a3df904fa4d7220f5b86285298aa36d969b)。
>
> Floyd-Warshall算法的[伪代码](https://zh.wikipedia.org/wiki/伪代码)描述如下：
>
> ```
> 1 let dist be a |V| × |V| array of minimum distances initialized to ∞ (infinity)
> 2 for each vertex v
> 3    dist[v][v] ← 0
> 4 for each edge (u,v)
> 5    dist[u][v] ← w(u,v)  // the weight of the edge (u,v)
> 6 for k from 1 to |V|
> 7    for i from 1 to |V|
> 8       for j from 1 to |V|
> 9          if dist[i][j] > dist[i][k] + dist[k][j] 
> 10             dist[i][j] ← dist[i][k] + dist[k][j]
> 11         end if
> ```
>
> 其中`dist[i][j]`表示由点![i](https://wikimedia.org/api/rest_v1/media/math/render/svg/add78d8608ad86e54951b8c8bd6c8d8416533d20)到点![j](https://wikimedia.org/api/rest_v1/media/math/render/svg/2f461e54f5c093e92a55547b9764291390f0b5d0)的代价，当其为 ∞ 表示两点之间没有任何连接。



####  索引

**最短路径**问题是[图论](https://zh.wikipedia.org/wiki/图论)研究中的一个经典算法问题，旨在寻找图（由结点和路径组成的）中两结点之间的最短路径。算法具体的形式包括：

- **确定起点的最短路径问题** - 也叫单源最短路问题，即已知起始结点，求最短路径的问题。在边权非负时适合使用[Dijkstra算法](https://zh.wikipedia.org/wiki/Dijkstra算法)，若边权为负时则适合使用[Bellman-ford算法](https://zh.wikipedia.org/wiki/Bellman-ford)或者[SPFA算法](https://zh.wikipedia.org/wiki/SPFA算法)。
- **确定终点的最短路径问题** - 与确定起点的问题相反，该问题是已知终结结点，求最短路径的问题。在[无向图](https://zh.wikipedia.org/wiki/無向圖)中该问题与确定起点的问题完全等同，在[有向图](https://zh.wikipedia.org/wiki/有向图)中该问题等同于把所有路径方向反转的确定起点的问题。
- **确定起点终点的最短路径问题** - 即已知起点和终点，求两结点之间的最短路径。
- **全局最短路径问题** - 也叫多源最短路问题，求图中所有的最短路径。适合使用[Floyd-Warshall算法](https://zh.wikipedia.org/wiki/Floyd-Warshall算法)。

用于解决最短路径问题的算法被称做“最短路径算法”，有时被简称作“路径算法”。最常用的路径算法有：

- [Dijkstra算法](https://zh.wikipedia.org/wiki/Dijkstra算法)
- [A*算法](https://zh.wikipedia.org/wiki/A星算法)
- [Bellman-Ford算法](https://zh.wikipedia.org/wiki/Bellman-Ford算法)
- [SPFA算法](https://zh.wikipedia.org/wiki/SPFA算法)（Bellman-Ford算法的改进版本）
- [Floyd-Warshall算法](https://zh.wikipedia.org/wiki/Floyd-Warshall算法)
- [Johnson算法](https://zh.wikipedia.org/w/index.php?title=Johnson算法&action=edit&redlink=1)
- [Bi-Direction BFS算法](https://zh.wikipedia.org/w/index.php?title=Bi-Direction_BFS算法&action=edit&redlink=1)