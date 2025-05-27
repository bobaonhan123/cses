// https://cses.fi/problemset/task/1641
use std::collections::{BinaryHeap, HashMap, HashSet, VecDeque};
use std::io::{self, BufRead, BufWriter, Write};

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

    // let n: i64 = read!(next, i64);
    // let arr: Vec<i32> = read_vec!(next, i32);
    let (n, x): (usize, i64) = read_tuple!(next, usize, i64);
    let arr: Vec<i64> = read_vec!(next, i64);
    let mut a: Vec<(i64, i64)> = arr
        .into_iter()
        .enumerate()
        .map(|(i, v)| (v, i as i64 + 1))
        .collect();
    a.sort_by_key(|&(v, _)| v);

    let stdout = io::stdout();
    let mut out = BufWriter::new(stdout.lock());

    for i in 0..n {
        let target = x - a[i].0;
        let (mut l, mut r) = (i + 1, n - 1);
        while l < r {
            let su2 = a[l].0 + a[r].0;
            if su2 == target {
                writeln!(out, "{} {} {}", a[l].1, a[r].1, a[i].1).unwrap();
                return;
            } else if su2 < target {
                l += 1;
            } else {
                r -= 1;
            }
        }
    }

    writeln!(out, "IMPOSSIBLE").unwrap();
    out.flush().unwrap();
}
