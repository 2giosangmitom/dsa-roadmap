// Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }

    pub fn from_vec(vec: Vec<i32>) -> Option<Box<ListNode>> {
        let mut head = None;
        let mut current = &mut head;

        for &value in vec.iter() {
            let new_node = Box::new(ListNode::new(value));
            *current = Some(new_node);
            if let Some(node) = current {
                current = &mut node.next;
            }
        }

        head
    }

    pub fn to_vec(head: Option<Box<ListNode>>) -> Vec<i32> {
        let mut vec = Vec::new();
        let mut current = head;

        while let Some(node) = current {
            vec.push(node.val);
            current = node.next;
        }

        vec
    }
}

use std::cell::RefCell;
use std::rc::Rc;

pub type RcListNodeRef = Rc<RefCell<RcListNode>>;

#[derive(Debug)]
pub struct RcListNode {
    pub val: i32,
    pub next: Option<RcListNodeRef>,
}

impl RcListNode {
    pub fn new(val: i32) -> RcListNodeRef {
        Rc::new(RefCell::new(RcListNode { val, next: None }))
    }

    pub fn from_vec(values: Vec<i32>) -> Option<RcListNodeRef> {
        let mut head: Option<RcListNodeRef> = None;
        let mut tail: Option<RcListNodeRef> = None;

        for value in values {
            let node = RcListNode::new(value);
            if let Some(tail_node) = tail {
                tail_node.borrow_mut().next = Some(node.clone());
                tail = Some(node);
            } else {
                head = Some(node.clone());
                tail = Some(node);
            }
        }

        head
    }

    pub fn to_vec_limit(head: Option<RcListNodeRef>, limit: usize) -> Vec<i32> {
        let mut result = Vec::new();
        let mut current = head;
        let mut steps = 0;

        while let Some(node) = current {
            if steps >= limit {
                break;
            }
            result.push(node.borrow().val);
            current = node.borrow().next.clone();
            steps += 1;
        }

        result
    }
}

pub type DoublyNodeRef = Rc<RefCell<DoublyNode>>;

#[derive(Debug)]
pub struct DoublyNode {
    pub val: i32,
    pub prev: Option<DoublyNodeRef>,
    pub next: Option<DoublyNodeRef>,
    pub child: Option<DoublyNodeRef>,
}

impl DoublyNode {
    pub fn new(val: i32) -> DoublyNodeRef {
        Rc::new(RefCell::new(DoublyNode {
            val,
            prev: None,
            next: None,
            child: None,
        }))
    }

    pub fn to_vec(head: Option<DoublyNodeRef>) -> Vec<i32> {
        let mut result = Vec::new();
        let mut current = head;

        while let Some(node) = current {
            result.push(node.borrow().val);
            current = node.borrow().next.clone();
        }

        result
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![1, 2, 3], vec![1, 2, 3])]
    #[case(vec![], vec![])]
    fn test_list_node(#[case] input: Vec<i32>, #[case] expected: Vec<i32>) {
        let head = ListNode::from_vec(input);
        let result = ListNode::to_vec(head);
        assert_eq!(result, expected);
    }
}
