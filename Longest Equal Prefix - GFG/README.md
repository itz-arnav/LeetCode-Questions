# Longest Equal Prefix
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given two positive integers x and y, and an array arr[] of positive integers. We need to find the longest prefix index which contains an equal number of x and y. Print the maximum index of largest prefix if exist otherwise print -1.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N=11
X=7  Y=42
arr[] = [ 7, 42, 5, 6, 42, 8, 7, 5, 3, 6, 7 ]
<strong>Output:</strong> 9
<strong>Explanation</strong>: The longest prefix with same 
number of occurrences of 7 and 42 is:
7, 42, 5, 6, 42, 8, 7, 5, 3, 6 </span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N=3
X=1 Y=2 
arr[] = [ 1,2,2 ]
<strong>Output:</strong> 1
</span></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:</strong><br>
Since this is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function <strong>findIndex</strong>() that takes <strong>array arr, integer X,&nbsp;integer Y, and integer N</strong>&nbsp;as parameters and return the desired result.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(N).<br>
<strong>Expected Auxiliary Space:</strong> O(1).</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
2 ≤ N ≤ 105<br>
X != Y</span></p>
</div>