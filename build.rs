extern crate cc;

fn main() {
    cc::Build::new().file("c/fs_utils.c").compile("make_fifo");
}
