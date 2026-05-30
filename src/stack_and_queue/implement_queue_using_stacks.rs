struct MyQueue {
    input: Vec<i32>,
    output: Vec<i32>,
}

impl MyQueue {
    fn new() -> Self {
        Self {
            input: Vec::new(),
            output: Vec::new(),
        }
    }

    fn push(&mut self, x: i32) {
        self.input.push(x);
    }

    fn pop(&mut self) -> i32 {
        self.peek();
        self.output.pop().unwrap()
    }

    fn peek(&mut self) -> i32 {
        if self.output.is_empty() {
            while let Some(val) = self.input.pop() {
                self.output.push(val);
            }
        }
        *self.output.last().unwrap()
    }

    fn empty(&self) -> bool {
        self.input.is_empty() && self.output.is_empty()
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    fn test_my_queue() {
        let mut q = MyQueue::new();
        q.push(1);
        q.push(2);
        assert_eq!(q.peek(), 1);
        assert_eq!(q.pop(), 1);
        assert!(!q.empty());
    }
}
