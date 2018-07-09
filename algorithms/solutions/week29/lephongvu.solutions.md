# Bai 1
```

class Solution {
public:
    string countAndSay(int n)
    {
        string curr_str;

        // The initial case, when n = 1
        curr_str += '1';

        // The iterative case, when n > 1
        for (int i = 0; i < n - 1; i++)
        {
            string buffer;

            // Handle the current string
            int index = 0;
            for (int index = 0; index < curr_str.size(); ++index)
            {
                // Count the occurance of each digit
                int cnt = 1; // At least one occurance

                while (index + 1 < curr_str.size() and curr_str[index + 1] == curr_str[index]) 
                {
                    index++;
                    cnt++;
                }

                buffer.push_back(cnt + '0');
                buffer.push_back(curr_str[index]);
            }

            // Update the current string
            curr_str = buffer;
        }

        return curr_str;
    }
};
```
