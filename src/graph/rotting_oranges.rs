struct Solution;

impl Solution {
    pub fn oranges_rotting(grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        let mut grid = grid;
        let mut queue = std::collections::VecDeque::new();
        let mut fresh = 0;
        for (i, row) in grid.iter().enumerate().take(m) {
            for (j, &cell) in row.iter().enumerate().take(n) {
                if cell == 2 {
                    queue.push_back((i, j, 0));
                } else if cell == 1 {
                    fresh += 1;
                }
            }
        }
        let mut minutes = 0;
        let dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)];
        while let Some((r, c, t)) = queue.pop_front() {
            minutes = t;
            for (dr, dc) in &dirs {
                let nr = r as i32 + dr;
                let nc = c as i32 + dc;
                if nr >= 0 && nr < m as i32 && nc >= 0 && nc < n as i32 {
                    let nr = nr as usize;
                    let nc = nc as usize;
                    if grid[nr][nc] == 1 {
                        grid[nr][nc] = 2;
                        fresh -= 1;
                        queue.push_back((nr, nc, t + 1));
                    }
                }
            }
        }
        if fresh > 0 { -1 } else { minutes }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![vec![2, 1, 1], vec![1, 1, 0], vec![0, 1, 1]], 4)]
    #[case(vec![vec![2, 1, 1], vec![0, 1, 1], vec![1, 0, 1]], -1)]
    #[case(vec![vec![0, 2]], 0)]
    fn test_oranges_rotting(#[case] grid: Vec<Vec<i32>>, #[case] expected: i32) {
        assert_eq!(Solution::oranges_rotting(grid), expected);
    }
}
