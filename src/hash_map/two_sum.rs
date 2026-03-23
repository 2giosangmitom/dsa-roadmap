use std::collections::HashMap;

struct Solution;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map = HashMap::<i32, i32>::new();

        for (idx, num) in nums.iter().enumerate() {
            let remainder = target - num;
            let v = map.get(&remainder);

            if let Some(value) = v {
                return vec![*value, idx as i32];
            } else {
                map.insert(*num, idx as i32);
            }
        }

        vec![]
    }
}

#[cfg(test)]
mod test {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(vec![2, 7, 11, 15], 9, vec![0, 1])]
    #[case(vec![3, 2, 4], 6, vec![1, 2])]
    #[case(vec![3, 3], 6, vec![0, 1])]
    fn two_sum_test(#[case] nums: Vec<i32>, #[case] target: i32, #[case] expected: Vec<i32>) {
        assert_eq!(Solution::two_sum(nums, target), expected);
    }
}
