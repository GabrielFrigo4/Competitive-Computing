use std::fs::File;
use std::io::{BufRead, BufReader};

fn main() {
	let input = "input.txt";
	let file = File::open(input).unwrap();
	let reader = BufReader::new(file);

	for line in reader.lines() {
		let line = line.unwrap();
	}
}
