// https://cses.fi/problemset/task/2413

/*
https://codeforces.com/blog/entry/98085
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

const MOD: usize = 1_000_000_007;

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    let mut next = || lines.next().unwrap().unwrap();
    let t: usize = read!(next, usize);
    
    let stdout = io::stdout();
    let mut out = BufWriter::new(stdout.lock());

    let mut dp: Vec<Vec<usize>> = vec![vec![0; 2]; 1_000_000 + 1];
    dp[0][0] = 1;
    dp[0][1] = 0;
    for i in 1..=1_000_000 {
        dp[i][0] = (4 * dp[i-1][0] + dp[i-1][1]) % MOD;
        dp[i][1] = (dp[i-1][0] + 2 * dp[i-1][1]) % MOD;
    }
    for _ in 0..t {
        let n: usize = read!(next, usize);
        writeln!(out, "{}", (dp[n][0]+dp[n][1])%MOD).unwrap();
    }

    out.flush().unwrap();
}