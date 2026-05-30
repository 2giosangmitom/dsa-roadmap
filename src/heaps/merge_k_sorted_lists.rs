use crate::linked_list::data_structure::ListNode;

struct Solution;

impl Solution {
    pub fn merge_k_lists(lists: Vec<Option<Box<ListNode>>>) -> Option<Box<ListNode>> {
        let mut values = Vec::new();
        for head in lists {
            let mut curr = head;
            while let Some(node) = curr {
                values.push(node.val);
                curr = node.next;
            }
        }
        values.sort_unstable();
        ListNode::from_vec(values)
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(
        vec![vec![1, 4, 5], vec![1, 3, 4], vec![2, 6]],
        vec![1, 1, 2, 3, 4, 4, 5, 6]
    )]
    #[case(vec![vec![]], vec![])]
    #[case(vec![vec![1]], vec![1])]
    fn test_merge_k_lists(#[case] inputs: Vec<Vec<i32>>, #[case] expected: Vec<i32>) {
        let lists: Vec<Option<Box<ListNode>>> =
            inputs.into_iter().map(ListNode::from_vec).collect();
        let result = Solution::merge_k_lists(lists);
        assert_eq!(ListNode::to_vec(result), expected);
    }
}
