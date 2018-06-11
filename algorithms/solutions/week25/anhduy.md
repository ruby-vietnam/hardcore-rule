```500
def find_words(words)
    words.select{ |word| word =~ /^[qwertyuiop]+$|^[asdfghjkl]+$|^[zxcvbnm]+$/i}
end
```

