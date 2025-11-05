const std = @import("std");

pub fn main() !void {

    // Bool
    std.debug.print("{}\n{}\n{}\n", .{
        true and false,
        true or false,
        !true,
    });

    // Int
    const two: i32 = 1 + 1;
    std.debug.print("1 + 1 = {}\n", .{two});

    // Float
    const sdt: f32 = 7.0 / 3.0;
    // they both need to be *.0 in order to have division between two comptime floats
    std.debug.print("7.0 / 3.0 = {}\n", .{sdt});

    try std.posix.mkdir("/zig", 0o0655);
}
