// i32 -> 32 bit signed integer
fn add2(x: i32, y: i32) -> i32 {
    // implicit return. semicolon not needed
    x + y
}

// Void Function
fn _greet(){
    println!("Hello!");
}

fn main(){

    /* INTEGER */

    // immutable
    let x: i32 = 5;
    // x += 1; // Error -> x is immutable
    let y: i32 = 13i32;

    // float
    let f: f64 = 1.5f64;

    let _sum = x + y + 13; // 31

    let mut _mutable = 1;
    _mutable = 4;
    _mutable += 2; // 6

    /* STRING */

    // string literal
    let something: &str = "Something idk bruh";
    println!("{} {}", f, something);

    // heap allocated string
    let s: String = "Hello World".to_string();

    /* String Slice */
    // an immutable view into another string
    // does not contain the contents of a string
    // rather has a pointer to beginning and length of a string buffer
    let s_slice: &str = &s;

    println!("{} = {}", s, s_slice); // both returns the same string

    /* VECTORS | ARRAYS */

    // fixed size array
    let _four_ints: [i32; 4]  = [1,2,3,4];

    // dynamic array / vector
    let mut vector: Vec<i32> = vec![1, 2, 3, 4];
    vector.push(100);

    // Vector Slice
    // An immutable view into the vector / array
    let vec_slice: &[i32] = &vector;

    // Use {:?} to print something debug style
    println!("{:?} = {:?}", vector, vec_slice);

    /* NOTHING */

    let _ = 3;
    let _ = add2(3, 4);
    // the returned value is thrown away
    
    /* TUPLES */

    // fixed size set of values
    // can be of different types
    let x: (i32, &str, f64) = (1, "Something", 3.4);
    println!("{} {} {}", x.0, x.1, x.2);
    // 1 Something 3.4
    
    // Destructuring let
    let (a,b,c) = x;
    println!("{} {} {}", a, b, c);

    /* STRUCT */
    
    struct Point {
        _x: i32,
        _y: i32,
    }

    let _origin: Point = Point { _x: 0, _y: 0 };

    // Struct with unnamed fields = Tuple Struct
    struct _Point2(i32, i32);

    /* BLOCK */

    let block: i32 = 5;
    {
        // blocks have their own scope
        let block: i32 = 7;
        println!("{}", block); // 7
    }
    println!("{}", block); // 5

    // blocks are also expressions
    // they evaluate to a value
    let a: i32 = 42;
    let b: i32 = { 42 };
    println!("{} = {}", a, b);

    let _c: i32 = {
        let x: i32 = 6;
        let y: i32 = 5;
        x + y // tail of the block
    }; // 11

    /* ENUM */

    // Enums are like the ones in C

    enum Direction {
        Down,
        Left,
        Right,
        Up,
    }

    let _up: Direction = Direction::Up;

    enum OptionalI32 {
        AnI32(i32),
        Nothing,
    }

    let _two: OptionalI32 = OptionalI32::AnI32(2);
    let _nothing: OptionalI32 = OptionalI32::Nothing;

    /* GENERICS */

    struct Foo<T> {
        _bar: T,
    }

    let _bruh: Foo<i32> = Foo { _bar: 5 };

    // This is defined at "Option" in the standard library
    // It is used in place of a null pointer
    enum Optional<T> {
        SomeVal(T),
        NoVal,
    }

    /* METHODS */

	// associated functions

    impl<T> Foo<T> {
        // methods take an explicit "self" parameter    
        fn bar(&self) -> &T { // self is borrowed
            &self._bar
        }

        fn bar_mut(&mut self) -> &mut T { // self is mutably borrowed
            &mut self._bar        
        }

        fn into_bar(self) -> T { // here self is consumed
            self._bar
        }
    }

    let a_foo: Foo<i32> = Foo { _bar: 1 };


}
