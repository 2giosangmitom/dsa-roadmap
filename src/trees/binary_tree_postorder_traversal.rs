use crate::trees::data_structure::TreeNode;
use std::cell::RefCell;
use std::rc::Rc;

struct Solution;

impl Solution {
    fn helper(node: &Option<Rc<RefCell<TreeNode>>>, result: &mut Vec<i32>) {
        if let Some(rc_node) = node {
            let node_ref = rc_node.borrow();
            Self::helper(&node_ref.left, result);
            Self::helper(&node_ref.right, result);
            result.push(node_ref.val);
        }
    }

    pub fn postorder_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut result = Vec::new();
        Self::helper(&root, &mut result);
        result
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![Some(1), None, Some(2), Some(3)], vec![3, 2, 1])]
    #[case(vec![], vec![])]
    #[case(vec![Some(1)], vec![1])]
    fn test_postorder_traversal(#[case] input: Vec<Option<i32>>, #[case] expected: Vec<i32>) {
        let tree = TreeNode::from_vec(input);
        let result = Solution::postorder_traversal(tree);
        assert_eq!(result, expected);
    }
}
