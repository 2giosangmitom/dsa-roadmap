use crate::linked_list::data_structure::RcListNodeRef;
use std::rc::Rc;

struct Solution;

impl Solution {
    pub fn has_cycle(head: Option<RcListNodeRef>) -> bool {
        let mut slow = head.clone();
        let mut fast = head;

        while let (Some(slow_node), Some(fast_node)) = (slow.clone(), fast.clone()) {
            slow = slow_node.borrow().next.clone();
            fast = fast_node
                .borrow()
                .next
                .clone()
                .and_then(|node| node.borrow().next.clone());

            if let (Some(slow_ref), Some(fast_ref)) = (slow.clone(), fast.clone())
                && Rc::ptr_eq(&slow_ref, &fast_ref)
            {
                return true;
            }
        }

        false
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::linked_list::data_structure::RcListNode;
    use rstest::rstest;

    #[rstest]
    fn test_has_cycle_true() {
        let head = RcListNode::from_vec(vec![3, 2, 0, -4]).unwrap();
        let mut tail = head.clone();
        let entry = head.borrow().next.clone().unwrap();

        while tail.borrow().next.is_some() {
            let next = tail.borrow().next.clone().unwrap();
            tail = next;
        }

        tail.borrow_mut().next = Some(entry);

        assert!(Solution::has_cycle(Some(head)));
    }

    #[rstest]
    fn test_has_cycle_false() {
        let head = RcListNode::from_vec(vec![1, 2, 3, 4]);
        assert!(!Solution::has_cycle(head));
    }

    #[rstest]
    fn test_has_cycle_single() {
        let head = RcListNode::new(1);
        head.borrow_mut().next = Some(head.clone());
        assert!(Solution::has_cycle(Some(head)));
    }
}
