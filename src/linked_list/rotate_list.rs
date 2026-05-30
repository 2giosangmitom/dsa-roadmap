use crate::linked_list::data_structure::ListNode;

struct Solution;

impl Solution {
    pub fn rotate_right(head: Option<Box<ListNode>>, k: i32) -> Option<Box<ListNode>> {
        let mut head = head;
        head.as_ref()?;

        let mut len = 1;
        let mut tail = head.as_mut().unwrap();
        while tail.next.is_some() {
            tail = tail.next.as_mut().unwrap();
            len += 1;
        }

        let k = (k as usize) % len;
        if k == 0 {
            return head;
        }

        let steps_to_new_tail = len - k - 1;
        let mut new_tail = head.as_mut().unwrap();
        for _ in 0..steps_to_new_tail {
            new_tail = new_tail.next.as_mut().unwrap();
        }

        let mut new_head = new_tail.next.take();
        let mut new_tail_iter = new_head.as_mut().unwrap();
        while new_tail_iter.next.is_some() {
            new_tail_iter = new_tail_iter.next.as_mut().unwrap();
        }
        new_tail_iter.next = head;

        new_head
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![1, 2, 3, 4, 5], 2, vec![4, 5, 1, 2, 3])]
    #[case(vec![0, 1, 2], 4, vec![2, 0, 1])]
    #[case(vec![], 1, vec![])]
    fn test_rotate_right(#[case] input: Vec<i32>, #[case] k: i32, #[case] expected: Vec<i32>) {
        let head = ListNode::from_vec(input);
        let result = Solution::rotate_right(head, k);
        assert_eq!(ListNode::to_vec(result), expected);
    }
}
