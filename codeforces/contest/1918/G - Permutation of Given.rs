use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let n: usize = input.trim().parse().unwrap();

    if n % 6 == 0 {
        println!("YES");
        print!("2 1 -1 ");
        for _ in 0..n / 6 - 1 {
            print!("1 -1 -2 -1 1 2 ");
        }
        println!("1 -1 -2");
    } else if n % 6 == 1 {
        println!("YES");
        print!("-5 8 1 -3 -4 ");
        for _ in 0..n / 6 - 1 {
            print!("-1 3 4 1 -3 -4 ");
        }
        println!("-2 5");
    } else if n % 6 == 2 {
        println!("YES");
        for _ in 0..n / 6 {
            print!("1 -1 -2 -1 1 2 ");
        }
        println!("1 -1");
    } else if n % 6 == 3 {
        if n == 3 {
            println!("NO");
        } else {
            println!("YES");
            print!("2 1 1 -3 -4 -1 3 ");
            for _ in 0..n / 6 - 1 {
                print!("4 1 -3 -4 -1 3 ");
            }
            println!("3 -2");
        }
    } else if n % 6 == 4 {
        println!("YES");
        for _ in 0..n / 6 {
            print!("1 -1 -2 -1 1 2 ");
        }
        println!("1 -1 1 2");
    } else if n % 6 == 5 {
        if n == 5 {
            println!("NO");
        } else {
            println!("YES");
            print!("-2 1 1 -3 -4 -1 3 ");
            for _ in 0..n / 6 - 1 {
                print!("4 1 -3 -4 -1 3 ");
            }
            println!("2 -1 2 4");
        }
	}
} 
