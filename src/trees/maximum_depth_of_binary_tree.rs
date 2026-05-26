use crate::trees::data_structure::TreeNode;
use std::cell::RefCell;
use std::rc::Rc;

struct Solution;

impl Solution {
    pub fn max_depth(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        match root {
            Some(v) => {
                let tree_node = v.borrow();
                1 + Self::max_depth(tree_node.left.clone())
                    .max(Self::max_depth(tree_node.right.clone()))
            }
            None => 0,
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![Some(3), Some(9), Some(20), None, None, Some(15), Some(7)], 3)]
    #[case(vec![Some(1), None, Some(2)], 2)]
    fn test(#[case] input: Vec<Option<i32>>, #[case] expected: i32) {
        let root = TreeNode::from_vec(input);
        assert_eq!(Solution::max_depth(root), expected);
    }
}
