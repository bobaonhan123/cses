// https://cses.fi/problemset/task/1662
/*
    
*/

use std::io::{self, BufRead, Write, BufWriter};
// use std::collections::{VecDeque, HashMap, HashSet, BinaryHeap};

macro_rules! input {
    ($(r:tt)*) => {{
        let stdin = io::stdin();
        let mut lines = stdin.lock().lines();
        let mut next = move || -> String {
            lines.next().unwrap().unwrap()
        };
        macro_rules! read { (t:ty) => { next().trim().parse::<t>().unwrap() }; }
        macro_rules! read_vec { (t:ty) => { next().trim().split_whitespace().map(|x| x.parse::<t>().unwrap()).collect::<Vec<_>>() }; }
        $(r)*
    }};
}

fn main() {
    let stdout = io::stdout();
    let mut out = BufWriter::new(stdout.lock());

    input! {
        let n: usize = read!(usize);
        let arr: Vec<i64> = read_vec!(i64);
    }
    let mut prefix_sum = vec![0i64; n];
    prefix_sum[0] = arr[0];
    for i in 1..n {
        prefix_sum[i] = prefix_sum[i-1] + arr[i];
    }
    

    // Example usages:
    // let mut stack: Vec<i32> = Vec::new();
    // let mut queue: VecDeque<i32> = VecDeque::new();
    // let mut map: HashMap<i32, i32> = HashMap::new();
    // let mut set: HashSet<i32> = HashSet::new();
    // let mut heap: BinaryHeap<i32> = BinaryHeap::new();

    writeln!(out, "").unwrap();
}