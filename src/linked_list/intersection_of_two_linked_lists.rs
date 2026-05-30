use crate::linked_list::data_structure::RcListNodeRef;
use std::rc::Rc;

struct Solution;

impl Solution {
    pub fn get_intersection_node(
        head_a: Option<RcListNodeRef>,
        head_b: Option<RcListNodeRef>,
    ) -> Option<RcListNodeRef> {
        let mut ptr_a = head_a.clone();
        let mut ptr_b = head_b.clone();

        while !Self::same_node(&ptr_a, &ptr_b) {
            ptr_a = match ptr_a {
                Some(node) => node.borrow().next.clone(),
                None => head_b.clone(),
            };
            ptr_b = match ptr_b {
                Some(node) => node.borrow().next.clone(),
                None => head_a.clone(),
            };
        }

        ptr_a
    }

    fn same_node(a: &Option<RcListNodeRef>, b: &Option<RcListNodeRef>) -> bool {
        match (a, b) {
            (Some(a_node), Some(b_node)) => Rc::ptr_eq(a_node, b_node),
            (None, None) => true,
            _ => false,
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::linked_list::data_structure::RcListNode;
    use rstest::rstest;
    use std::ptr;

    fn ptr_addr(node: &Option<RcListNodeRef>) -> *const RcListNode {
        match node {
            Some(node) => &*node.borrow() as *const RcListNode,
            None => ptr::null(),
        }
    }

    #[rstest]
    fn test_get_intersection_node_exists() {
        let shared = RcListNode::from_vec(vec![8, 4, 5]).unwrap();

        let list_a = RcListNode::from_vec(vec![4, 1]).unwrap();
        let mut tail_a = list_a.clone();
        while tail_a.borrow().next.is_some() {
            let next = tail_a.borrow().next.clone().unwrap();
            tail_a = next;
        }
        tail_a.borrow_mut().next = Some(shared.clone());

        let list_b = RcListNode::from_vec(vec![5, 6, 1]).unwrap();
        let mut tail_b = list_b.clone();
        while tail_b.borrow().next.is_some() {
            let next = tail_b.borrow().next.clone().unwrap();
            tail_b = next;
        }
        tail_b.borrow_mut().next = Some(shared.clone());

        let result = Solution::get_intersection_node(Some(list_a), Some(list_b));
        assert_eq!(ptr_addr(&result), ptr_addr(&Some(shared)));
    }

    #[rstest]
    fn test_get_intersection_node_none() {
        let list_a = RcListNode::from_vec(vec![2, 6, 4]);
        let list_b = RcListNode::from_vec(vec![1, 5]);
        let result = Solution::get_intersection_node(list_a, list_b);
        assert!(result.is_none());
    }
}
