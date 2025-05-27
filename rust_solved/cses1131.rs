// https://cses.fi/problemset/task/1131
/*
find the first fartest node from any node
find the fartest node from that fartest node
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

fn main() {
    let stdout = io::stdout();
    let mut out = BufWriter::new(stdout.lock());

    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    let mut next = || lines.next().unwrap().unwrap();

    let n: usize = read!(next, usize);
    let mut g = vec![Vec::new(); n];
    for _ in 0..n - 1 {
        let uv = read_vec!(next, usize);
        let u = uv[0] - 1;
        let v = uv[1] - 1;
        g[u].push(v);
        g[v].push(u);
    }
    let mut q: VecDeque<usize> = VecDeque::new();
    q.push_back(0);
    let mut dist = vec![-1; n];
    dist[0] = 0;
    while let Some(u) = q.pop_front() {
        for &v in &g[u as usize] {
            if dist[v] == -1 {
                dist[v] = dist[u as usize] + 1;
                q.push_back(v as usize);
            }
        }
    }
    let (v1, _) = dist.iter().enumerate().max_by_key(|&(_, &d)| d).unwrap();
    let mut q2: VecDeque<usize> = VecDeque::new();
    q2.push_back(v1 as usize);
    let mut dist2 = vec![-1; n];
    dist2[v1] = 0;
    while let Some(u) = q2.pop_front() {
        for &v in &g[u as usize] {
            if dist2[v] == -1 {
                dist2[v] = dist2[u as usize] + 1;
                q2.push_back(v as usize);
            }
        }
    }


    // Example usages:
    // let mut stack: Vec<i32> = Vec::new();
    // let mut queue: VecDeque<i32> = VecDeque::new();
    // let mut map: HashMap<i32, i32> = HashMap::new();
    // let mut set: HashSet<i32> = HashSet::new();
    // let mut heap: BinaryHeap<i32> = BinaryHeap::new();

    writeln!(out, "{}", dist2.iter().max().unwrap()).unwrap();
}