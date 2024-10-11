impl Solution {
    pub fn product_except_self(nums: Vec<i32>) -> Vec<i32> {

        let mut answers: Vec<i32> = vec![1; nums.len()];

        let mut left = 1;
        let mut right = 1;

        for i in (0..nums.len()) {
            answers[i] *= left;
            left *= nums[i];
        }
        for i in (0..nums.len()).rev() {
            answers[i] *= right;
            right *= nums[i];
        }
        return answers;
    }
}