class Solution {
    public String minWindow(String s, String t) {
        if (s.isEmpty() || t.isEmpty() || s.length() < t.length()) {
            return "";
        }

        HashMap<Character, Integer> window = new HashMap<>();
        HashMap<Character, Integer> need = new HashMap<>();
        int l = 0;
        int r = 0;
        int start = 0;
        int valid = 0;
        int minLen = Integer.MAX_VALUE;

        for(char c : t.toCharArray()) {
            need.put(c, need.getOrDefault(c, 0) + 1);
        }

        while(r < s.length()) {
            char c = s.charAt(r);
            r++;

            if (need.containsKey(c)) {
                window.put(c, window.getOrDefault(c, 0) + 1);

                if (window.get(c).equals(need.get(c))) {
                    valid++;
                }
            }

            while(need.size() == valid) {
                if (r - l < minLen) {
                    start = l;
                    minLen = r - l;
                }

                char d = s.charAt(l);
                l++;
                if (need.containsKey(d)) {
                    if (window.get(d).equals(need.get(d))) {
                        valid--;
                    }
                    window.put(d, window.get(d) - 1);
                }
            }
        }

        return minLen == Integer.MAX_VALUE ? "" : s.substring(start, start+minLen);
    }
}