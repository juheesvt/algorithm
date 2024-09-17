impl Solution {
    pub fn gcd_of_strings(str1: String, str2: String) -> String {
        if format!("{}{}", str1, str2) != format!("{}{}", str2, str1) {
            return "".to_string();
        } else {
            let mut a;
            let mut b;
            if str1.len() > str2.len() {
                a = str1.len();
                b = str2.len();
            } else {
                a = str2.len();
                b = str1.len();
            }

            let mut n = a % b;
            while n > 0 {
                a = b;
                b = n;
                n = a % b;
            }
            let answer = str1.split_at(b).0.to_string();

            return answer;
        }
    }
}