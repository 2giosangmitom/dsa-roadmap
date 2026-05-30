use crate::trees::data_structure::TreeNode;
use std::cell::RefCell;
use std::rc::Rc;

struct Solution;

impl Solution {
    fn height(node: &Option<Rc<RefCell<TreeNode>>>) -> i32 {
        match node {
            None => 0,
            Some(v) => {
                let left_height = Self::height(&v.borrow().left);
                if left_height == -1 {
                    return -1;
                }
                let right_height = Self::height(&v.borrow().right);
                if right_height == -1 {
                    return -1;
                }
                if (left_height - right_height).abs() > 1 {
                    -1
                } else {
                    1 + left_height.max(right_height)
                }
            }
        }
    }

    pub fn is_balanced(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        Self::height(&root) != -1
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![Some(3), Some(9), Some(20), None, None, Some(15), Some(7)], true)]
    #[case(
        vec![Some(1), Some(2), Some(2), Some(3), Some(3), None, None, Some(4), Some(4)],
        false
    )]
    fn test(#[case] input: Vec<Option<i32>>, #[case] expected: bool) {
        let root = TreeNode::from_vec(input);
        assert_eq!(Solution::is_balanced(root), expected);
    }
}
