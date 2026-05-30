use crate::trees::data_structure::TreeNode;
use std::cell::RefCell;
use std::rc::Rc;

struct Solution;

impl Solution {
    pub fn lowest_common_ancestor(
        root: Option<Rc<RefCell<TreeNode>>>,
        p: Option<Rc<RefCell<TreeNode>>>,
        q: Option<Rc<RefCell<TreeNode>>>,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        match root {
            None => None,
            Some(node) => {
                if node.borrow().val == p.as_ref().unwrap().borrow().val
                    || node.borrow().val == q.as_ref().unwrap().borrow().val
                {
                    return Some(node);
                }
                let left =
                    Self::lowest_common_ancestor(node.borrow().left.clone(), p.clone(), q.clone());
                let right = Self::lowest_common_ancestor(node.borrow().right.clone(), p, q);
                match (left, right) {
                    (Some(_), Some(_)) => Some(node),
                    (Some(l), None) => Some(l),
                    (None, Some(r)) => Some(r),
                    (None, None) => None,
                }
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    fn find_node(root: &Option<Rc<RefCell<TreeNode>>>, val: i32) -> Option<Rc<RefCell<TreeNode>>> {
        match root {
            None => None,
            Some(node) => {
                if node.borrow().val == val {
                    return Some(node.clone());
                }
                if let Some(found) = find_node(&node.borrow().left, val) {
                    return Some(found);
                }
                find_node(&node.borrow().right, val)
            }
        }
    }

    #[rstest]
    #[case(
        vec![Some(3), Some(5), Some(1), Some(6), Some(2), Some(0), Some(8), None, None, Some(7), Some(4)],
        5,
        1,
        3
    )]
    #[case(
        vec![Some(3), Some(5), Some(1), Some(6), Some(2), Some(0), Some(8), None, None, Some(7), Some(4)],
        5,
        4,
        5
    )]
    fn test(
        #[case] input: Vec<Option<i32>>,
        #[case] p_val: i32,
        #[case] q_val: i32,
        #[case] expected: i32,
    ) {
        let root = TreeNode::from_vec(input);
        let p = find_node(&root, p_val);
        let q = find_node(&root, q_val);
        let lca = Solution::lowest_common_ancestor(root, p, q);
        assert_eq!(lca.unwrap().borrow().val, expected);
    }
}
