<h2><a href="https://www.geeksforgeeks.org/problems/box-stacking/1">Box Stacking</a></h2><h3>Difficulty Level : Difficulty: Hard</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">Given three arrays <strong>height[]</strong>, <strong>width[]</strong>, and <strong>length[]</strong> of size n, where height[i], width[i], and length[i] represent the dimensions of the ith box, find the maximum possible height of a stack formed using these boxes.</span></p>
<ul>
<li><span style="font-size: 18px;">A box can be rotated so that any of its dimensions becomes its height.</span></li>
<li><span style="font-size: 18px;">&nbsp;A box can be placed on top of another only if both dimensions of its base are strictly smaller than those of the box below.&nbsp;</span></li>
<li><span style="font-size: 18px;">Multiple instances of the same box can be used.</span></li>
</ul>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong style="font-size: 18px;">Input: </strong><span style="font-size: 18px;">height[] = [4, 1, 4, 10], width[] = [6, 2, 5, 12], length[] = [7, 3, 6, 32]
</span><strong style="font-size: 18px;">Output:</strong><span style="font-size: 18px;"> 60
</span><strong style="font-size: 18px;">Explanation: </strong><span style="font-size: 18px;">One possible arrangement of the boxes from bottom to top is shown below. Note that there can be multiple instances of a box type.<br><img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/933228/Web/Other/blobid0_1787736038.webp" width="302" height="318"> <br>Hence, the total height of this stack is 10 + 32 + 4 + 4 + 6 + 1 + 3 = 60. No other combination of boxes produces a height greater than this.</span></span>
</pre>
<pre><span style="font-size: 18px;"><strong>Input</strong>: height[] = [1, 4, 3], width[] = [2, 5, 4], length[] = [3, 6, 1]
<strong>Output:</strong> 15</span>
<span style="font-size: 18px;"><span style="font-size: 18px;"><strong>Explanation: </strong>One possible arrangement of the boxes from bottom to top is</span><span style="font-size: 18px;"> shown below:</span><span style="font-size: 18px;"> </span><strong style="font-size: 18px;"><br></strong><span style="font-size: 18px;"><img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/933228/Web/Other/blobid1_1787736128.webp" width="296" height="312"><br>Hence, the total height of this stack is 4 + 6 + 1 + 1 + 3 = 15 No other combination of boxes produces a height greater than this.</span></span>
</pre>
</div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>Codenation</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;