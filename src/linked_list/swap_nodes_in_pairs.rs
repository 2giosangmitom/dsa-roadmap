use crate::linked_list::data_structure::ListNode;

struct Solution;

impl Solution {
    pub fn swap_pairs(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut dummy = Box::new(ListNode { val: 0, next: head });
        let mut prev = &mut dummy;

        while prev.next.is_some() && prev.next.as_ref().unwrap().next.is_some() {
            let mut first = prev.next.take().unwrap();
            let mut second = first.next.take().unwrap();

            first.next = second.next.take();
            second.next = Some(first);
            prev.next = Some(second);
            prev = prev.next.as_mut().unwrap().next.as_mut().unwrap();
        }

        dummy.next
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![1, 2, 3, 4], vec![2, 1, 4, 3])]
    #[case(vec![1], vec![1])]
    #[case(vec![], vec![])]
    fn test_swap_pairs(#[case] input: Vec<i32>, #[case] expected: Vec<i32>) {
        let head = ListNode::from_vec(input);
        let result = Solution::swap_pairs(head);
        assert_eq!(ListNode::to_vec(result), expected);
    }
}
