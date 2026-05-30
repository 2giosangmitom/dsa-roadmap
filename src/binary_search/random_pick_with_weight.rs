struct Solution {
    prefix: Vec<i32>,
    total: i32,
    state: u64,
}

impl Solution {
    pub fn new(w: Vec<i32>) -> Self {
        let mut prefix = Vec::with_capacity(w.len());
        let mut sum = 0;
        for weight in w {
            sum += weight;
            prefix.push(sum);
        }
        Solution {
            prefix,
            total: sum,
            state: 1,
        }
    }

    pub fn pick_index(&mut self) -> i32 {
        let rand = (self.next_u32() % self.total as u32) as i32 + 1;
        let idx = self.prefix.binary_search(&rand).unwrap_or_else(|i| i);
        idx as i32
    }

    fn next_u32(&mut self) -> u32 {
        self.state = self.state.wrapping_mul(6364136223846793005).wrapping_add(1);
        (self.state >> 33) as u32
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    fn test_pick_index_deterministic() {
        let mut solution = Solution::new(vec![1, 3]);
        let picks: Vec<i32> = (0..10).map(|_| solution.pick_index()).collect();
        assert!(picks.iter().all(|&i| i == 0 || i == 1));
    }
}
