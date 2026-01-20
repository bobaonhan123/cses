// https://cses.fi/problemset/task/1730

use std::io::{self, BufRead, Write, BufWriter, StdinLock, StdoutLock, Lines};

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

fn solve(lines: &mut Lines<StdinLock>, out: &mut BufWriter<StdoutLock>) {
    let mut next = || lines.next().unwrap().unwrap();

    let n: usize = read!(next, usize);
    let arr: Vec<i32> = read_vec!(next, i32);
    // let (a, b): (i32, i32) = read_tuple!(next, i32, i32);
    let mut xo: i32=0;
    for i in 0..n {
        xo= xo^arr[i];
    }

    let stdout = io::stdout();
    let mut out = BufWriter::new(stdout.lock());
    
    if xo!=0 {
        writeln!(out, "first").unwrap();
    }
    else {
        writeln!(out, "second").unwrap();
    }
}

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    let mut next = || lines.next().unwrap().unwrap();

    let t: usize = read!(next, usize);
    // let arr: Vec<i32> = read_vec!(next, i32);
    // let (a, b): (i32, i32) = read_tuple!(next, i32, i32);


    let stdout = io::stdout();
    let mut out = BufWriter::new(stdout.lock());

    // Your solution logic here
    for _ in 0..t {
        solve(&mut lines, &mut out);
    }

    /// The line `// writeln!(out, "{}", n).unwrap();` is a commented-out line of code in the Rust
    /// program. It is using the `writeln!` macro to write the value of `n` to the output buffer `out`.
    /// However, since `n` is not defined or used in the provided code snippet, this line is currently
    /// not doing anything meaningful and has been commented out.
    // writeln!(out, "{}", n).unwrap();
    out.flush().unwrap();
}