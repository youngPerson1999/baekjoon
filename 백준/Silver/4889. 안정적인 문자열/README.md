# [Silver I] 안정적인 문자열 - 4889 

[문제 링크](https://www.acmicpc.net/problem/4889) 

### 성능 요약

메모리: 2024 KB, 시간: 4 ms

### 분류

자료 구조, 그리디 알고리즘, 스택, 문자열

### 제출 일자

2025년 3월 18일 21:17:37

### 문제 설명

<p>I’m out of stories. For years I’ve been writing stories, some rather silly, just to make simple problems look diﬃcult and complex problems look easy. But, alas, not for this one.</p>

<p>You’re given a non empty string made in its entirety from opening and closing braces. Your task is to ﬁnd the minimum number of “operations” needed to make the string stable. The deﬁnition for being stable is as follows:</p>

<ol>
	<li>An empty string is stable.</li>
	<li>If S is stable, then {S} is also stable.</li>
	<li>If S and T are both stable, then ST (the concatenation of the two) is also stable.</li>
</ol>

<p>All of these strings are stable: {}, {}{}, and {{}{}}; But none of these: }{, {{}{, nor {}{. The only operation allowed on the string is to replace an opening brace with a closing brace, or visa-versa.</p>

### 입력 

 <p>Your program will be tested on one or more data sets. Each data set is described on a single line. The line is a non-empty string of opening and closing braces and nothing else. No string has more than 2000 braces. All sequences are of even length.</p>

<p>The last line of the input is made of one or more ’-’ (minus signs.)</p>

### 출력 

 <p>For each test case, print the following line:</p>

<pre>k. N</pre>

<p>Where k is the test case number (starting at one,) and N is the minimum number of operations needed to convert the given string into a balanced one.</p>

