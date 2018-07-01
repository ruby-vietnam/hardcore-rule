use std::vec::Vec;

enum Direction {
    NORTH,
    WEST,
    SOUTH,
    EAST
}

fn main() {

}

fn opposite(d1: &Direction, d2: &Direction) -> bool {
    use Direction::*;
    match (*d1, *d2) {
        (NORTH, SOUTH) | (SOUTH, NORTH) => true,
        (WEST, EAST) | (EAST, WEST) => true,
        _ => false
    }
}

fn dir_reduc(arr: &[Direction]) -> Vec<Direction> {
    let mut result = arr.to_vec();
    let mut i = (result.len() - 1) as isize;
    while i > 0 {
        if opposite(&result[i as usize], &result[(i - 1) as usize]) {
            result.remove(i as usize);
            result.remove((i - 1) as usize);
        }
        i = i - 1;
        if i as usize >= result.len() { i = (result.len() - 1) as isize }
    }
    result
}
