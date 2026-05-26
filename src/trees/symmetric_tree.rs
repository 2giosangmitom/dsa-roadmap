use crate::trees::data_structure::TreeNode;
use std::cell::RefCell;
use std::rc::Rc;

struct Solution;

impl Solution {
    fn helper(
        node1: &Option<Rc<RefCell<TreeNode>>>,
        node2: &Option<Rc<RefCell<TreeNode>>>,
    ) -> bool {
        match (node1, node2) {
            (None, None) => true,
            (None, _) | (_, None) => false,
            (Some(v1), Some(v2)) => {
                let tree_node1 = v1.borrow();
                let tree_node2 = v2.borrow();
                if tree_node1.val != tree_node2.val {
                    false
                } else {
                    Self::helper(&tree_node1.left, &tree_node2.right)
                        && Self::helper(&tree_node1.right, &tree_node2.left)
                }
            }
        }
    }

    pub fn is_symmetric(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        if let Some(v) = root {
            let root_node = v.borrow();
            return Self::helper(&root_node.left, &root_node.right);
        }
        true
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![Some(1), Some(2), Some(2), Some(3), Some(4), Some(4), Some(3)], true)]
    #[case(vec![Some(1), Some(2), Some(2), None, Some(3), None, Some(3)], false)]
    fn test(#[case] input: Vec<Option<i32>>, #[case] expected: bool) {
        let root = TreeNode::from_vec(input);
        assert_eq!(Solution::is_symmetric(root), expected);
    }
}
