use crate::trees::data_structure::TreeNode;
use std::cell::RefCell;
use std::rc::Rc;

struct Solution;

impl Solution {
    pub fn invert_tree(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        if let Some(node) = root {
            let left = node.borrow().left.clone();
            let right = node.borrow().right.clone();
            node.borrow_mut().left = Self::invert_tree(right);
            node.borrow_mut().right = Self::invert_tree(left);
            Some(node)
        } else {
            None
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(
        vec![Some(4), Some(2), Some(7), Some(1), Some(3), Some(6), Some(9)],
        vec![Some(4), Some(7), Some(2), Some(9), Some(6), Some(3), Some(1)]
    )]
    #[case(
        vec![Some(2), Some(1), Some(3)],
        vec![Some(2), Some(3), Some(1)]
    )]
    fn test(#[case] input: Vec<Option<i32>>, #[case] expected: Vec<Option<i32>>) {
        let root = TreeNode::from_vec(input);
        let result = Solution::invert_tree(root);
        let expected_root = TreeNode::from_vec(expected);
        assert_eq!(result, expected_root);
    }
}
