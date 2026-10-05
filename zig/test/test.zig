const std = @import("std");

pub fn main() void {
    const a = 3;
    const b = 4;

    const result = add(a, b);

    std.debug.print("{} + {} = {}\n", .{ a, b, result });
}

fn add(x: i32, y: i32) i32 {
    return x + y;
}
