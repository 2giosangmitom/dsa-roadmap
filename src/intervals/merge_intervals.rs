struct Solution;

impl Solution {
    pub fn merge(intervals: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        if intervals.is_empty() {
            return vec![];
        }

        let mut intervals = intervals;
        intervals.sort_by(|a, b| a[0].cmp(&b[0]));

        let mut res = vec![intervals[0].clone()];
        for interval in intervals.into_iter().skip(1) {
            let last = res.last_mut().unwrap();
            if interval[0] <= last[1] {
                last[1] = last[1].max(interval[1]);
            } else {
                res.push(interval);
            }
        }
        res
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![vec![1, 3], vec![2, 6], vec![8, 10], vec![15, 18]], vec![vec![1, 6], vec![8, 10], vec![15, 18]])]
    #[case(vec![vec![1, 4], vec![4, 5]], vec![vec![1, 5]])]
    fn test_merge(#[case] intervals: Vec<Vec<i32>>, #[case] expected: Vec<Vec<i32>>) {
        assert_eq!(Solution::merge(intervals), expected);
    }
}
