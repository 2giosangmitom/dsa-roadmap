use std::cmp::Reverse;
use std::collections::BinaryHeap;

struct MedianFinder {
    left: BinaryHeap<i32>,
    right: BinaryHeap<Reverse<i32>>,
}

impl MedianFinder {
    pub fn new() -> Self {
        MedianFinder {
            left: BinaryHeap::new(),
            right: BinaryHeap::new(),
        }
    }

    pub fn add_num(&mut self, num: i32) {
        self.left.push(num);

        if let Some(&left_max) = self.left.peek()
            && let Some(&Reverse(right_min)) = self.right.peek()
            && left_max > right_min
        {
            self.right.push(Reverse(self.left.pop().unwrap()));
        }

        if self.left.len() > self.right.len() + 1 {
            self.right.push(Reverse(self.left.pop().unwrap()));
        } else if self.right.len() > self.left.len() {
            self.left.push(self.right.pop().unwrap().0);
        }
    }

    pub fn find_median(&self) -> f64 {
        if self.left.len() > self.right.len() {
            *self.left.peek().unwrap() as f64
        } else {
            let left = *self.left.peek().unwrap() as f64;
            let right = self.right.peek().unwrap().0 as f64;
            (left + right) / 2.0
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    fn test_median_finder() {
        let mut mf = MedianFinder::new();
        mf.add_num(1);
        mf.add_num(2);
        assert!((mf.find_median() - 1.5).abs() < 1e-10);
        mf.add_num(3);
        assert!((mf.find_median() - 2.0).abs() < 1e-10);
    }
}
