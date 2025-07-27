use std::fs::OpenOptions;
use std::io::{Seek, SeekFrom, Write};

fn main() {
    let mut fb = OpenOptions::new().write(true).open("/dev/fb0").unwrap();
    let blue: [u8; 4] = [0xFF, 0x00, 0x00, 0x00]; // RGBA maybe
    for _ in 0..(1024*768) {
        fb.write_all(&blue).unwrap();
    }
}
