use crate::linked_list::data_structure::ListNode;

struct Solution;

impl Solution {
    pub fn reverse_between(
        head: Option<Box<ListNode>>,
        left: i32,
        right: i32,
    ) -> Option<Box<ListNode>> {
        if left == right {
            return head;
        }

        let mut dummy = Box::new(ListNode { val: 0, next: head });
        let mut prev = &mut dummy;

        for _ in 1..left {
            prev = prev.next.as_mut().unwrap();
        }

        let mut current = prev.next.take();
        let mut reversed: Option<Box<ListNode>> = None;

        for _ in left..=right {
            let mut node = current.take().unwrap();
            current = node.next.take();
            node.next = reversed;
            reversed = Some(node);
        }

        let mut tail_ref = reversed.as_mut().unwrap();
        while tail_ref.next.is_some() {
            tail_ref = tail_ref.next.as_mut().unwrap();
        }
        tail_ref.next = current;
        prev.next = reversed;
        dummy.next
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![1, 2, 3, 4, 5], 2, 4, vec![1, 4, 3, 2, 5])]
    #[case(vec![5], 1, 1, vec![5])]
    #[case(vec![1, 2, 3], 1, 2, vec![2, 1, 3])]
    fn test_reverse_between(
        #[case] input: Vec<i32>,
        #[case] left: i32,
        #[case] right: i32,
        #[case] expected: Vec<i32>,
    ) {
        let head = ListNode::from_vec(input);
        let result = Solution::reverse_between(head, left, right);
        assert_eq!(ListNode::to_vec(result), expected);
    }
}
