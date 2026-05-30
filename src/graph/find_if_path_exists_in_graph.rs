struct Solution;

impl Solution {
    pub fn valid_path(n: i32, edges: Vec<Vec<i32>>, source: i32, destination: i32) -> bool {
        if source == destination {
            return true;
        }
        let n = n as usize;
        let mut adj = vec![vec![]; n];
        for edge in &edges {
            let u = edge[0] as usize;
            let v = edge[1] as usize;
            adj[u].push(v);
            adj[v].push(u);
        }
        let mut visited = vec![false; n];
        let mut stack = vec![source as usize];
        while let Some(u) = stack.pop() {
            if visited[u] {
                continue;
            }
            visited[u] = true;
            for &v in &adj[u] {
                if v == destination as usize {
                    return true;
                }
                if !visited[v] {
                    stack.push(v);
                }
            }
        }
        false
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(3, vec![vec![0, 1], vec![1, 2], vec![2, 0]], 0, 2, true)]
    #[case(6, vec![vec![0, 1], vec![0, 2], vec![3, 5], vec![5, 4], vec![4, 3]], 0, 5, false)]
    fn test_valid_path(
        #[case] n: i32,
        #[case] edges: Vec<Vec<i32>>,
        #[case] source: i32,
        #[case] destination: i32,
        #[case] expected: bool,
    ) {
        assert_eq!(
            Solution::valid_path(n, edges, source, destination),
            expected
        );
    }
}
