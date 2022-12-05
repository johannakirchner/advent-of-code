use std::fs::File;
use std::io::{BufRead, BufReader};

struct Round {
    opponent: char,
    shape: char,
}

fn first(x: Round) -> i32 {
    let mut score: i32 = 0;

    if x.shape == 'X' {
        score += 1;
        if x.opponent == 'C' {
            score += 6;
        } else if x.opponent == 'A' {
            score += 3;
        }
    } else if x.shape == 'Y' {
        score += 2;
        if x.opponent == 'A' {
            score += 6;
        } else if x.opponent == 'B' {
            score += 3;
        }
    } else if x.shape == 'Z' {
        score += 3;
        if x.opponent == 'B' {
            score += 6;
        } else if x.opponent == 'C' {
            score += 3;
        }
    }

    return score;
}

fn second(x: Round) -> i32 {
    let mut score: i32 = 0;

    if x.shape == 'X' { // lose
        if x.opponent == 'A' {
            score += 3;
        } else if x.opponent == 'B' {
            score += 1;
        } else if x.opponent == 'C' {
            score += 2;
        }
    } else if x.shape == 'Y' { // draw
        score += 3;
        if x.opponent == 'A' {
            score += 1;
        } else if x.opponent == 'B' {
            score += 2;
        } else if x.opponent == 'C' {
            score += 3;
        }
    } else if x.shape == 'Z' { // win
        score += 6;
        if x.opponent == 'A' {
            score += 2;
        } else if x.opponent == 'B' {
            score += 3;
        } else if x.opponent == 'C' {
            score += 1;
        }
    }

    return score;
}

fn main() {
    let mut score1: i32 = 0;
    let mut score2: i32 = 0;
    let mut rounds: Vec<Round> = Vec::new();

    let f = BufReader::new(File::open("input.txt").expect("open failed"));

    for line in f.lines() {
        let mut r: Vec<char> = Vec::new();

        for c in line.expect("lines failed").chars() {
            if c != ' ' {
                r.push(c);
            }
        }
        let sh;
        let op;

        match r.pop() {
            Some(a) => sh = a,
            None => {
                sh = ' ';
            }
        }
        match r.pop() {
            Some(a) => op = a,
            None => op = ' ',
        }
        rounds.push(Round {
            shape: sh,
            opponent: op,
        });
    }
    

    for r in rounds {
        score1 += first(r);
    }
    
    println!("{}", score1);

    // for r in rounds {
    //     score2 += second(r);
    // }

    // println!("{}", score2);
}

// X / A rock = 1
// Y / B paper = 2
// Z / C scissors = 3

// X LOSE
// Y draw 
// Z win
