impl Solution {
    pub fn find_max_average(nums: Vec<i32>, k: i32) -> f64 {
        let k = k as usize;
        let mut max_num: f64 = -123456789.0;
        let mut current_num: f64 = nums[0..k].iter().map(|&x| x as f64).sum();

        max_num = if max_num < current_num {
            current_num
        } else {
            max_num
        };

        for i in 0..(nums.len() - k) {
            current_num += -nums[i] as f64 + nums[i + k] as f64; 
            if current_num > max_num {
                max_num = current_num;
            }
        }

        return max_num / (k as f64);
    }
}