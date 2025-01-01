fn mkfifo(name : &str) ->i32 {
    extern "C" {
        fn make_fifo(file_path: *const std::os::raw::c_char) -> i32;
    }
    let c_string = std::ffi::CString::new(name).unwrap();
    unsafe {
        return make_fifo((&c_string).as_ptr());
    }
}

fn main() {
    env_logger::init();
    log::info!("Hello, world!");
    mkfifo("artifacts/test1");
}
