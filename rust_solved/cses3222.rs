//https://cses.fi/problemset/task/3222

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

    let stdout = io::stdout();
    let mut out = BufWriter::new(stdout.lock());

    // Your solution logic here
    let mut arr: Vec<usize> = read_vec!(next, usize);
    let mut bmap: BTreeMap<usize, usize> = BTreeMap::new();
    let mut res=0;
    for i in 0..k {
        let count = bmap.get(&arr[i]).cloned().unwrap_or(0);
        if count == 0 {
            res += 1;
        }
        bmap.insert(arr[i], count + 1);
    }
    write!(out, "{} ", res).unwrap();
    for i in 1..=n-k {
        let pr = arr[i - 1];
        let next_elem = arr[i + k - 1];
        let prcnt = bmap.get(&pr).cloned().unwrap_or(0);
        if prcnt == 1 {
            res -= 1;
            bmap.remove(&pr);
        } else {
            bmap.insert(pr, prcnt - 1);
        }
        let necnt = bmap.get(&next_elem).cloned().unwrap_or(0);
        if necnt == 0 {
            res += 1;
        }
        bmap.insert(next_elem, necnt + 1);
        write!(out, "{} ", res).unwrap();
    }

    // writeln!(out, "{}", rres).unwrap();
    out.flush().unwrap();
}