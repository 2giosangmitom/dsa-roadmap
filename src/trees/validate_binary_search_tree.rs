use crate::trees::data_structure::TreeNode;
use std::cell::RefCell;
use std::rc::Rc;

struct Solution;

impl Solution {
    fn helper(node: &Option<Rc<RefCell<TreeNode>>>, min: Option<i64>, max: Option<i64>) -> bool {
        match node {
            None => true,
            Some(v) => {
                let val = v.borrow().val as i64;
                if let Some(min_val) = min
                    && val <= min_val
                {
                    return false;
                }
                if let Some(max_val) = max
                    && val >= max_val
                {
                    return false;
                }
                Self::helper(&v.borrow().left, min, Some(val))
                    && Self::helper(&v.borrow().right, Some(val), max)
            }
        }
    }

    pub fn is_valid_bst(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        Self::helper(&root, None, None)
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![Some(2), Some(1), Some(3)], true)]
    #[case(vec![Some(5), Some(1), Some(4), None, None, Some(3), Some(6)], false)]
    fn test(#[case] input: Vec<Option<i32>>, #[case] expected: bool) {
        let root = TreeNode::from_vec(input);
        assert_eq!(Solution::is_valid_bst(root), expected);
    }
}
