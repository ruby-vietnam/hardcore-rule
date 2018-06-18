# #1
```c#
public char FindTheDifference(string s, string t)
    {
        char[] ct = t.ToCharArray();
        char[] cs = s.ToCharArray();
        Array.Sort(ct);
        Array.Sort(cs);

        for (var i = 0; i < cs.Length; i++)
        {
            if (ct[i] != cs[i]) return ct[i];
        }

        return ct[ct.Length - 1];
    }
```