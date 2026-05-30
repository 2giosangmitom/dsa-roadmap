use crate::linked_list::data_structure::ListNode;

struct Solution;

impl Solution {
    pub fn add_two_numbers(
        mut l1: Option<Box<ListNode>>,
        mut l2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        let mut stack1 = Vec::new();
        let mut stack2 = Vec::new();

        while let Some(node) = l1 {
            stack1.push(node.val);
            l1 = node.next;
        }
        while let Some(node) = l2 {
            stack2.push(node.val);
            l2 = node.next;
        }

        let mut carry = 0;
        let mut head: Option<Box<ListNode>> = None;

        while !stack1.is_empty() || !stack2.is_empty() || carry != 0 {
            let sum = stack1.pop().unwrap_or(0) + stack2.pop().unwrap_or(0) + carry;
            carry = sum / 10;
            let mut node = Box::new(ListNode::new(sum % 10));
            node.next = head;
            head = Some(node);
        }

        head
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![7, 2, 4, 3], vec![5, 6, 4], vec![7, 8, 0, 7])]
    #[case(vec![2, 4, 3], vec![5, 6, 4], vec![8, 0, 7])]
    #[case(vec![0], vec![0], vec![0])]
    fn test_add_two_numbers_ii(
        #[case] input1: Vec<i32>,
        #[case] input2: Vec<i32>,
        #[case] expected: Vec<i32>,
    ) {
        let l1 = ListNode::from_vec(input1);
        let l2 = ListNode::from_vec(input2);
        let result = Solution::add_two_numbers(l1, l2);
        assert_eq!(ListNode::to_vec(result), expected);
    }
}
