use crate::trees::data_structure::TreeNode;
use std::cell::RefCell;
use std::rc::Rc;

struct Solution;

impl Solution {
    fn helper(node: &Option<Rc<RefCell<TreeNode>>>, result: &mut Vec<i32>) {
        if let Some(v) = node {
            let tree_node = v.borrow();
            result.push(tree_node.val);
            Self::helper(&tree_node.left, result);
            Self::helper(&tree_node.right, result);
        }
    }

    pub fn preorder_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut result = Vec::<i32>::new();

        Self::helper(&root, &mut result);

        result
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![Some(1), None, Some(2), Some(3)], vec![1, 2, 3])]
    #[case(vec![], vec![])]
    #[case(vec![Some(1)], vec![1])]
    fn test_preorder_traversal(#[case] input: Vec<Option<i32>>, #[case] expected: Vec<i32>) {
        let tree = TreeNode::from_vec(input);
        let result = Solution::preorder_traversal(tree);
        assert_eq!(result, expected);
    }
}
