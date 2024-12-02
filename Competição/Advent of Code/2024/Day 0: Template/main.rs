use std::fs::File;
use std::io::{BufRead, BufReader};

fn main() {
    let input = "input.txt";
    let file = File::open(input).expect("Unable to open file");
    let reader = BufReader::new(file);
    
    for (index, line) in reader.lines().enumerate() {
		let line = line.expect("Unable to read line");
		println!("{}. {}", index + 1, line);
    }
}
