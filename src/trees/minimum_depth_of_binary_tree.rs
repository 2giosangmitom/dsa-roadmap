use crate::trees::data_structure::TreeNode;
use std::cell::RefCell;
use std::rc::Rc;

struct Solution;

impl Solution {
    pub fn min_depth(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        match root {
            None => 0,
            Some(node) => {
                let left = node.borrow().left.clone();
                let right = node.borrow().right.clone();
                match (left, right) {
                    (None, None) => 1,
                    (None, r) => 1 + Self::min_depth(r),
                    (l, None) => 1 + Self::min_depth(l),
                    (l, r) => 1 + Self::min_depth(l).min(Self::min_depth(r)),
                }
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![Some(3), Some(9), Some(20), None, None, Some(15), Some(7)], 2)]
    #[case(vec![Some(2), None, Some(3), None, Some(4), None, Some(5), None, Some(6)], 5)]
    fn test(#[case] input: Vec<Option<i32>>, #[case] expected: i32) {
        let root = TreeNode::from_vec(input);
        assert_eq!(Solution::min_depth(root), expected);
    }
}
