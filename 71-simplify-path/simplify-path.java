class Solution {
    public String simplifyPath(String path) {
        Deque<String> stack = new ArrayDeque<>();
        String[] subDir = path.split("/+");

        for(String dir : subDir) {
            if (dir.isEmpty() || dir.equals(".")) {
                continue;
            } else if (dir.equals("..")){
                if (!stack.isEmpty()) {
                    stack.pop();
                }
            } else {
                stack.push(dir);
            }
        }

        StringBuilder ans = new StringBuilder();
        while(!stack.isEmpty()) {
            ans.insert(0, "/" + stack.pop());
        }

        return ans.length() == 0 ? "/" : ans.toString();
    }
}