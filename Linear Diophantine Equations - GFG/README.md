# Linear Diophantine Equations
## Easy
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">A Diophantine equation is a polynomial equation, usually in two or more unknowns, such that only the integral solutions are required. An Integral solution is a solution such that all the unknown variables take only integer values.</span></p>

<p><span style="font-size:18px">Given three integers A, B, C representing a linear equation of the form: Ax + By = C. Determine if the equation has a solution such that x and y are both integral values.</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: </strong>
A = 3
B = 6
C = 9 
<strong>Output: </strong>
1 
<strong>Explanation:</strong>
It is possible to
write A, B, C in the
for 3 + 6 = 9</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: </strong>
A = 4
B = 2
C = 3
<strong>Output: </strong>
0 
<strong>Explanation:</strong>
It is not possible to
represent A, B, C in 
Diophantine equation form.</span>
</pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Your task is to complete the function <strong>isPossible()</strong>&nbsp;which takes&nbsp;three integer <strong>values</strong>&nbsp;A, B, C as input parameters&nbsp;and returns 1 if the solution for x and y exist otherwise return 0.</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(log N)<br>
<strong>Expected Space Complexity:</strong> O(1)</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= A,B,C &lt;= 10<sup>5</sup></span></p>
 <p></p>
            </div>