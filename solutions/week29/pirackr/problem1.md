```python
class Solution(object):
    def countAndSay(self, n):
        if not n:
            return ''
        if n==1:
            return '1'
        pre='1'
        cur=''
        for i in xrange(1,n):
            curC=pre[0]
            cnt=0
            tmp=''
            for j in xrange(len(pre)):
                if pre[j]==curC:
                    cnt+=1
                else:
                    tmp+=str(cnt)+curC
                    curC=pre[j]
                    cnt=1
            tmp+=str(cnt)+curC
            pre=tmp
        return pre
```
