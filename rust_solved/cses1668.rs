// https://cses.fi/problemset/task/1668
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

fn dfs(g: &Vec<Vec<usize>>, u: usize, color: &mut Vec<usize>, c: usize) -> bool {
    color[u] = c;
    for &v in &g[u] {
        if color[v] == 0 {
            if !dfs(g, v, color, 3 - c) {
                return false;
            }
        } else if color[v] == c {
            return false;
        }
    }
    true
}

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    let mut next = || lines.next().unwrap().unwrap();

    // let n: usize = read!(next, usize);
    let (n,m) = read_tuple!(next,usize,usize);
    let mut g = vec![Vec::new(); n + 1];
    for _ in 0..m {
        let (a, b) = read_tuple!(next, usize, usize);
        g[a].push(b);
        g[b].push(a);
    }
    // let arr: Vec<i32> = read_vec!(next, i32);
    // let (a, b): (i32, i32) = read_tuple!(next, i32, i32);

    let stdout = io::stdout();
    let mut out = BufWriter::new(stdout.lock());
    let mut color = vec![0; n + 1];
    for i in 1..=n {
        if color[i]==0 {
            if !dfs(&g,i,&mut color, 1) {
                writeln!(out, "IMPOSSIBLE").unwrap();
                return
            }
        }
    }
    for i in 1..=n {
        write!(out, "{} ",color[i]).unwrap();
    }
    out.flush().unwrap();
}