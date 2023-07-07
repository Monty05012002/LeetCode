# Good Stones
## Medium
<div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Geek is in a geekland which have a river and some stones in it. Initially geek can step on any stone. Each stone has a number on it representing the value of exact step geek can move. If the number is +ve then geeks can move right and if the number is -ve then geeks can move left. Bad Stones are defined as the stones in which if geeks steps, will reach a never ending loop whereas good stones are the stones which are safe from never ending loops. Return the number of <strong>good stones</strong> in river.</span></p>
<p><span style="font-size: 18px;">Example 1:</span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> [2, 3, -1, 2, -2, 4, 1]</span>
<span style="font-size: 18px;"><strong>Output: </strong>3
<strong>Explanation: </strong>Index 3, 5 and 6 are safe only. As index 1, 4, 2 forms a cycle and from index 0 you can go to index 2 which is part of cycle.
</span><img style="height: 169px; width: 500px;" src="https://media.geeksforgeeks.org/img-practice/good_stones_png-1663740812.png" alt="">
</pre>
<p><span style="font-size: 18px;">Example 2:</span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> [1, 0, -3, 0, -5, 0]</span>
<span style="font-size: 18px;"><strong>Output: 2</strong>
<strong>Explanation: </strong>Index 2 and 4 are safe only. As index 0, 1, 3, 5 form cycle.
</span><img src="https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/713990/Web/Other/3500a2e3-a9d5-4957-a6c7-43ed30313c68_1685087994.jpg">

</pre>
<p><span style="font-size: 18px;"><strong>Your Task:</strong></span><br><span style="font-size: 18px;">You don't need to read input or print anything. Your task is to complete the function badStones() which takes integer <strong>n</strong> and&nbsp;an&nbsp;array <strong>arr </strong>as input, and return an interger value as the number of good stones. Here n is the lenght of arr.</span></p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity</strong>&nbsp;: O(N), N is the number of stones<br><strong>Expected Auxiliary Space</strong>&nbsp;: O(N),&nbsp;N is the number of stones</span></p>
<p><br><span style="font-size: 18px;"><strong>Constraints:</strong><br>&nbsp;&nbsp;&nbsp;1 &lt;= n&nbsp;&lt;&nbsp;10^5 (where n is the length of the array)<br>&nbsp; -1000 &lt;= arr[i] &lt; 1000</span></p></div>