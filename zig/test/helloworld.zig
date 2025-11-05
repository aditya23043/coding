const std = @import("std");
const info = std.log.info;

pub fn main() void {
    // unlike C, zig functions have fixed number of arguments
    info("Hello World", .{});
}
