//https://cses.fi/problemset/task/3426

use std::io::{self, BufRead, Write, BufWriter};
use std::collections::{VecDeque, HashMap, HashSet, BinaryHeap, BTreeMap};
use std::cmp::{max, min};

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

    let (n,k): (usize, usize) = read_tuple!(next, usize, usize);
    // let arr: Vec<i32> = read_vec!(next, i32);
    let (x, a, b,c ): (usize, usize,usize, usize) = read_tuple!(next,usize, usize,usize, usize);

    let stdout = io::stdout();
    let mut out = BufWriter::new(stdout.lock());

    // Your solution logic here
    let mut arr: Vec<usize> = vec![0; n];
    let mut res:usize = 0;
    let mut rres:usize=0;
    arr[0]=x;
    for i in 1..n {
        arr[i] = (a*arr[i-1]+b)%c;
    }
    for i in 0..k {
        res^=arr[i];
    }
    rres=res;
    for i in 1..=n-k {
        res^=arr[i-1];
        res^=arr[i+k-1];
        rres^=res;
    }


    writeln!(out, "{}", rres).unwrap();
    out.flush().unwrap();
}