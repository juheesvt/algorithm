impl Solution {
    pub fn largest_altitude(gain: Vec<i32>) -> i32 {
        let mut current = 0;
        let mut max_num = 0;

        for element in gain {
            current += element;
            if current > max_num {
                max_num = current;
            }
        }
        return max_num;
    }
}