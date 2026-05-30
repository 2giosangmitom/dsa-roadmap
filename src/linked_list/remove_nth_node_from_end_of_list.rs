use crate::linked_list::data_structure::ListNode;

struct Solution;

impl Solution {
    pub fn remove_nth_from_end(head: Option<Box<ListNode>>, n: i32) -> Option<Box<ListNode>> {
        let mut dummy = Box::new(ListNode { val: 0, next: head });
        let mut len = 0;
        let mut current = dummy.next.as_ref();
        while let Some(node) = current {
            len += 1;
            current = node.next.as_ref();
        }

        let target_index = len - n as usize;
        let mut slow = &mut dummy;
        for _ in 0..target_index {
            slow = slow.next.as_mut().unwrap();
        }

        let next = slow.next.as_mut().unwrap().next.take();
        slow.next = next;
        dummy.next
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![1, 2, 3, 4, 5], 2, vec![1, 2, 3, 5])]
    #[case(vec![1], 1, vec![])]
    #[case(vec![1, 2], 1, vec![1])]
    fn test_remove_nth_from_end(
        #[case] input: Vec<i32>,
        #[case] n: i32,
        #[case] expected: Vec<i32>,
    ) {
        let head = ListNode::from_vec(input);
        let result = Solution::remove_nth_from_end(head, n);
        assert_eq!(ListNode::to_vec(result), expected);
    }
}
