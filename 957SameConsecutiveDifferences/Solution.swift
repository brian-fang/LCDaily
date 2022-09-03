func numsSameConsecDiff(_ n: Int, _ k: Int) -> [Int] {
    var result = [Int]()
    
    func dfs(_ n: Int, _ num: Int) {
        if n == 0 {
            result.append(num)
            return
        }
        let digit = num % 10
        if digit+k < 10 {
            dfs(n - 1, num*10 + digit+k)
        }
        if k != 0 && digit-k >= 0 {
            dfs(n - 1, num*10 + digit-k)
        }
    }
    
    for i in 1...9 {
        dfs(n - 1, i)
    }
    
    return result
}

let argv = CommandLine.arguments

if let n = Int(argv[1]), let k = Int(argv[2]) {
    print(numsSameConsecDiff(n, k))
}
