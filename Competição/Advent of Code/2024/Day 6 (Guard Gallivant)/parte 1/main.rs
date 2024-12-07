use std::env;
use std::fs::File;
use std::io::{BufRead, BufReader};

fn main() {
	let args = env::args().collect::<Vec<String>>();
	let input = &args[1];

	let file = File::open(input).unwrap();
	let reader = BufReader::new(file);

	let mut mat = Vec::<Vec<u32>>::new();
	for line in reader.lines() {
		let line = line.unwrap();
		mat.push(line.chars().map(|x| u32::from(x)).collect::<Vec<u32>>());
	}
}
