use crate::trees::data_structure::TreeNode;
use std::cell::RefCell;
use std::rc::Rc;

struct Solution;

impl Solution {
    fn dfs(node: &Option<Rc<RefCell<TreeNode>>>, max_sum: &mut i32) -> i32 {
        match node {
            None => 0,
            Some(v) => {
                let left_gain = Self::dfs(&v.borrow().left, max_sum).max(0);
                let right_gain = Self::dfs(&v.borrow().right, max_sum).max(0);
                let total = v.borrow().val + left_gain + right_gain;
                *max_sum = (*max_sum).max(total);
                v.borrow().val + left_gain.max(right_gain)
            }
        }
    }

    pub fn max_path_sum(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut max_sum = i32::MIN;
        Self::dfs(&root, &mut max_sum);
        max_sum
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![Some(1), Some(2), Some(3)], 6)]
    #[case(vec![Some(-10), Some(9), Some(20), None, None, Some(15), Some(7)], 42)]
    fn test(#[case] input: Vec<Option<i32>>, #[case] expected: i32) {
        let root = TreeNode::from_vec(input);
        assert_eq!(Solution::max_path_sum(root), expected);
    }
}
