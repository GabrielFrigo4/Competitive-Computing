use std::env;
use std::fs::File;
use std::io::{BufRead, BufReader};

enum State {
	Rules,
	Updates
}

fn main() {
	let args = env::args().collect::<Vec<String>>();
	let input = &args[1];

	let file = File::open(input).unwrap();
	let reader = BufReader::new(file);

	let mut rules = Vec::<(i32, i32)>::new();
	let mut state = State::Rules;
	for line in reader.lines() {
		let line = line.unwrap();
		if line == "" {
			state = State::Updates;
		}

		match state {
			State::Rules => {
				let parts = line.split("|").collect::<Vec<&str>>();
				let min = parts[0].parse::<i32>().unwrap();
				let max = parts[1].parse::<i32>().unwrap();
				rules.push((min, max));
			},
			State::Updates => {

			}
		}
	}
}
