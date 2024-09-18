use std::collections::HashMap;

impl Solution {
    pub fn unique_occurrences(arr: Vec<i32>) -> bool {
        let mut count_dict = HashMap::new();

        for num in arr {
            *count_dict.entry(num).or_insert(0) += 1;
        }

        let values_num = count_dict.len();
        let set_num = count_dict.values().cloned().collect::<std::collections::HashSet<_>>().len();

        if values_num == set_num {
            return true;
        } else {
            return false;
        }

        



        return true;
    }
}