struct Solution;

impl Solution {
    pub fn num_islands(grid: Vec<Vec<char>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        let mut grid = grid;
        let mut count = 0;
        for i in 0..m {
            for j in 0..n {
                if grid[i][j] == '1' {
                    count += 1;
                    Self::dfs(&mut grid, i, j, m, n);
                }
            }
        }
        count
    }

    fn dfs(grid: &mut Vec<Vec<char>>, i: usize, j: usize, m: usize, n: usize) {
        if i >= m || j >= n || grid[i][j] != '1' {
            return;
        }
        grid[i][j] = '0';
        Self::dfs(grid, i.wrapping_sub(1), j, m, n);
        Self::dfs(grid, i + 1, j, m, n);
        Self::dfs(grid, i, j.wrapping_sub(1), m, n);
        Self::dfs(grid, i, j + 1, m, n);
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(
        vec![
            vec!['1', '1', '1', '1', '0'],
            vec!['1', '1', '0', '1', '0'],
            vec!['1', '1', '0', '0', '0'],
            vec!['0', '0', '0', '0', '0'],
        ],
        1
    )]
    #[case(
        vec![
            vec!['1', '1', '0', '0', '0'],
            vec!['1', '1', '0', '0', '0'],
            vec!['0', '0', '1', '0', '0'],
            vec!['0', '0', '0', '1', '1'],
        ],
        3
    )]
    fn test_num_islands(#[case] grid: Vec<Vec<char>>, #[case] expected: i32) {
        assert_eq!(Solution::num_islands(grid), expected);
    }
}
