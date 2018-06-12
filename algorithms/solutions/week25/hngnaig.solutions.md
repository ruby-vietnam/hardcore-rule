# Problem1

````python
class Solution:
    def findWords(self, words):
        klists = ['qwertyuiop','asdfghjkl','zxcvbnm']
        s = []
        for w in words:
            ws = []
            for p, kl in enumerate(klists):
                for ch in w.lower():
                    if ch in kl: ws.append(p)
            if len(set(ws)) == 1:
                s.append(w)
        return s
        ```
````
