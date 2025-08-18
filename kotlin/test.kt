fun foo(msg: String) {
	println(msg);
}

fun greet(msg: String, prefix: String = "Hello"){
	println("$prefix $msg");
}

fun bruh(x: Int, y: Int) = x xor y

fun main() {
	println("Hello")
	foo("Huh")
	greet("Adi")
	var num: Int = bruh(1, 2);
	foo(num.toString());
}
