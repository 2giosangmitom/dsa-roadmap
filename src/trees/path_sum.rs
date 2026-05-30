use crate::trees::data_structure::TreeNode;
use std::cell::RefCell;
use std::rc::Rc;

struct Solution;

impl Solution {
    pub fn has_path_sum(root: Option<Rc<RefCell<TreeNode>>>, target_sum: i32) -> bool {
        match root {
            None => false,
            Some(node) => {
                let val = node.borrow().val;
                let left = node.borrow().left.clone();
                let right = node.borrow().right.clone();
                if left.is_none() && right.is_none() {
                    return val == target_sum;
                }
                Self::has_path_sum(left, target_sum - val)
                    || Self::has_path_sum(right, target_sum - val)
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(
        vec![Some(5), Some(4), Some(8), Some(11), None, Some(13), Some(4), Some(7), Some(2), None, None, None, Some(1)],
        22,
        true
    )]
    #[case(vec![Some(1), Some(2), Some(3)], 5, false)]
    fn test(#[case] input: Vec<Option<i32>>, #[case] target: i32, #[case] expected: bool) {
        let root = TreeNode::from_vec(input);
        assert_eq!(Solution::has_path_sum(root, target), expected);
    }
}
