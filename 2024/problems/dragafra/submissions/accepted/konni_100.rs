use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Failed to read line");
    let windows: u32 = input.trim().parse().expect("Invalid input");

    input = String::new();
    io::stdin().read_line(&mut input).expect("Failed to read line");
    let curtains: u32 = input.trim().parse().expect("Invalid input");
    println!("{}", windows - curtains);
}
