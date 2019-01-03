
# Table of Contents

1.  [Single Source Shortest Path Problems in Directed Acyclic Networks](#org56a4edc)
    1.  [The Pulling Algorithm](#orgd8e17c2)
    2.  [The Reaching Algorithm](#orgf5fbb6d)
2.  [Single Source Shortest Path Problems in Networks With No Negative Arc Length](#org91b97b4)
    1.  [Dijkstra Algorithm](#orgdea0ae9)
    2.  [Optimization: Bidiretional Search](#orgf65fef4)
    3.  [Optimization: Heap](#orgcfd70c3)
    4.  [Optimization: Dial's Implementation](#orge330496)
3.  [Single Source Shortest Path Problems in Networks With Arbitrary Arc Lengths](#org483defe)
    1.  [Optimality Condition](#org36bbb76)
    2.  [Generic Label-Correcting Algorithm](#orgc4fe623)
    3.  [Modified Label-Correcting Algorithm](#org460dab9)
    4.  [Detecting Negative Cycles](#orgee7545e)
4.  [All-Pair Shortest Path Problems in Networks With Arbitrary Arc Lengths](#org9291c4d)
    1.  [Repeated Shortest Path Algorithm](#org5a1a109)
    2.  [Generic Label-Correcting Algorithm](#org139678a)
    3.  [Floyd-Warshall Algorithm](#org4482d57)
    4.  [Detecting Negative Cycles](#orge63ac08)



<a id="org56a4edc"></a>

# Single Source Shortest Path Problems in Directed Acyclic Networks

-   A topological ordering of nodes is available for a directed acyclic network such that for any \((i, j) \in A\), \(i\) appears before \(j\) in the ordering.
-   Two similar algorithms based on this topological ordering can be established.
-   The complexity is \(O(m)\) for both algorithms, since each arc is examined exactly once in each execution.
-   The reaching algorithm is prefered since we usually maintain the adjacent-list \(A(i)\) for node \(i \in N\).


<a id="orgd8e17c2"></a>

## The Pulling Algorithm

<p class="verse">
**algorithm** Pulling;<br />
**begin**<br />
&#xa0;&#xa0;&#xa0;&#xa0;\(d(s) \leftarrow 0, \mbox{pred}(s) \leftarrow 0\);<br />
&#xa0;&#xa0;&#xa0;&#xa0;\(d(i) \leftarrow \infty\) for all \(i \in N - \{ s \}\);<br />
&#xa0;&#xa0;&#xa0;&#xa0;**for** each node \(j \in N\) in topological ordering **do**<br />
&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;**for** all arc \((i, j), i \in N\) **do**<br />
&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;**if** \(d(j) > d(i) + c_{ij}\) **then**<br />
&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;**begin**<br />
&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;\(d(j) \leftarrow d(i) + c_{ij}\);<br />
&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;\(\mbox{pred}(i) \leftarrow j\);<br />
&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;**end**;<br />
**end**;<br />
</p>


<a id="orgf5fbb6d"></a>

## The Reaching Algorithm

<p class="verse">
**algorithm** Reaching;<br />
**begin**<br />
&#xa0;&#xa0;&#xa0;&#xa0;\(d(s) \leftarrow 0, \mbox{pred}(s) \leftarrow 0\);<br />
&#xa0;&#xa0;&#xa0;&#xa0;\(d(i) \leftarrow \infty\) for all \(i \in N - \{ s \}\);<br />
&#xa0;&#xa0;&#xa0;&#xa0;**for** each node \(i \in N\) in topological ordering **do**<br />
&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;**for** all arc \((i, j), j \in N\) **do**<br />
&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;**if** \(d(j) > d(i) + c_{ij}\) **then**<br />
&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;**begin**<br />
&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;\(d(j) \leftarrow d(i) + c_{ij}\);<br />
&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;\(\mbox{pred}(i) \leftarrow j\);<br />
&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;**end**;<br />
**end**;<br />
</p>


<a id="org91b97b4"></a>

# Single Source Shortest Path Problems in Networks With No Negative Arc Length


<a id="orgdea0ae9"></a>

## Dijkstra Algorithm

<p class="verse">
**algorithm** Dijkstra's;<br />
**begin**<br />
&#xa0;&#xa0;&#xa0;&#xa0;\(S \leftarrow \emptyset, \bar S \leftarrow N\);<br />
&#xa0;&#xa0;&#xa0;&#xa0;\(d(s) \leftarrow 0, \mbox{pred}(s) \leftarrow 0\);<br />
&#xa0;&#xa0;&#xa0;&#xa0;**d(s) &larr; &infin;** for all \(i \in N - \{ s \}\);<br />
&#xa0;&#xa0;&#xa0;&#xa0;**while** \(|S| < n\) **do**<br />
&#xa0;&#xa0;&#xa0;&#xa0;**begin**<br />
&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;let \(i \in \bar S\) be some node such that \(d(i) = \mbox{min} \{ d(j) : j \in \bar S \}\);<br />
&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;\(S \leftarrow S \cup \{ i \}\);<br />
&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;\(\bar S \leftarrow \bar S - \{ i \}\);<br />
&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;**for** each \((i, j) \in A(i)\) **do**<br />
&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;**if** \(d(j) > d(i) > c_{ij}\) **then**<br />
&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;**begin**<br />
&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;\(d(j) \leftarrow d(i) + c_{ij}\);<br />
&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;\(\mbox{pred}(j) \leftarrow i\);<br />
&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#xa0;**end**;<br />
&#xa0;&#xa0;&#xa0;&#xa0;**end**;<br />
**end**;<br />
</p>

-   The node selecting operations cost \(O(n^2)\).
-   The distance updating operations cost \(O(m)\).
-   Since the upper bound of \(m\) is \(O(n^2)\), Dijkstra's algorithm runs in \(O(n^2)\).


<a id="orgf65fef4"></a>

## TODO Optimization: Bidiretional Search


<a id="orgcfd70c3"></a>

## TODO Optimization: Heap


<a id="orge330496"></a>

## TODO Optimization: Dial's Implementation


<a id="org483defe"></a>

# Single Source Shortest Path Problems in Networks With Arbitrary Arc Lengths


<a id="org36bbb76"></a>

## TODO Optimality Condition


<a id="orgc4fe623"></a>

## TODO Generic Label-Correcting Algorithm


<a id="org460dab9"></a>

## TODO Modified Label-Correcting Algorithm


<a id="orgee7545e"></a>

## TODO Detecting Negative Cycles


<a id="org9291c4d"></a>

# All-Pair Shortest Path Problems in Networks With Arbitrary Arc Lengths


<a id="org5a1a109"></a>

## TODO Repeated Shortest Path Algorithm


<a id="org139678a"></a>

## TODO Generic Label-Correcting Algorithm


<a id="org4482d57"></a>

## TODO Floyd-Warshall Algorithm


<a id="orge63ac08"></a>

## TODO Detecting Negative Cycles

