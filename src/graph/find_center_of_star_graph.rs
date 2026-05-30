struct Solution;

impl Solution {
    pub fn find_center(edges: Vec<Vec<i32>>) -> i32 {
        if edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1] {
            edges[0][0]
        } else {
            edges[0][1]
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![vec![1, 2], vec![2, 3], vec![4, 2]], 2)]
    #[case(vec![vec![1, 2], vec![5, 1], vec![1, 3], vec![1, 4]], 1)]
    fn test_find_center(#[case] edges: Vec<Vec<i32>>, #[case] expected: i32) {
        assert_eq!(Solution::find_center(edges), expected);
    }
}
