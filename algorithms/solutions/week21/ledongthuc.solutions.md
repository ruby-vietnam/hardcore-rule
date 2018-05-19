*Problem1: https://leetcode.com/problems/valid-anagram/description/*

```go
func isAnagram(s string, t string) bool {
    if len(s) != len(t) {
        return false
    }
    
    counter := make([]int, 26)
    
    for i, _ := range s {
        counter[s[i] - 'a']++
        counter[t[i] - 'a']--
    }
    
    for i, _ := range counter {
        if counter[i] != 0 {
            return false
        }
    }
    
    return true
}
```

*Problem 2: https://leetcode.com/problems/encode-and-decode-tinyurl/description/*

```java
import java.security.*;
import java.util.Base64;

public class Codec {

    HashMap<Character,Character> runes;
    HashMap<String,String> urls;
    String host;
    
    Codec() {
        this.urls = new HashMap<String,String>(); 
        this.runes = new HashMap<Character,Character>(); 
        this.initRuneMap();
        this.host = "http://thuc.com.vn/";
        
    }
        
    // Encodes a URL to a shortened URL.
    public String encode(String longUrl)  {
        try {
            MessageDigest md = MessageDigest.getInstance("MD5");
            String shortPart = new String(Base64.getEncoder().encode(md.digest(longUrl.getBytes("UTF-8"))), "UTF-8");
            String magicWords = this.runize(shortPart);
            this.urls.put(magicWords, longUrl);
            return this.host + magicWords;
        } catch(Exception e){
            
        }
        
        return longUrl;
    }

    // Decodes a shortened URL to its original URL.
    public String decode(String shortUrl) {
        String shortPart = shortUrl.substring(this.host.length());
        if (!this.urls.containsKey(shortPart)) {
            return "";
        }
        
        return this.urls.get(shortPart);
    }
    
    private String runize(String origin) {
        String magicWords = "";
        for (char ch: origin.toCharArray()) {
            if (this.runes.containsKey(ch)) {
                magicWords += this.runes.get(ch);
            } else {
                magicWords += ch;
            }
        }
        return magicWords;
    }
    
    private void initRuneMap() {
        // abcdefghijklmnopqrstuvwxyz
        // ᚩᛒᚳᛞᛖᚠᚷᚻᛁᛄᛣᛚᛗᚾᚨᛈᛢᚱᛥᚢᚹᚹᚳᛋᚣᛉ
        this.runes.put('a', 'ᚩ');
        this.runes.put('b', 'ᛒ');
        this.runes.put('c', 'ᚳ');
        this.runes.put('d', 'ᛞ');
        this.runes.put('e', 'ᛖ');
        this.runes.put('f', 'ᚠ');
        this.runes.put('g', 'ᚷ');
        this.runes.put('h', 'ᚻ');
        this.runes.put('i', 'ᛁ');
        this.runes.put('j', 'ᛄ');
        this.runes.put('k', 'ᛣ');
        this.runes.put('l', 'ᛚ');
        this.runes.put('m', 'ᛗ');
        this.runes.put('n', 'ᚾ');
        this.runes.put('o', 'ᚨ');
        this.runes.put('p', 'ᛈ');
        this.runes.put('q', 'ᛢ');
        this.runes.put('r', 'ᚱ');
        this.runes.put('s', 'ᛥ');
        this.runes.put('t', 'ᚢ');
        this.runes.put('u', 'ᚹ');
        this.runes.put('v', 'ᚹ');
        this.runes.put('w', 'ᚳ');
        this.runes.put('x', 'ᛋ');
        this.runes.put('y', 'ᚣ');
        this.runes.put('z', 'ᛉ');
        this.runes.put('A', 'ᚩ');
        this.runes.put('B', 'ᛒ');
        this.runes.put('C', 'ᚳ');
        this.runes.put('D', 'ᛞ');
        this.runes.put('E', 'ᛖ');
        this.runes.put('F', 'ᚠ');
        this.runes.put('G', 'ᚷ');
        this.runes.put('H', 'ᚻ');
        this.runes.put('I', 'ᛁ');
        this.runes.put('J', 'ᛄ');
        this.runes.put('K', 'ᛣ');
        this.runes.put('L', 'ᛚ');
        this.runes.put('M', 'ᛗ');
        this.runes.put('N', 'ᚾ');
        this.runes.put('O', 'ᚨ');
        this.runes.put('P', 'ᛈ');
        this.runes.put('Q', 'ᛢ');
        this.runes.put('R', 'ᚱ');
        this.runes.put('S', 'ᛥ');
        this.runes.put('T', 'ᚢ');
        this.runes.put('U', 'ᚹ');
        this.runes.put('V', 'ᚹ');
        this.runes.put('W', 'ᚳ');
        this.runes.put('X', 'ᛋ');
        this.runes.put('Y', 'ᚣ');
        this.runes.put('Z', 'ᛉ');
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(url));
```
