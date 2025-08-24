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

    let n: usize = read!(next, usize);
    // let arr: Vec<i32> = read_vec!(next, i32);
    // let (a, b): (i32, i32) = read_tuple!(next, i32, i32);

    let stdout = io::stdout();
    let mut out = BufWriter::new(stdout.lock());
    let r#mod: usize = 1_000_000_007;
    let s: usize = n * (n + 1) / 2;
    if s % 2 == 1 {
        writeln!(out, "0").unwrap();
        return;
    }
    let t = s / 2;
    let mut dp = vec![0usize; t + 1];
    dp[0] = 1;
    for i in 1..=n {
        for j in (i..=t).rev() {
            dp[j] = (dp[j] + dp[j - i]) % r#mod;
        }
    }
    /*
    Vì đây là các số đã được r#mod, vì vậy dp cuối /2 không thể chia bình thường
    => Nghịch đảo r#modulo
    Chia 2 bằng cách nhân với 2 mũ -1, Mà 2 mũ -1 = 2 mũ (r#mod-2) trong môi trường r#mod r#mod
    công thức nhanh là 2 mũ -1 = (r#mod+1)/2 trong môi trường r#mod r#mod
     */
    let inv = (r#mod+1)/2;

    writeln!(out, "{}", (dp[t]*inv)%r#mod).unwrap();
    out.flush().unwrap();
}