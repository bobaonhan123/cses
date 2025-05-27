// https://cses.fi/problemset/task/1671
/*
    This is a dijkstra problem
*/
use std::io::{self, BufRead, Write, BufWriter};
use std::collections::{VecDeque, HashMap, HashSet, BinaryHeap};
use std::cmp::Reverse;

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
    let ma = 1_000_000_000_000_000_7;

    let (n, m): (usize, usize) = read_tuple!(next, usize, usize);
    let mut graph = vec![Vec::new(); n + 1];
    let mut dist = vec![ma; n + 1];
    dist[0]=0;
    dist[1]=0;
    let mut heap = BinaryHeap::new();

    for i in 0..m {
        let (u, v, w): (usize, usize, usize) = read_tuple!(next, usize, usize, usize);
        graph[u].push((v,w));
    }
    heap.push(Reverse((0, 1)));
    while let Some(Reverse((cost, u))) = heap.pop() {
        if cost > dist[u] {
            continue; // skip if there exist a shorter path
        }
        for &(v, w) in &graph[u] {
            let next = cost + w;            
            if next < dist[v] {
                dist[v] = next;
                heap.push(Reverse((next, v)));
            }
        }
    }

    // let arr: Vec<i32> = read_vec!(next, i32);
    // let (a, b): (i32, i32) = read_tuple!(next, i32, i32);

    let stdout = io::stdout();
    let mut out = BufWriter::new(stdout.lock());

    // Your solution logic here
    for i in 1..=n {
        write!(out, "{} ", &dist[i]).unwrap();
    }
    // writeln!(out, "{}", n).unwrap();
    out.flush().unwrap();
}