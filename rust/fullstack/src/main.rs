use std::io;

fn main() {
    println!("Input: ");

    let mut guess: String = String::new();
    io::stdin()
        .read_line(&mut guess)
        .expect("FAILED TO READ LINE");

    println!("{}", guess);
}

fn something(){
    return;
}
