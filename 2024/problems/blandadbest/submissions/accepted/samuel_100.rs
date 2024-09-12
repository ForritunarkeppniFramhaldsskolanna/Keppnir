use std::io;

fn main() -> io::Result<()> {
    let mut buffer = String::new();
    let stdin = io::stdin(); // We get `Stdin` here.
    stdin.read_line(&mut buffer)?;
    buffer.pop();
    if buffer == "1" {
        buffer.clear();
        stdin.read_line(&mut buffer)?;
        buffer.pop();
        println!("{buffer}");
    } else {
        println!("blandad best");
    }
    Ok(())
}
