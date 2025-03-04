class Solution {
    public boolean isNumber(String s) {
        int n = s.length();
        boolean isdot = false;
        boolean ise = false;
        boolean nums = false;
        for (int i = 0; i < n; i++) {
            if ('0' <= s.charAt(i) && s.charAt(i) <= '9') {
                nums = true;
            } else if (s.charAt(i) == '+' || s.charAt(i) == '-') {
                if (i > 0 && (s.charAt(i-1) != 'e' && s.charAt(i-1) != 'E')) {
                    return false;
                }
            } else if (s.charAt(i) == 'e' || s.charAt(i) == 'E') {
                if (ise || !nums) {
                    return false;
                }
                ise = true;
                nums = false;
            } else if (s.charAt(i) == '.') {
                if (isdot || ise) {
                    return false;
                }
                isdot = true;
            } else {
                return false;
            }
        }
        return nums;
    }
}