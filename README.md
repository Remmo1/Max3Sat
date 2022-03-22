# Max3Sat
Project made on laboratory of Effective Programming Techniques.
[See how it works!](https://www.youtube.com/watch?v=EkPx4DKFHqk)

## Explanation
The problem that I solved here is max3sat. I used here c++ in writing this code. The problem is as follows: We have a clauses that contain three numbers each for example (1, 7, -1), (3, -2, 12) etc. A number has to be true or false, let's say for our example:
* 1 is true so -1 is false
* 7 is false
* 3 is true
* -2 is false so 2 is true
* 12 is false
The clause is satisfied when it has at least one true. In our example we have 
(true, false, true), (true, false, false)
so we have 2 satisfied clauses. Our task is to find the best solution for more complicated and bigger dataset.
