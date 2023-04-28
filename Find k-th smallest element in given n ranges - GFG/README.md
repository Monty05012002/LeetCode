# Find k-th smallest element in given n ranges
## Medium
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given an&nbsp;integer <strong>N</strong>&nbsp;consisting of&nbsp;ranges of the form [p, q]&nbsp;which denotes the integer in the range [p, p + 1, p + 2,...q].&nbsp; Given another integer&nbsp;<strong>Q&nbsp;</strong>denoting&nbsp;the number of queries.&nbsp;The task is to return&nbsp;the <strong>k<sup>th</sup></strong>&nbsp;smallest element for each query (assume k&gt;1) after combining all the ranges.<br>
In case the <strong>k<sup>th</sup></strong>&nbsp;smallest element doesn't exist&nbsp;-1.&nbsp;</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
range[] = {{1, 4}, {6, 8}}
queries[] = {2, 6, 10}
<strong>Output: </strong>2 7 -1
<strong>Explanation:</strong> After combining the given ranges, 
the numbers become 1 2 3 4 6 7 8. As here 2nd 
element is 2, so we print 2. As 6th element is 
7, so we print 7 and as 10th element doesn't exist, so we
print -1.</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
range[] = {{2, 6}, {5, 7}} 
queries[] = {5, 8}
<strong>Output: </strong>6 -1
</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Your task is to complete the function <strong>kthSmallestNum</strong><strong>()</strong>&nbsp;which takes a N * 2 array denoting the ranges and an array denoting the queries.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(NlogN)<br>
<strong>Expected Auxiliary Space:</strong> O(N)</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= N &lt;= 10<sup>3</sup></span><br>
<span style="font-size:18px">1 &lt;= range[i][0] &lt;= range[i][1] &lt;= 10<sup>3</sup><br>
1 &lt;= Q &lt;= 500<br>
1 &lt;= queries[i] &lt;= 500<br>
-10<sup>3&nbsp;</sup>&lt;= point[i] &lt;= 10<sup>3</sup></span></p>
</div>