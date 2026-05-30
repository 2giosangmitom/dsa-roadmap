use crate::linked_list::data_structure::ListNode;

struct Solution;

impl Solution {
    pub fn sort_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        if head.is_none() || head.as_ref().unwrap().next.is_none() {
            return head;
        }

        let (left, right) = Self::split(head);
        let left = Self::sort_list(left);
        let right = Self::sort_list(right);
        Self::merge(left, right)
    }

    fn split(head: Option<Box<ListNode>>) -> (Option<Box<ListNode>>, Option<Box<ListNode>>) {
        let mut len = 0;
        let mut cur = head.as_ref();
        while let Some(node) = cur {
            len += 1;
            cur = node.next.as_ref();
        }

        let mid = len / 2;
        let mut dummy = Box::new(ListNode { val: 0, next: head });
        let mut curr = &mut dummy;
        for _ in 0..mid {
            curr = curr.next.as_mut().unwrap();
        }

        let right = curr.next.take();
        let left = dummy.next.take();
        (left, right)
    }

    fn merge(left: Option<Box<ListNode>>, right: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut dummy = Box::new(ListNode { val: 0, next: None });
        let mut curr = &mut dummy;
        let mut l = left;
        let mut r = right;

        while let (Some(l_node), Some(r_node)) = (l.as_ref(), r.as_ref()) {
            if l_node.val <= r_node.val {
                curr.next = l;
                curr = curr.next.as_mut().unwrap();
                l = curr.next.take();
            } else {
                curr.next = r;
                curr = curr.next.as_mut().unwrap();
                r = curr.next.take();
            }
        }

        curr.next = if l.is_some() { l } else { r };
        dummy.next
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![4, 2, 1, 3], vec![1, 2, 3, 4])]
    #[case(vec![-1, 5, 3, 4, 0], vec![-1, 0, 3, 4, 5])]
    #[case(vec![], vec![])]
    fn test_sort_list(#[case] input: Vec<i32>, #[case] expected: Vec<i32>) {
        let head = ListNode::from_vec(input);
        let result = Solution::sort_list(head);
        assert_eq!(ListNode::to_vec(result), expected);
    }
}
