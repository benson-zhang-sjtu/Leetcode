## 2016/10/15 Update 2 ##
After learning from the discussion board, I test a recursion method that runs 23ms compared to 750ms brute force method. 
The idead is to divide string s into substring by delimeter c where the number of c is less than k.
I also copy a split function of s from [Evan Teran](http://stackoverflow.com/questions/236129/split-a-string-in-c)

## 2016/10/15 Update 1 ##
简单改进了暴搜程序，对于字符串s中出现最多和最少的字母的次数分别记为min_num, max_num 
如果k > max_num, 直接返回0
如果k <= min_num 直接返回s的长度
再按直接的程序暴力搜索，从长度s.size()-1的字符串依次往下搜索，竟然就过了....

I optimize the brute force method. Suppose min_num is the number of letter that repeated minimal times.max_num is the number of letter that repeated maximal times.
if k > max_num, return 0
if k <= min_num, return s.size()
It's done... We brute force from the substring of length s.size()-1 down to 1. If found, then return the result.

## 2016/10/15 ##
I use brute-force method to solve this problem. It's easy to see that it'll exceed time limit.
Failed test case is : "aaa....aaaa" of length 1000000 and k=1000000 
