use std::env;
use std::fs::File;
use std::io::{BufRead, BufReader};
use std::collections::HashSet;

#[derive(Eq, Hash, PartialEq)]
enum Symbol {
	Obstacle,
	Free,
	Up,
	Right,
	Down,
	Left,
}

fn char_symbol(c: char) -> Symbol {
	match c {
		'#' => Symbol::Obstacle,
		_ => Symbol::Free
	}
}

fn dir_symbol(d: (isize, isize)) -> Symbol {
	match d {
		(-1, 0) => Symbol::Up,
		(0, 1) => Symbol::Right,
		(1, 0) => Symbol::Down,
		(0, -1) => Symbol::Left,
		_ => Symbol::Free
	}
}

fn next_dir(d: (isize, isize)) -> (isize, isize) {
	match d {
		(-1, 0) => (0, 1),
		(0, 1) => (1, 0),
		(1, 0) => (0, -1),
		(0, -1) => (-1, 0),
		_ => (0, 0)
	}
}

fn prev_dir(d: (isize, isize)) -> (isize, isize) {
	match d {
		(-1, 0) => (0, -1),
		(0, 1) => (-1, 0),
		(1, 0) => (0, 1),
		(0, -1) => (1, 0),
		_ => (0, 0)
	}
}

fn valid_pos(x: isize, y: isize, mat: &Vec::<Vec<HashSet<Symbol>>>) -> bool {
	return !(y < 0 || x < 0 || y >= mat.len() as isize || x >= mat[0].len() as isize);
}

fn backward_spread(mut pos: (isize, isize), mut dir: (isize, isize), mat: &mut Vec::<Vec<HashSet<Symbol>>>) {
	while valid_pos(pos.1 - dir.1, pos.0 - dir.0, &mat) {
		if mat[(pos.0 - dir.0) as usize][(pos.1 - dir.1) as usize].contains(&Symbol::Obstacle) {
			mat[pos.0 as usize][pos.1 as usize].insert(dir_symbol(dir));
			dir = prev_dir(dir);
		}
		else if !mat[(pos.0 - dir.0) as usize][(pos.1 - dir.1) as usize].contains(&dir_symbol(dir)) {
			mat[pos.0 as usize][pos.1 as usize].insert(dir_symbol(dir));
			pos.0 -= dir.0;
			pos.1 -= dir.1;
		}
		else {
			mat[pos.0 as usize][pos.1 as usize].insert(dir_symbol(dir));
			break;
		}
	}
}

fn main() {
	let args = env::args().collect::<Vec<String>>();
	let input = &args[1];

	let file = File::open(input).unwrap();
	let reader = BufReader::new(file);

	let mut pos = (0, 0);
	let mut cdir = (-1, 0);
	let mut ndir = (0, 1);

	let mut mat = Vec::<Vec<HashSet<Symbol>>>::new();
	for (index_y, line) in reader.lines().enumerate() {
		let line = line.unwrap();
		mat.push(line.chars().map(|x| HashSet::<Symbol>::from([char_symbol(x)])).collect::<Vec<HashSet<Symbol>>>());
		for (index_x, char) in line.chars().enumerate() {
			if pos != (0, 0) {
				break;
			}
			if char == '^' {
				pos = (index_y as isize, index_x as isize);
			}
		}
	}

	let mut count = 0;
	backward_spread(pos, cdir, &mut mat);
	while valid_pos(pos.1 + cdir.1, pos.0 + cdir.0, &mat) {
		if !mat[(pos.0 + cdir.0) as usize][(pos.1 + cdir.1) as usize].contains(&Symbol::Obstacle) {
			if mat[pos.0 as usize][pos.1 as usize].contains(&dir_symbol(ndir)) {
				println!("{} {}", pos.1 + cdir.1, pos.0 + cdir.0);
				count += 1;
			}
			mat[pos.0 as usize][pos.1 as usize].insert(dir_symbol(cdir));
			pos.0 += cdir.0;
			pos.1 += cdir.1;
			continue;
		}

		cdir = ndir;
		ndir = next_dir(ndir);

		backward_spread(pos, cdir, &mut mat);
	}
	println!("{}", count);
}
