use std::env;
use std::fs::File;
use std::io::{BufRead, BufReader};

fn main() {
	let args: Vec<String> = env::args().collect();
	let input = &args[1];

	let file = File::open(input).unwrap();
	let reader = BufReader::new(file);

	for line in reader.lines() {
		let line = line.unwrap();
	}
}
