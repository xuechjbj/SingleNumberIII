#SingleNumberIII

Provide 2 soultions:

1) utilize the std:map(implemented by red black tree), insert the integer
if it wasn't found in map; otherwise delete it. finially the left integers
in the map are anwser;

2) first sort the input integers. then scan the array to get the single number;

According LeetCode test, the method 2 is faster than method 1.

