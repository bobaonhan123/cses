// https://cses.fi/problemset/task/1144
/*

*/

use std::io::{self, BufRead, Write, BufWriter};
use std::collections::{VecDeque, HashMap, HashSet, BinaryHeap};

macro_rules! read {
    ($next:expr, $t:ty) => {
        $next().trim().parse::<$t>().unwrap()
    };
}

macro_rules! read_vec {
    ($next:expr, $t:ty) => {
        $next()
            .trim()
            .split_whitespace()
            .map(|x| x.parse::<$t>().unwrap())
            .collect::<Vec<_>>()
    };
}

macro_rules! read_tuple {
    ($next:expr, $($t:ty),+) => {
        {
            let line = $next();
            let mut iter = line.trim().split_whitespace();
            ($(iter.next().unwrap().parse::<$t>().unwrap(),)+)
        }
    };
}

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    let mut next = || lines.next().unwrap().unwrap();

    let n: usize = read!(next, usize);
    // let arr: Vec<i32> = read_vec!(next, i32);
    // let (a, b): (i32, i32) = read_tuple!(next, i32, i32);

    let stdout = io::stdout();
    let mut out = BufWriter::new(stdout.lock());

    // Your solution logic here

    writeln!(out, "{}", n).unwrap();
    out.flush().unwrap();
}