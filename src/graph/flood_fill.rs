struct Solution;

impl Solution {
    pub fn flood_fill(mut image: Vec<Vec<i32>>, sr: i32, sc: i32, color: i32) -> Vec<Vec<i32>> {
        let directions = [(-1, 0), (0, 1), (1, 0), (0, -1)];
        let (m, n) = (image.len() as i32, image[0].len() as i32);
        let original_color = image[sr as usize][sc as usize];
        image[sr as usize][sc as usize] = color;

        for (x, y) in directions {
            let next_sr = sr + x;
            let next_sc = sc + y;
            if next_sr < 0
                || next_sr >= m
                || next_sc < 0
                || next_sc >= n
                || image[next_sr as usize][next_sc as usize] != original_color
                || image[next_sr as usize][next_sc as usize] == color
            {
                continue;
            }

            image = Self::flood_fill(image, next_sr, next_sc, color);
        }

        image
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![vec![1, 1, 1], vec![1, 1, 0], vec![1, 0, 1]], 1, 1, 2, vec![vec![2, 2, 2], vec![2, 2, 0], vec![2, 0, 1]])]
    #[case(vec![vec![0, 0, 0], vec![0, 1, 1]], 1, 1, 1, vec![vec![0, 0, 0], vec![0, 1, 1]])]
    fn test_flood_fill(
        #[case] image: Vec<Vec<i32>>,
        #[case] sr: i32,
        #[case] sc: i32,
        #[case] color: i32,
        #[case] expected: Vec<Vec<i32>>,
    ) {
        assert_eq!(Solution::flood_fill(image, sr, sc, color), expected);
    }
}
