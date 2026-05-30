struct Solution;

impl Solution {
    pub fn can_complete_circuit(gas: Vec<i32>, cost: Vec<i32>) -> i32 {
        let total_gas: i32 = gas.iter().sum();
        let total_cost: i32 = cost.iter().sum();
        if total_gas < total_cost {
            return -1;
        }

        let mut start = 0;
        let mut tank = 0;
        for i in 0..gas.len() {
            tank += gas[i] - cost[i];
            if tank < 0 {
                start = i as i32 + 1;
                tank = 0;
            }
        }
        start
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![1, 2, 3, 4, 5], vec![3, 4, 5, 1, 2], 3)]
    #[case(vec![2, 3, 4], vec![3, 4, 3], -1)]
    fn test_can_complete_circuit(
        #[case] gas: Vec<i32>,
        #[case] cost: Vec<i32>,
        #[case] expected: i32,
    ) {
        assert_eq!(Solution::can_complete_circuit(gas, cost), expected);
    }
}
