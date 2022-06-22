# Maximum prefix sum for a given range
## Easy 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px"><span style="font-family:arial,helvetica,sans-serif">Given an array of <strong>N</strong> integers and <strong>Q</strong> queries, each query having a range from index&nbsp;<strong>L</strong> to <strong>R</strong>. Find the maximum prefix-sum for the range <strong>L</strong> to <strong>R</strong>.<br>
<strong>Note: </strong>Assume 0 based indexing.</span></span></p>

<p><span style="font-size:18px"><span style="font-family:arial,helvetica,sans-serif"><strong>Example 1:</strong></span></span></p>

<pre><span style="font-size:18px"><span style="font-family:arial,helvetica,sans-serif"><strong>Input:</strong> 
a[ ] = {-1, 2, 3, -5} 
Q = 2
L<sub>1</sub> = 0, R<sub>1</sub> = 3
L<sub>2</sub> = 1, R<sub>2</sub> = 3
<strong>Output:</strong>
4 5<strong>
Explanation:</strong>
The range (0, 3) in the 1st query is {-1, 2, 3, -5}, hence, 
the max prefix-sum will be -1 + 2 + 3 = 4. The range (1, 3) 
in the 2nd query is {2, 3, -5}, hence, the max prefix-sum 
will be 2 + 3 = 5.</span></span></pre>

<p><span style="font-size:18px"><span style="font-family:arial,helvetica,sans-serif"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>maxPrefixes()</strong>&nbsp;which takes the array <strong>A[]</strong>, its size <strong>N</strong>, array<strong> L[] </strong>and<strong> R[] </strong>and&nbsp;their size <strong>Q </strong>as input parameters and returns a vector storing the required answer for every query.</span></span></p>

<p><span style="font-size:18px"><span style="font-family:arial,helvetica,sans-serif"><strong>Expected Time Complexity:</strong> O(N*Q)<br>
<strong>Expected Auxiliary Space:</strong> O(1)</span></span></p>

<p><span style="font-size:18px"><span style="font-family:arial,helvetica,sans-serif"><strong>Constraints: </strong><br>
1 ≤ N, A[i] ≤&nbsp;10<sup>4</sup><br>
1 ≤&nbsp;Q ≤&nbsp;10<sup>4</sup><br>
0 ≤&nbsp;L[i] ≤&nbsp;R[i] &lt; N</span></span></p>
 <p></p>
            </div>