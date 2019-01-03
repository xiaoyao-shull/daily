
# Table of Contents

1.  [Single Source Shortest Path Problems in Directed Acyclic Networks](#orga788e72)
    1.  [The Pulling Algorithm](#orgf37a7e2)
    2.  [The Reaching Algorithm](#orgde7a2ee)
2.  [Single Source Shortest Path Problems in Networks With No Negative Arc Length](#org1781e69)
    1.  [Dijkstra Algorithm](#org6251cd3)
    2.  [Optimization: Bidiretional Search](#org5e2f789)
    3.  [Optimization: Heap](#orga6d726d)
    4.  [Optimization: Dial's Implementation](#org8da8d5f)
3.  [Single Source Shortest Path Problems in Networks With Arbitrary Arc Lengths](#orgba4f38b)
    1.  [Optimality Condition](#orgc8e16e9)
    2.  [Generic Label-Correcting Algorithm](#orgdb3d8d0)
    3.  [Modified Label-Correcting Algorithm](#orgbcc687b)
    4.  [Detecting Negative Cycles](#orgcac6707)
4.  [All-Pair Shortest Path Problems in Networks With Arbitrary Arc Lengths](#orgc25797e)
    1.  [Repeated Shortest Path Algorithm](#orgd22f040)
    2.  [Generic Label-Correcting Algorithm](#org02cae3a)
    3.  [Floyd-Warshall Algorithm](#org55bc521)
    4.  [Detecting Negative Cycles](#org29c80f6)



<a id="orga788e72"></a>

# Single Source Shortest Path Problems in Directed Acyclic Networks

-   A topological ordering of nodes is available for a directed acyclic network such that for any \((i, j) \in A\), \(i\) appears before \(j\) in the ordering.
-   Two similar algorithms based on this topological ordering can be established.
-   The complexity is \(O(m)\) for both algorithms, since each arc is examined exactly once in each execution.
-   The reaching algorithm is prefered since we usually maintain the adjacent-list \(A(i)\) for node \(i \in N\).


<a id="orgf37a7e2"></a>

## The Pulling Algorithm

> **algorithm** Pulling;
> **begin**
>     \(d(s) \leftarrow 0, \mbox{pred}(s) \leftarrow 0\);
>     \(d(i) \leftarrow \infty\) for all \(i \in N - \{ s \}\);
>     **for** each node \(j \in N\) in topological ordering **do**
>         **for** all arc \((i, j), i \in N\) **do**
>             **if** \(d(j) > d(i) + c_{ij}\) **then**
>             **begin**
>                 \(d(j) \leftarrow d(i) + c_{ij}\);
>                 \(\mbox{pred}(i) \leftarrow j\);
>             **end**;
> **end**;


<a id="orgde7a2ee"></a>

## The Reaching Algorithm

> **algorithm** Reaching;
> **begin**
>     \(d(s) \leftarrow 0, \mbox{pred}(s) \leftarrow 0\);
>     \(d(i) \leftarrow \infty\) for all \(i \in N - \{ s \}\);
>     **for** each node \(i \in N\) in topological ordering **do**
>         **for** all arc \((i, j), j \in N\) **do**
>             **if** \(d(j) > d(i) + c_{ij}\) **then**
>             **begin**
>                 \(d(j) \leftarrow d(i) + c_{ij}\);
>                 \(\mbox{pred}(i) \leftarrow j\);
>             **end**;
> **end**;


<a id="org1781e69"></a>

# Single Source Shortest Path Problems in Networks With No Negative Arc Length


<a id="org6251cd3"></a>

## Dijkstra Algorithm

> **algorithm** Dijkstra's;
> **begin**
>     \(S \leftarrow \emptyset, \bar S \leftarrow N\);
>     \(d(s) \leftarrow 0, \mbox{pred}(s) \leftarrow 0\);
>     **d(s) &larr; &infin;** for all \(i \in N - \{ s \}\);
>     **while** \(|S| < n\) **do**
>     **begin**
>         let \(i \in \bar S\) be some node such that \(d(i) = \mbox{min} \{ d(j) : j \in \bar S \}\);
>         \(S \leftarrow S \cup \{ i \}\);
>         \(\bar S \leftarrow \bar S - \{ i \}\);
>         **for** each \((i, j) \in A(i)\) **do**
>             **if** \(d(j) > d(i) > c_{ij}\) **then**
>             **begin**
>                 \(d(j) \leftarrow d(i) + c_{ij}\);
>                 \(\mbox{pred}(j) \leftarrow i\);
>             **end**;
>     **end**;
> **end**;

-   The node selecting operations cost \(O(n^2)\).
-   The distance updating operations cost \(O(m)\).
-   Since the upper bound of \(m\) is \(O(n^2)\), Dijkstra's algorithm runs in \(O(n^2)\).


<a id="org5e2f789"></a>

## TODO Optimization: Bidiretional Search


<a id="orga6d726d"></a>

## TODO Optimization: Heap


<a id="org8da8d5f"></a>

## TODO Optimization: Dial's Implementation


<a id="orgba4f38b"></a>

# Single Source Shortest Path Problems in Networks With Arbitrary Arc Lengths


<a id="orgc8e16e9"></a>

## TODO Optimality Condition


<a id="orgdb3d8d0"></a>

## TODO Generic Label-Correcting Algorithm


<a id="orgbcc687b"></a>

## TODO Modified Label-Correcting Algorithm


<a id="orgcac6707"></a>

## TODO Detecting Negative Cycles


<a id="orgc25797e"></a>

# All-Pair Shortest Path Problems in Networks With Arbitrary Arc Lengths


<a id="orgd22f040"></a>

## TODO Repeated Shortest Path Algorithm


<a id="org02cae3a"></a>

## TODO Generic Label-Correcting Algorithm


<a id="org55bc521"></a>

## TODO Floyd-Warshall Algorithm


<a id="org29c80f6"></a>

## TODO Detecting Negative Cycles

