use crate::trees::data_structure::TreeNode;
use std::cell::RefCell;
use std::collections::VecDeque;
use std::rc::Rc;

struct Solution;

impl Solution {
    pub fn vertical_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
        let mut nodes = Vec::new();
        let mut queue = VecDeque::new();
        if let Some(node) = root {
            queue.push_back((node, 0i32, 0i32));
        }
        while let Some((node, col, row)) = queue.pop_front() {
            let val = node.borrow().val;
            nodes.push((col, row, val));
            if let Some(left) = &node.borrow().left {
                queue.push_back((left.clone(), col - 1, row + 1));
            }
            if let Some(right) = &node.borrow().right {
                queue.push_back((right.clone(), col + 1, row + 1));
            }
        }
        nodes.sort_by(|a, b| a.0.cmp(&b.0).then(a.1.cmp(&b.1)).then(a.2.cmp(&b.2)));
        let mut result = Vec::new();
        let mut i = 0;
        while i < nodes.len() {
            let mut col_group = Vec::new();
            let col = nodes[i].0;
            while i < nodes.len() && nodes[i].0 == col {
                col_group.push(nodes[i].2);
                i += 1;
            }
            result.push(col_group);
        }
        result
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(
        vec![Some(3), Some(9), Some(20), None, None, Some(15), Some(7)],
        vec![vec![9], vec![3, 15], vec![20], vec![7]]
    )]
    #[case(
        vec![Some(1), Some(2), Some(3), Some(4), Some(5), Some(6), Some(7)],
        vec![vec![4], vec![2], vec![1, 5, 6], vec![3], vec![7]]
    )]
    fn test(#[case] input: Vec<Option<i32>>, #[case] expected: Vec<Vec<i32>>) {
        let root = TreeNode::from_vec(input);
        assert_eq!(Solution::vertical_traversal(root), expected);
    }
}
