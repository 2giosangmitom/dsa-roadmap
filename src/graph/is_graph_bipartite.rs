struct Solution;

impl Solution {
    pub fn is_bipartite(graph: Vec<Vec<i32>>) -> bool {
        let n = graph.len();
        let mut color = vec![-1; n];
        for i in 0..n {
            if color[i] == -1 {
                color[i] = 0;
                let mut queue = std::collections::VecDeque::new();
                queue.push_back(i);
                while let Some(u) = queue.pop_front() {
                    for &v in &graph[u] {
                        let v = v as usize;
                        if color[v] == -1 {
                            color[v] = color[u] ^ 1;
                            queue.push_back(v);
                        } else if color[v] == color[u] {
                            return false;
                        }
                    }
                }
            }
        }
        true
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![vec![1, 2, 3], vec![0, 2], vec![0, 1, 3], vec![0, 2]], false)]
    #[case(vec![vec![1, 3], vec![0, 2], vec![1, 3], vec![0, 2]], true)]
    fn test_is_bipartite(#[case] graph: Vec<Vec<i32>>, #[case] expected: bool) {
        assert_eq!(Solution::is_bipartite(graph), expected);
    }
}
