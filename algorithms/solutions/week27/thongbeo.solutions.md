#Problem 1
``` Java 
class Solution {
    public List<String> subdomainVisits(String[] cpdomains) {
        HashMap<String,Integer> hm = new HashMap<>();
        for(String cpdomain : cpdomains){
            int num = Integer.valueOf(cpdomain.substring(0, cpdomain.indexOf(' ')));
            String domain = cpdomain.substring(cpdomain.indexOf(' ') + 1);
            hm.put(domain, num + hm.getOrDefault(domain, 0));
            
            int idx = domain.indexOf(".");
            while (idx != -1){
                String s = domain.substring(idx +1);
                 hm.put(s, num + hm.getOrDefault(s, 0));
                idx = domain.indexOf(".", idx +1);
            }
         }
        
        List<String> result = new ArrayList<>();
        for (Map.Entry<String, Integer> entry : hm.entrySet()){
            StringBuilder sb = new StringBuilder();
            sb.append(String.valueOf(entry.getValue()));
            sb.append(" ");
            sb.append(entry.getKey());
            result.add(sb.toString());
        }
        
        return result;
    }
}
```
