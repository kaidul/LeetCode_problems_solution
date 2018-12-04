import java.util.AbstractMap;

class Solution {
    public String reorganizeString(String S) {
        Map<Character, Integer> freqMap = new HashMap<>();
        for(char ch : S.toCharArray()) {
            int freq = freqMap.getOrDefault(ch, 0) + 1;
            if(freq > (S.length() + 1) / 2) {
                return "";
            }
            freqMap.put(ch, freq);
        }
        PriorityQueue<Map.Entry<Character, Integer>> pQ = new PriorityQueue(
            (Comparator<Map.Entry<Character, Integer>>) (lhs, rhs) -> rhs.getValue().compareTo(lhs.getValue())
        );
        for(Map.Entry<Character, Integer> entry : freqMap.entrySet()) {
            pQ.add(entry);
        }
        
        StringBuilder resultBuilder = new StringBuilder();
        while(!pQ.isEmpty()) {
            Map.Entry<Character, Integer> top = pQ.poll();
            if(resultBuilder.length() == 0 || resultBuilder.charAt(resultBuilder.length() - 1) != top.getKey()) {
                resultBuilder.append(top.getKey());
                if(top.getValue() - 1 > 0) {
                    pQ.add(new AbstractMap.SimpleEntry(top.getKey(), top.getValue() - 1));
                }
            } else {
                Map.Entry<Character, Integer> secondTop = pQ.poll();
                resultBuilder.append(secondTop.getKey());
                if(secondTop.getValue() - 1 > 0) {
                    pQ.add(new AbstractMap.SimpleEntry(secondTop.getKey(), secondTop.getValue() - 1));
                }
                pQ.add(top);
            }
        }
        
        return resultBuilder.toString();
    }
}