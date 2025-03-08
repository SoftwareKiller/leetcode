func simplifyPath(path string) string {
    dirs := make([]string, 0)
    subDir := strings.Split(path, "/")

    for _, dir := range subDir {
        if dir == "" || dir == "." {
            continue
        } else if dir == ".." {
            if len(dirs) > 0 {
                dirs = dirs[:len(dirs)-1]
            }
        } else {
            dirs = append(dirs, dir)
        }
    }

    ans := ""
    for _, d := range dirs {
        ans += "/" + d
    }

    if len(ans) == 0 {
        return "/"
    }
    return ans
}