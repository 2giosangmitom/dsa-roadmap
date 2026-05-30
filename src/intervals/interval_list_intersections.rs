struct Solution;

impl Solution {
    pub fn interval_intersection(
        first_list: Vec<Vec<i32>>,
        second_list: Vec<Vec<i32>>,
    ) -> Vec<Vec<i32>> {
        let mut res = Vec::new();
        let (mut i, mut j) = (0, 0);

        while i < first_list.len() && j < second_list.len() {
            let start = first_list[i][0].max(second_list[j][0]);
            let end = first_list[i][1].min(second_list[j][1]);

            if start <= end {
                res.push(vec![start, end]);
            }

            if first_list[i][1] < second_list[j][1] {
                i += 1;
            } else {
                j += 1;
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
    #[case(
        vec![vec![0, 2], vec![5, 10], vec![13, 23], vec![24, 25]],
        vec![vec![1, 5], vec![8, 12], vec![15, 24], vec![25, 26]],
        vec![vec![1, 2], vec![5, 5], vec![8, 10], vec![15, 23], vec![24, 24], vec![25, 25]]
    )]
    #[case(vec![vec![1, 3], vec![5, 9]], vec![], vec![])]
    fn test_interval_intersection(
        #[case] first: Vec<Vec<i32>>,
        #[case] second: Vec<Vec<i32>>,
        #[case] expected: Vec<Vec<i32>>,
    ) {
        assert_eq!(Solution::interval_intersection(first, second), expected);
    }
}
